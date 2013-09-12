#ifndef LOCALEUSAGE_HPP_INCLUDED
#define LOCALEUSAGE_HPP_INCLUDED

#include <iostream>
#include <clocale>
#include <locale>
#include <chrono>
#include <boost/algorithm/string.hpp>
#if defined (_WIN32)
#   include <Windows.h>
#endif
#include "Convert.hpp"
#include "Utility.hpp"

/*
 locale :: "locale_name"
        | "language[_country_region[.code_page]]"
        | ".code_page"
        | "C"
        | ""
        | NULL

 */

void TestLocale()
{
	std::locale loc = std::locale("");
	std::string narrowname(loc.name());
	std::wstring name(narrowname.begin(), narrowname.end());
	/*
		Note:
		std::wstring name(loc.name().begin(), loc.name().end()); // error, as the char has been changed.
	 */
	std::wcout<<L"Native Locale Name:"<<name<<std::endl;

	loc = std::locale();
	narrowname.assign(loc.name());
	name.assign(narrowname.begin(), narrowname.end());
	std::wcout<<L"Default Locale Name:"<<name<<std::endl;

	loc = std::locale("C");
	narrowname.assign(loc.name());
	name.assign(narrowname.begin(), narrowname.end());
	std::wcout<<L"\"C\" Locale Name:"<<name<<std::endl;

	loc = std::locale::classic();
	narrowname.assign(loc.name());
	name.assign(narrowname.begin(), narrowname.end());
	std::wcout<<L"Classic Locale Name:"<<name<<std::endl;
	std::wcout.flush();

	if (std::wcout.bad())
	{
		std::wcout.clear();
		std::wcout.flush();
		std::wcout<<"Reset std::wcout"<<std::endl;
	}
}

void TestUsageSetLocaleInC()
{
	wprintf(L"===%ls===\n", __FUNCTIONW__);
	/*
	If the value of this parameter is NULL, the function
	does not make any changes to the current locale,
	but the name of the current locale is still
	returned by the function.
	Note: Later calls to setlocale overwrite the string,
	which makes string pointers returned by earlier calls
	no longer valid. You can use _strdup to save a copy of
	a specific locale string.

	Note:
	setlocale is usually used in c, affect printf and wprintf
	*/
	struct lconv *lc;
	// use native environment
	char * psz = std::setlocale(LC_ALL, "chs");
	lc = std::localeconv();
	wprintf(L"\tCurrent Locale    : %s\n", Char2WString(psz).data());
	wprintf(L"\tThousand Separator: %s\n", Char2WString(lc->thousands_sep).data());
	wprintf(L"\tGrouping          : %s\n", Char2WString(lc->grouping).data());
	wprintf(L"\tCurrency Symbol   : %s\n", Char2WString(lc->currency_symbol).data());
	wprintf(L"\tNumber 1000000    : %ld\n", 1000000);

	psz = std::setlocale(LC_ALL, "english");
	lc = std::localeconv();
	wprintf(L"\tCurrent Locale    : %s\n", Char2WString(psz).data());
	wprintf(L"\tThousand Separator: %s\n", Char2WString(lc->thousands_sep).data());
	wprintf(L"\tGrouping          : %s\n", Char2WString(lc->grouping).data());
	wprintf(L"\tCurrency Symbol   : %s\n", Char2WString(lc->currency_symbol).data());
	wprintf(L"\tNumber 1000000    : %ld\n", 1000000);

	if (std::wcout.bad())
	{
		std::wcout.clear();
		std::wcout.flush();
		std::wcout<<"Reset std::wcout"<<std::endl;
	}
}

void TestUsageSetLocaleInCPP()
{
	std::wcout<<L"==="<<__FUNCTIONW__<<L"==="<<std::endl;
	/*
	Note:
	use locale object for c++, affect std::cout and std::wcout
	*/
	std::wcout.clear();
	std::wcout.flush();
	std::wcout.imbue(std::locale("eng"));
	std::wcout<<L"\tCurrent Locale    : "<<String2WString(std::wcout.getloc().name())<<std::endl;
	std::wcout<<L"\tThousand Separator: "<<std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).thousands_sep()<<std::endl;
	std::wcout<<L"\tGrouping          : "<<String2WString(std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).grouping())<<std::endl;
	std::wcout<<L"\tCurrency Symbol   : "<<std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).curr_symbol()<<std::endl;
	std::wcout<<L"\tNumber 1000000    : "<<1000000<<std::endl;
	std::wcout.flush();

	std::wcout.imbue(std::locale("C"));
	std::wcout<<L"\tCurrent Locale    : "<<String2WString(std::wcout.getloc().name())<<std::endl;
	std::wcout<<L"\tThousand Separator: "<<std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).thousands_sep()<<std::endl;
	std::wcout<<L"\tGrouping          : "<<String2WString(std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).grouping())<<std::endl;
	std::wcout<<L"\tCurrency Symbol   : "<<std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).curr_symbol()<<std::endl;
	std::wcout<<L"\tNumber 1000000    : "<<1000000<<std::endl;
	std::wcout.flush();
#if defined (_WIN32)
	std::wcout.imbue(std::locale("deu_deu.1252"));
#else
	std::wcout.imbue(std::locale("de_DE"));
#endif
	std::wcout<<L"\tCurrent Locale    : "<<String2WString(std::wcout.getloc().name())<<std::endl;
	std::wcout<<L"\tThousand Separator: "<<std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).thousands_sep()<<std::endl;
	std::wcout<<L"\tGrouping          : "<<String2WString(std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).grouping())<<std::endl;
	std::wcout<<L"\tCurrency Symbol   : "<<std::use_facet<std::moneypunct<wchar_t> >(std::wcout.getloc()).curr_symbol()<<std::endl;
	std::wcout<<L"\tNumber 1000000    : "<<1000000<<std::endl;
	std::wcout.flush();

	if (std::wcout.bad())
	{
		std::wcout.clear();
		std::wcout.flush();
		std::wcout<<"Reset std::wcout"<<std::endl;
	}
}

void TestNSIAPIUsage()
{
	/*
		National Language Support (NLS) API Reference
		MSDN: http://msdn.microsoft.com/en-us/goglobal/bb896001.aspx
	*/

}
/*
%a Abbreviated weekday name * Thu
%A Full weekday name *  Thursday
%b Abbreviated month name * Aug
%B Full month name * August
%c Date and time representation * Thu Aug 23 14:55:02 2001
%C Year divided by 100 and truncated to integer (00-99) 20
%d Day of the month, zero-padded (01-31) 23
%D Short MM/DD/YY date, equivalent to %m/%d/%y 08/23/01
%e Day of the month, space-padded ( 1-31) 23
%F Short YYYY-MM-DD date, equivalent to %Y-%m-%d 2001-08-23
%g Week-based year, last two digits (00-99) 01
%G Week-based year 2001
%h Abbreviated month name * (same as %b) Aug
%H Hour in 24h format (00-23) 14
%I Hour in 12h format (01-12) 02
%j Day of the year (001-366) 235
%m Month as a decimal number (01-12) 08
%M Minute (00-59) 55
%n New-line character ('\n')
%p AM or PM designation PM
%r 12-hour clock time * 02:55:02 pm
%R 24-hour HH:MM time, equivalent to %H:%M 14:55
%S Second (00-61) 02
%t Horizontal-tab character ('\t')
%T ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S 14:55:02
%u ISO 8601 weekday as number with Monday as 1 (1-7) 4
%U Week number with the first Sunday as the first day of week one (00-53) 33
%V ISO 8601 week number (00-53) 34
%w Weekday as a decimal number with Sunday as 0 (0-6) 4
%W Week number with the first Monday as the first day of week one (00-53) 34
%x Date representation * 08/23/01
%X Time representation * 14:55:02
%y Year, last two digits (00-99) 01
%Y Year 2001
%z ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100)
 If timezone cannot be termined, no characters +100
%Z Timezone name or abbreviation *
 If timezone cannot be termined, no characters CDT
%% A % sign %
*/
void TestTimePut()
{

	auto now = std::chrono::system_clock::now();
	auto t = std::chrono::system_clock::to_time_t(now);
	std::wcout<<L"Local Time:"<<std::endl;
	auto ptm = std::localtime(&t);
#if defined _WIN32
	/* Windows dosen't support the time zone */
	const std::wstring FMT(L"%Y-%m-%d %H:%M:%S %A\n");
#else
	const std::wstring FMT(L"%Y-%m-%d %H:%M:%S %A %Z\n");
#endif
	//const std::time_put<char>& ctp = std::use_facet<std::time_put<char> >(std::locale("C"));
	//const std::time_put<char>& dtp = std::use_facet<std::time_put<char> >(std::locale());
	//const std::time_put<char>& ntp = std::use_facet<std::time_put<char> >(std::locale(""));
	//ctp.put(std::wcout, std::wcout, '0', ptm, FMT.data(), FMT.data() + FMT.length());
	//dtp.put(std::wcout, std::wcout, '0', ptm, FMT.data(), FMT.data() + FMT.length());
	//ntp.put(std::wcout, std::wcout, '0', ptm, FMT.data(), FMT.data() + FMT.length());


	std::locale curlocale = std::wcout.getloc();

	try
	{
		std::wcout<<L"C Locale:";
		std::use_facet<std::time_put<wchar_t> >(std::locale("C")).put(std::wcout, std::wcout, L'0', ptm, FMT.data(), FMT.data() + FMT.length());

		std::wcout<<L"Default Locale:";
		std::use_facet<std::time_put<wchar_t> >(std::locale()).put(std::wcout, std::wcout, L'0', ptm, FMT.data(), FMT.data() + FMT.length());

		std::wcout<<L"Native Locale:";
		std::use_facet<std::time_put<wchar_t> >(std::locale("")).put(std::wcout, std::wcout, L'0', ptm, FMT.data(), FMT.data() + FMT.length());

		if (std::wcout.bad())
		{
			std::wcout.clear();
			std::wcout.flush();
			std::wcout<<"Reset std::wcout"<<std::endl;
		}
	}
	catch (...)
	{
		std::wcerr<<std::strerror(errno)<<std::endl;
	}

	std::wcout.imbue(curlocale);
}

void TestNarrowAndWide()
{
	std::wcout<<L"==="<<__FUNCTIONW__<<L"==="<<std::endl;
	try
	{
		std::wcout.imbue(std::locale(""));
		std::wstring wstr = L"1你好 世界";
		std::wcout<<wstr<<std::endl;
		std::wcout<<L"2你好 世界"<<std::endl; // failed to print
		printf("%s\n", "3你好 世界");
		if (std::setlocale(LC_ALL, "chs"))
		{
			wprintf(L"%s\n", L"4你好 世界");
		}
		std::cout<<"Hello World"<<std::endl;
	}
	catch (const std::exception& exp)
	{
		std::cerr<<exp.what()<<std::endl;
	}
	std::wcout.flush();
	std::wcout.imbue(std::locale(""));
}

void TestLocaleUsage()
{
    //TestUsageSetLocaleInC();
    TestUsageSetLocaleInCPP();
    //TestNSIAPIUsage();
    //TestLocale();
    //TestTimePut();
    TestNarrowAndWide();
}

#endif

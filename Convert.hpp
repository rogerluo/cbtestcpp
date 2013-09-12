#ifndef CONVERT_HPP_INCLUDED
#define CONVERT_HPP_INCLUDED

#include <string>
// declare
std::wstring Char2WString(const char * psz);
std::wstring String2WString(const std::string& in);

// definition
std::wstring Char2WString(const char * psz)
{
	static std::string tmp;
	tmp.assign(psz);
	return String2WString(tmp);
}

std::wstring String2WString(const std::string& in)
{
	std::wstring out(in.begin(), in.end());
	return out;
}

#endif
#include <iostream>
//#include <thread>
#include <memory>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <iomanip>
#include <locale>
#include <tchar.h>
using namespace std;
#include "C11NewFeatures.hpp"
#include "CppMacro.hpp"
#include "CharacterEncodingConversion.hpp"
#include "LocaleUsage.hpp"

void thFun(int &i)
{
	cout<<L"Hi from worker "<<i<<L"!\n";
}
//void Init(vector<thread> &workers)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		//auto th = std::thread(&thFun, std::ref(i));
//		auto th = std::thread(&thFun, std::ref(i));
//		workers.push_back(std::move(th));
//		assert(!th.joinable());
//	}
//}
template <typename T>
class First
{
public:
    First(){cout<<__FUNCTIONW__<<endl;}
    void Foo(void);
};
template <typename T>
void First<T>::Foo(void)
{
    cout<<__FUNCTIONW__<<endl;
}
template <>
void First<int>::Foo(void)
{
    cout<<L"Using Int"<<endl;
}
template <typename T1, typename T2>
class TwoType
{
public:
    TwoType(){cout<<__func__<<endl;}
    void Foo(void);
};
template <typename T1, typename T2>
void TwoType<T1, T2>::Foo(void)
{
#if defined (__GNUC__) || defined (__GNUG__)
    cout<<__PRETTY_FUNCTION__<<endl;
#else
	cout<<__FUNCDNAME__<<endl;
#endif
}
template <>
void TwoType<double, int>::Foo(void)
{
#if defined (__GNUC__) || defined (__GNUG__)
    cout<<L"Using double and int:"<<__PRETTY_FUNCTION__<<endl;
#else
	cout<<L"Using double and int:"<<__FUNCDNAME__<<endl;
#endif
}

class Base
{
public:
    virtual Base* Foo(void){cout<<__FUNCTIONW__<<endl; return this;}
};
class Concrete : public Base
{
public:
    virtual Concrete* Foo(void) {cout<<__FUNCTIONW__<<endl;return this;}
};

template<typename charT>
struct ThousandSeparator : public std::numpunct<charT>
{
public:
    ThousandSeparator(charT sep = _T(',')) : _sep(sep){
    }
protected:
    charT do_thousands_sep() const {
        return _sep;
    }
    std::string do_grouping() const {
        return "\3";
    }
private:
    charT               _sep;
};

void CheckSeparator()
{
    std::locale dotsep(std::locale(), new ThousandSeparator<char>('.'));
    std::locale commasep(std::locale(), new ThousandSeparator<char>);
    std::wcout.imbue(dotsep);
    std::wcout<<1000000<<std::endl;
    std::wcout.imbue(commasep);
    std::wcout<<1000000<<std::endl;
    std::wcout.imbue(std::locale());
    std::wcout<<1000000<<std::endl;
}

void CheckCharConversion()
{
    // upper all characters
    std::wstring str(L"hello world");
    std::wcout<<L"Before:"<<str<<std::endl;
    for (wchar_t& c : str) c = std::use_facet<std::ctype<wchar_t>>(std::wcout.getloc()).toupper(c);
    std::wcout<<L"After :"<<str<<std::endl;
}


int main()
{
    //CheckSeparator();
    //CheckCharConversion();

    //TestC11NewFeatures();
    //TestCppMacro();
    //TestCharEncodingMain();
	TestLocaleUsage();
	return 0;
}

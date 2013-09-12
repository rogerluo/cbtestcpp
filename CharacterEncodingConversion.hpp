#ifndef CHARACTERENCODINGCONVERSION_HPP_INCLUDED
#define CHARACTERENCODINGCONVERSION_HPP_INCLUDED

#include <iostream>
#include <string>
#include <locale>

#include "CppMacro.hpp"
#if defined _STL_CODECVT_SUPPORT
#include <codecvt>
#endif

std::wstring utf8_to_wstring (const std::string& str)
{
#if defined _STL_CODECVT_SUPPORT
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
#endif
    return std::wstring(L"");
}

void TestCharEncodingMain()
{

}

#endif // CHARACTERENCODINGCONVERSION_HPP_INCLUDED

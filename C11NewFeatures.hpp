#ifndef C11NEWFEATURES_HPP_INCLUDED
#define C11NEWFEATURES_HPP_INCLUDED

#include <string>
#include <locale>
#include <iostream>
#include <boost/assign/std.hpp>
#include "Utility.hpp"


void TestNewIteratorMethod()
{
    using namespace boost::assign;
    std::vector<std::wstring> strs;
    strs+=L"hello",L"world";

    for(std::wstring& str : strs)
        for (wchar_t& c : str)
            c = std::use_facet<std::ctype<wchar_t>>(std::wcout.getloc()).toupper(c);

    for (auto& str : strs) std::wcout<<str<<L" ";
    std::wcout<<std::endl;
}

void TestC11NewFeatures()
{
    std::wcout<<__FUNCTIONW__<<std::endl;
    TestNewIteratorMethod();
}

#endif // C11NEWFEATURES_HPP_INCLUDED

#ifndef CPPMACRO_HPP_INCLUDED
#define CPPMACRO_HPP_INCLUDED

#include "Utility.hpp"
#include <iostream>

#if defined (_WIN32) || defined (_WIN64) && (!defined (__MINGW32__) || !defined (__MINGW64__))
/* Windows. ------------------------------------------------- */
/* CXX11 New Feature */
#	if _MSC_VER >= 1700
#	define _STL_CODECVT_SUPPORT
#	define _STL_THREAD_SUPPORT
#	endif

#	define ISMSVC11()	(_MSC_VER >= 1700)
//#	define ISMSVC10()	(_MSC_VER >= 1600 && _MSC_VER < 1700)
//#	define ISMSVC9()	(_MSC_VER >= 1500 && _MSC_VER < 1600)
//bool IsMSVC11() {return ISMSVC11();}
//bool IsMSVC10() {return ISMSVC10();}
//bool IsMSVC9() {return ISMSVC9();}
#elif defined (_AIX)
/* IBM AIX. ------------------------------------------------- */
#elif defined(__hpux)
/* Hewlett-Packard HP-UX. ----------------------------------- */
#elif defined (__unix__)
/* DragonFly BSD, FreeBSD, OpenBSD, NetBSD------------------- */
#elif defined (__linux__)
/* Centos, Debian, Fedora, OpenSUSE, RedHat, Ubuntu. -------- */
#elif defined (__APPLE__) || defined (__MACH__)
/* OSX, iOS, Darwin. ---------------------------------------- */
#elif defined(__sun) && defined(__SVR4)
/* Oracle Solaris, Open Indiana. ---------------------------- */
#elif defined(__CYGWIN__) && !defined(_WIN32)
/* Cygwin POSIX under Microsoft Windows. -------------------- */
#elif defined(__MINGW32__) || defined (__MINGW64__) && !defined(_WIN32)
/* MinGW GNU under Microsoft Windows. ----------------------- */
#endif

/*
 * _WIN32 signifies that the Win32 API is available.
   It does not tell you which compiler you are using,
   in fact _WIN32 is defined both when using Cygwin's GCC
   and MinGW's GCC. So, do not use _WIN32 to figure out
   if you're being compiled with Visual Studio.

   _MSC_VER tells you that you the the program is
   being compiled with Microsoft Visual C/C++. Well,
   almost. _MSC_VER is also defined when using
   Intel's C++ compiler which is intended to be a drop-in
   replacement for Visual C++.

   for more details about marcro defined,
   refer to: http://nadeausoftware.com/articles/c_c
 */
void TestOperatorSystem()
{
    std::wcout<<L"Detected Operator System:";

#if defined (_WIN32) || defined (_WIN64)
/* Windows. ------------------------------------------------- */
	std::wcout<<L"Windows OS"<<std::endl;
#elif defined (_AIX)
/* IBM AIX. ------------------------------------------------- */
#elif defined(__hpux)
/* Hewlett-Packard HP-UX. ----------------------------------- */
#elif defined (__unix__)
/* DragonFly BSD, FreeBSD, OpenBSD, NetBSD------------------- */
#elif defined (__linux__)
/* Centos, Debian, Fedora, OpenSUSE, RedHat, Ubuntu. -------- */
#elif defined (__APPLE__) || defined (__MACH__)
/* OSX, iOS, Darwin. ---------------------------------------- */
#elif defined(__sun) && defined(__SVR4)
/* Oracle Solaris, Open Indiana. ---------------------------- */
#elif defined(__CYGWIN__) && !defined(_WIN32)
/* Cygwin POSIX under Microsoft Windows. -------------------- */
#elif defined(__MINGW32__) || defined (__MINGW64__) && !defined(_WIN32)
/* MinGW GNU under Microsoft Windows. ----------------------- */
	std::wcout<<L"MinGW under Windows OS"<<std::endl;
#endif
}

void TestProcessor()
{
    std::wcout<<L"Dectect Processor:";
#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64) || defined(__IA64__)
	/* Itanium -------------------------------------------------- */
    std::wcout<<L"Itanium"<<std::endl;
#endif
#if defined(__x86_64__) || defined(_M_X64)
	/* x86 64-bit ----------------------------------------------- */
    std::wcout<<L"x86-64 bit"<<std::endl;
#elif defined(__i386) || defined(_M_IX86)
	/* x86 32-bit ----------------------------------------------- */
    std::wcout<<L"x86 32-bit"<<std::endl;
#endif
}

void TestCompilerNameAndVersion()
{
    std::wcout<<L"Detected Compiler:";
#if defined(__clang__)
	/* Clang/LLVM. ---------------------------------------------- */
    std::wcout<<L"Clang/LLVM"<<std::end;
#elif defined(__ICC) || defined(__INTEL_COMPILER)
	/* Intel ICC/ICPC. ------------------------------------------ */
    std::wcout<<L"Intel ICC/ICPC"<<std::endl;
#elif (defined(__GNUC__) || defined(__GNUG__)) && !(defined(__clang__) || defined(__INTEL_COMPILER))
	/* GNU GCC/G++. ---------------------------------------------
       Clang/LLVM and Intel compilers define __GNUC__ and __GNUG__ to indicate compatibility
	*/
	std::wcout<<L"GNU GCC/G++"<<std::endl;
#elif defined(__HP_cc) || defined(__HP_aCC)
	/* Hewlett-Packard C/aC++. ---------------------------------- */
    std::wcout<<L"HP"<<std::endl;
#elif defined(__IBMC__) || defined(__IBMCPP__)
	/* IBM XL C/C++. -------------------------------------------- */
    std::wcout<<L"IBMC"<<std::endl;
#elif defined(_MSC_VER)
	/* Microsoft Visual Studio. --------------------------------- */
    std::wcout<<L"MSVC"<<std::endl;
	std::wcout<<L"_MSC_VER:"<<_MSC_VER<<std::endl;
	std::wcout<<L"_MSC_BUILD:"<<_MSC_BUILD<<std::endl;
	std::wcout<<L"_MSC_FULL_VER:"<<_MSC_FULL_VER<<std::endl;
#elif defined(__PGI)
	/* Portland Group PGCC/PGCPP. ------------------------------- */
    std::wcout<<L"PGI"<<std::endl;
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
	/* Oracle Solaris Studio. ----------------------------------- */
    std::wcout<<L"Oracle/Solaris"<<std::endl;
#endif
}

void TestFunMacro()
{
	std::wcout<<L"__FUNCTIONW__:"<<__FUNCTIONW__<<std::endl;
#if defined (__GNUC__) || defined (__GNUG__)
	std::wcout<<L"Macro for GNUC:"<<std::endl;
	std::wcout<<L"__func__:"<<__func__<<std::endl;
    std::wcout<<L"__PRETTY_FUNCTION__:"<<__PRETTY_FUNCTION__<<std::endl;
#else
	std::wcout<<L"Macro for MSVC:"<<std::endl;
	std::wcout<<L"__FUNCDNAME__:"<<__FUNCDNAME__<<std::endl;
	std::wcout<<L"__FUNCSIG__:"<<__FUNCSIG__<<std::endl;
#endif
}

void TestCppMacro()
{
    TestProcessor();
    TestOperatorSystem();
    TestCompilerNameAndVersion();
    TestFunMacro();
}


#endif // CPPMACRO_HPP_INCLUDED

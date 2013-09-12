#ifndef UTILITY_HPP_INCLUDED
#define UTILITY_HPP_INCLUDED

/*
 Function Name
 Windows:
    support: __FUNCTION__, __FUNCTIONW__, __
 GNU:
    support: __FUNCTION__, __func__, __PRETTY_FUNCTION__
    __FUNCTION__ is another name for __func__. Older versions of GCC recognize only this
    name. However, it is not standardized. For maximum portability, we recommend you use
    __func__, but provide a fallback definition with the preprocessor
 */

#if defined (__GNUC__) || defined (__GNUG__)
#   if __STDC_VERSION__ < 199901L
#       if __GNUC__ >= 2
#           define __func__ __FUNCTION__
#       else
#           define __func__ "<unknown>"
#       endif
#   endif
#   define __FUNCTIONW__ __func__
#endif

#endif // UTILITY_HPP_INCLUDED

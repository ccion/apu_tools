/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _EWL_MATH_APEX_H
#define _EWL_MATH_APEX_H

#ifndef _EWL_CMATH
#error This header may only be included from <cmath>
#endif

#define __SET_ERRNO__
#ifdef __SET_ERRNO__
	#include <cerrno>
#endif

#if _USE_AEABI_PRIVATE_
#define PREFIX(s) __FSL ## s
#else
#define PREFIX(s) s
#endif

#ifndef _EWL_USE_INLINE
	#define _EWL_USE_INLINE 0
#endif

_EWL_BEGIN_NAMESPACE_STD
_EWL_BEGIN_EXTERN_C

_EWL_END_EXTERN_C
_EWL_END_NAMESPACE_STD

#endif /* _EWL_MATH_APEX_H */

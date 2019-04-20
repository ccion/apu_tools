/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _EWL_STDARG_APEX_H
#define _EWL_STDARG_APEX_H

_EWL_BEGIN_EXTERN_C

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)		__builtin_va_end(v)
#define va_arg(v,l)		__builtin_va_arg(v,l)
#define __va_copy(d,s)	__builtin_va_copy(d,s)

#if _EWL_C99
	#define va_copy(dest, src)		__builtin_va_copy(d,s)
#endif

_EWL_END_EXTERN_C

#endif /* _EWL_STDARG_APEX_H */

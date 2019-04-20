/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef __ansi_prefix__
#define __ansi_prefix__

#include <os_enum.h>

#define __dest_os __apex_bare

#define _USE_AEABI_PRIVATE_  1

/*********************************************/
/*     OS Specific Configuration Flags       */
/*********************************************/

/* Console IO Support Configuration Flags */

#ifndef _EWL_CONSOLE_SUPPORT
	#define _EWL_CONSOLE_SUPPORT	1
#endif

#ifndef _EWL_BUFFERED_CONSOLE
#define _EWL_BUFFERED_CONSOLE			1
#endif


#ifndef TMP_MAX
	#define TMP_MAX						32767
#endif

#if !defined(__STDC_WANT_LIB_EXT1__)
#define __STDC_WANT_LIB_EXT1__				1
#endif

#define _EWL_C99_MATH_LEAK					1

/* File IO Support Configuration Flags */

#ifndef _EWL_OS_DISK_FILE_SUPPORT
	#define _EWL_OS_DISK_FILE_SUPPORT		1
#endif

/* Time Support Configuration Flags */

#ifndef _EWL_OS_TIME_SUPPORT
	#define _EWL_OS_TIME_SUPPORT	0
#endif

#ifndef _EWL_CLOCK_T_AVAILABLE
	#define _EWL_CLOCK_T_AVAILABLE	0
#endif

#ifndef _EWL_TIME_T_AVAILABLE
	#define _EWL_TIME_T_AVAILABLE	0
#endif

#if _EWL_OS_TIME_SUPPORT && ((!_EWL_CLOCK_T_AVAILABLE)  || (!_EWL_TIME_T_AVAILABLE))
	#error _EWL_CLOCK_T_AVAILABLE and _EWL_CLOCK_T_AVAILABLE must match _EWL_OS_TIME_SUPPORT
#endif

/* Thread Safety Configuration Flags */

#ifndef _EWL_THREADSAFE
	#define _EWL_THREADSAFE 0
#endif

#ifndef _EWL_PTHREADS
	#define _EWL_PTHREADS 0
#endif

#if _EWL_PTHREADS && !_EWL_THREADSAFE
	#error _EWL_PTHREADS and _EWL_THREADSAFE must match
#endif

#ifndef _EWL_LOCALDATA_AVAILABLE
	#define _EWL_LOCALDATA_AVAILABLE 0
#endif

/* Memory Allocation Flags */

/*  See alloc.c for more details on configuration options */

#ifndef _EWL_OS_ALLOC_SUPPORT
	#define _EWL_OS_ALLOC_SUPPORT 		0
#endif

#ifndef _EWL_HEAP_EXTERN_PROTOTYPES
	#define _EWL_HEAP_EXTERN_PROTOTYPES \
		extern char_t __heap_addr[]; \
		extern char_t __heap_size[];
#endif

#ifndef _EWL_HEAP_START
	#define _EWL_HEAP_START __heap_addr
#endif

#ifndef _EWL_HEAP_SIZE
	#define _EWL_HEAP_SIZE __heap_size
#endif

/********************************************/
/*      Additional Portability Flags        */
/********************************************/

#ifndef _EWL_USE_INLINE
	#define _EWL_USE_INLINE 0
#endif

#ifndef _EWL_COMPLEX_SUPPORT
	#define _EWL_COMPLEX_SUPPORT 0
#endif

#ifndef _EWL_LONGLONG
	#define _EWL_LONGLONG 1
#endif

#ifndef _EWL_FLOATING_POINT
	#define _EWL_FLOATING_POINT 1
#endif

#ifndef _EWL_WIDE_CHAR
	#define _EWL_WIDE_CHAR 0
#endif

#ifndef _EWL_USES_SUN_MATH_LIB
	#define _EWL_USES_SUN_MATH_LIB 		1
	#define _EWL_USES_SUN_SP_MATH_LIB 	1
	#ifndef _EWL_USES_SUN_DP_MATH_LIB
	#define _EWL_USES_SUN_DP_MATH_LIB 	1
	#endif
#endif

#ifndef _EWL_POSIX
	#define _EWL_POSIX 0
#endif

#ifndef _EWL_NEEDS_EXTRAS
	#define _EWL_NEEDS_EXTRAS 0
#endif

#define _EWL_BF_ORDER

#ifndef _EWL_IEC_559_ADDITIONS
	#define _EWL_IEC_559_ADDITIONS			1
#endif

/***************************/
/*  Flags for C11 Support  */
/***************************/

#ifndef _EWL_C11
#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define _EWL_C11    1
#else
    #define _EWL_C11    0
#endif /* __STDC_xx */
#endif

#ifdef _EWL_C11
#if defined(__llvm__)

/* Versions of DECIMAL_DIG for each floating-point type */
#define EWL_FLT_DECIMAL_DIG    __FLT_DECIMAL_DIG__
#define EWL_DBL_DECIMAL_DIG    __DBL_DECIMAL_DIG__
#define EWL_LDBL_DECIMAL_DIG   __DECIMAL_DIG__

/* Whether types support subnormal numbers */
#define EWL_FLT_HAS_SUBNORM    __FLT_HAS_DENORM__
#define EWL_DBL_HAS_SUBNORM    __DBL_HAS_DENORM__
#define EWL_LDBL_HAS_SUBNORM   __LDBL_HAS_DENORM__

#else
  #error unsupported macros for C11 spec in <ansi_prefix.APEX.h>
#endif /* __llvm__ */

#define _EWL_UNICODE_CHAR        1
#define _EWL_MAX_ALIGN_T_TYPE    long double

#endif /* _EWL_C11 */

/************************************************/
/*     Flags to reduce code and data size       */
/************************************************/

#ifndef _EMBEDDED_WARRIOR_CTYPE
#define _EMBEDDED_WARRIOR_CTYPE 			1
#endif

#ifndef _EWL_STRERROR_KNOWS_ERROR_NAMES
	#define _EWL_STRERROR_KNOWS_ERROR_NAMES 0
#endif

#ifndef _EWL_ASSERT_DISPLAYS_FUNC
	#define _EWL_ASSERT_DISPLAYS_FUNC	0
#endif

#ifndef _EMBEDDED_WARRIOR_HAS_NO_LOCALE
	#define _EMBEDDED_WARRIOR_HAS_NO_LOCALE	1
#endif

#ifndef _EWL_C_LOCALE_ONLY
	#define _EWL_C_LOCALE_ONLY	1
#endif

#ifndef _EMBEDDED_WARRIOR_MALLOC
	#define _EMBEDDED_WARRIOR_MALLOC		1	/* 1: for reduced code and data size by reducing EWL functionality */
#endif

#ifndef _EWL_C99
	#define _EWL_C99	1
#endif

#ifndef _EWL_ACCURATE_BUT_LARGE_ANSI_FP
    #define _EWL_ACCURATE_BUT_LARGE_ANSI_FP	0
#endif

#ifndef __EWL_ROUND_DECIMAL_ANSI_FP__
	#define __EWL_ROUND_DECIMAL_ANSI_FP__ 	1
#endif

#if !_EWL_C99 && !_EWL_C_LOCALE_ONLY && !_EMBEDDED_WARRIOR_HAS_NO_LOCALE
	#error _EWL_C_LOCALE_ONLY must be turned on if _EWL_C99 is off
#endif

#ifndef _EWL_FLOATING_POINT_IO
	#define _EWL_FLOATING_POINT_IO	0
#endif

#ifndef _EWL_C_HAS_CPP_EXTENSIONS
	#define _EWL_C_HAS_CPP_EXTENSIONS 		1
#endif

#ifndef _EWL_C99_PRINTF_SCANF
	#define _EWL_C99_PRINTF_SCANF 			0
#endif

#ifndef _EWL_FLOATING_POINT_PRINTF_SCANF
	#define _EWL_FLOATING_POINT_PRINTF_SCANF			0	/* 0: for reduced code and data size by reducing EWL functionality */
#endif

#define _EWL_C99_MATH_LEAK					1

#ifndef _EWL_USES_EXIT_PROCESS
	#define _EWL_USES_EXIT_PROCESS 1
#endif

#ifndef _EWL_FLT_EVAL_METHOD
	#define _EWL_FLT_EVAL_METHOD  0
#endif

#define _EWL_FLOAT_HEX 						0

#if defined(__cplusplus)
    #define _EWL_USING_NAMESPACE
#endif

#define __ANSI_OVERLOAD__

#define _EWL_INTEGRAL_MATH

#define _EWL_DOUBLE_SIZE 					64

#if _EWL_C99 || _EWL_USES_SUN_MATH_LIB
	#ifndef NAN
		#define NAN (__builtin_nanf(""))
	#endif
#endif

#ifndef __STDC_LIMIT_MACROS
	#define __STDC_LIMIT_MACROS
#endif

#endif /*	__ansi_prefix__	  */

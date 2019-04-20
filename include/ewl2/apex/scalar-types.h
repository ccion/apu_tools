/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_SCALAR_TYPES_H
#define _APEX_SCALAR_TYPES_H


#ifndef __OPENCL_C_VERSION__

#include <stdint.h>
#include <stdbool.h>

#endif


// Scalar types
typedef signed char         int08s;
typedef unsigned char       int08u;

typedef signed short        int16s;
typedef unsigned short      int16u;

typedef signed int          int32s;
typedef unsigned int        int32u;

#ifdef __OPENCL_C_VERSION__

typedef signed long         int64s;
typedef unsigned long       int64u;

#else

typedef signed long long    int64s;
typedef unsigned long long  int64u;

#endif /* __OPENCL_C_VERSION__ */

#endif

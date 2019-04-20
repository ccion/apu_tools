/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_VECTOR_TYPES_H
#define _APEX_VECTOR_TYPES_H

#include <apex/scalar-types.h>

#ifndef APU_VSIZE
#define APU_VSIZE 32
#endif

// Vector types
typedef bool      __vbool   __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vbool   vbool     __attribute__((aligned(1))); 

typedef int08s    __vec08s  __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vec08s  vec08s    __attribute__((aligned(1))); 
typedef int08u    __vec08u  __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vec08u  vec08u    __attribute__((aligned(1))); 

typedef int16s    __vec16s  __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vec16s  vec16s    __attribute__((aligned(2))); 
typedef int16u    __vec16u  __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vec16u  vec16u    __attribute__((aligned(2))); 

typedef int32s    __vec32s  __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vec32s  vec32s    __attribute__((aligned(4))); 
typedef int32u    __vec32u  __attribute__((ext_vector_type(APU_VSIZE)));
typedef __vec32u  vec32u    __attribute__((aligned(4))); 

#endif

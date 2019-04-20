/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_SUPPORT_H
#define _APEX_SUPPORT_H


// Decide how to handle the "static" keyword.

#ifdef __OPENCL_C_VERSION__
  #if __clang__
    /* temporarily enable "static" and other storage class specifiers in OpenCL */
    #define _STATIC static
    #pragma OPENCL EXTENSION cl_clang_storage_class_specifiers : enable
  #else
    /* "static" is an illegal specifier in OpenCL, so eliminate it */
    #define _STATIC
  #endif /* __clang__ */
#else
  /* keep the "static" */
  #define _STATIC static
#endif


#include <apex/scalar-types.h>
#include <apex/vector-types.h>
#include <apex/chess_compatibility.h>
#include <apex/intrinsics.hpp>
#include <apex/vec32-ctor.h>
#include <apex/vif.h>
#include <apex/runtime-info.h>



// clean up some of our temporary preprocessor macros

#ifdef __OPENCL_C_VERSION__
  #if __clang__
    #pragma OPENCL EXTENSION cl_clang_storage_class_specifiers : disable
  #endif
#endif
#undef _STATIC


#endif

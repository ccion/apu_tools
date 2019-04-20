/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_VECTOR_IF_H
#define _APEX_VECTOR_IF_H

#include <apex/vector-types.h>

#ifdef __cplusplus
  #define __VIF_EXTERN_C extern "C"
#else
  #define __VIF_EXTERN_C
#endif

__VIF_EXTERN_C bool __vif(vbool);

__VIF_EXTERN_C bool __vif_endif(void);

// Implementation of vif
#ifdef __OPENCL_C_VERSION__
  #define vif(b)  if (__vif(__builtin_convertvector((b), vbool)))
#else
  #define vif(b)  if (__vif((vbool)(b)))
#endif
#define velse     else
#define vendif    __vif_endif();

#endif

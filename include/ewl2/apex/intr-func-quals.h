/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/
 
#undef __APEX_INT_F_QUALS
#define __APEX_INT_F_QUALS_NOOV __attribute__((always_inline)) _STATIC inline

#ifndef __cplusplus
  #define __APEX_INT_F_QUALS __attribute__((overloadable)) __APEX_INT_F_QUALS_NOOV
  #ifndef __OPENCL_C_VERSION__
    #define __GET_MACRO_APEX_CARRY(_1,_2,_3,_4,NAME,...) NAME
    #define __GET_MACRO_APEX_VSR(_1,_2,_3,_4,_5,NAME,...) NAME
  #endif
#else
  #define __APEX_INT_F_QUALS __APEX_INT_F_QUALS_NOOV
#endif

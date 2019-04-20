/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_CHESS_COMPATIBILITY_H
#define _APEX_CHESS_COMPATIBILITY_H

#define chess_prepare_for_pipelining
#ifdef __OPENCL_C_VERSION__
  #define chess_loop_range(min, max) __attribute__((apex_min_loop_count(1)))
  #define chess_unroll_loop(n)
#else
  #define chess_loop_range(...) __attribute__((apex_min_loop_count(1)))
  #define chess_unroll_loop(...)
#endif
#define chess_storage(x)
#define chess_copy(x) (x)
#define chess_output 
#ifndef __OPENCL_C_VERSION__
  #define property(...)
#endif

#define __cmem

/* Allow restrict for C++ */
#ifdef __cplusplus
  #define restrict __restrict__
#endif

#endif

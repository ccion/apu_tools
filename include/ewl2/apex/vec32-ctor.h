/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_VEC32_CTOR_H
#define _APEX_VEC32_CTOR_H

#include <apex/scalar-types.h>
#include <apex/vector-types.h>

#include <apex/intr-func-quals.h>

#ifndef __OPENCL_C_VERSION__

/* Macro with a variable number of parameters; will expand to a macro name */
#define __V32_CTOR_MACRO(_1, _2, NAME, ...) NAME

/* Keep the proper cast (C-style vs C++) */
#ifdef __cplusplus
  #define __vec32s_cast(a)    vec32s(a)
  #define __vec32u_cast(a)    vec32u(a)
#else
  #define __vec32s_cast(a)    ((vec32s)(a))
  #define __vec32u_cast(a)    ((vec32u)(a))
#endif

/* The pack macro will call a builtin, with the parameters reversed */
__APEX_INT_F_QUALS vec32s __vec32s_pack(vec16s hi, vec16s lo) {
  return __builtin_apex_vec32_pack(lo, hi);
}
__APEX_INT_F_QUALS vec32s __vec32s_pack(vec16s hi, vec16u lo) {
  return __vec32s_pack((vec16s)hi, (vec16s)lo);
}
__APEX_INT_F_QUALS vec32s __vec32s_pack(vec16u hi, vec16s lo) {
  return __vec32s_pack((vec16s)hi, (vec16s)lo);
}
__APEX_INT_F_QUALS vec32s __vec32s_pack(vec16u hi, vec16u lo) {
  return __vec32s_pack((vec16s)hi, (vec16s)lo);
}
#define __vec32u_pack(hi, lo) ((vec32u)__vec32s_pack(hi, lo))

/* Dispatch to the proper macro, based on the number of parameters */
#define vec32s(...) __V32_CTOR_MACRO(__VA_ARGS__, __vec32s_pack, __vec32s_cast)(__VA_ARGS__)
#define vec32u(...) __V32_CTOR_MACRO(__VA_ARGS__, __vec32u_pack, __vec32u_cast)(__VA_ARGS__)

#endif /* __OPENCL_C_VERSION__ */

#endif

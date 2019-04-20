/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

/**
 * @file 
 * Apex intrinsic header file.
 *
 * This header provides definitions of APEX intrinsics that map to
 * one instruction.
 * These intrinsics have the same name as the instruction to which
 * they map.
 */

#ifndef _APEX_INSTRUCTIONS_H
#define _APEX_INSTRUCTIONS_H

#include <apex/scalar-types.h>
#include <apex/vector-types.h>

#include <apex/intr-func-quals.h>

/**
 * @addtogroup other Other Intrinsics
 * @brief Other intrinsics
 * @{
 */

/////////////////////////////////////////////////////
// Bit count/select                                //
/////////////////////////////////////////////////////

/**
 * Pop count
 * @param a unsigned int
 * @return int total number of one bits
 */
__APEX_INT_F_QUALS int pcnt(unsigned int a) {
  return __builtin_popcount(a);
}

#ifndef __OPENCL_C_VERSION__
/**
 * Count leading zero
 * @param a unsigned int
 * @return int total number of leading zero bits
 */
__APEX_INT_F_QUALS int clz(unsigned int a) {
  return __builtin_clz(a);
}
#endif

/**
 * Count leading same bits
 * @param a unsigned int
 * @return int total number of leading identical bits
 */
__APEX_INT_F_QUALS int clb(unsigned int a) {
  return __builtin_apex_clb(a);
}

/**
 * Signed integer select
 * @param a first input signed int
 * @param b second input signed int
 * @param c control boolean for select
 * @return int return a if true else b
 */
__APEX_INT_F_QUALS int select(bool c, int a, int b) {
  return c ? a : b;
}

/**
 * Unsigned integer select
 * @param a first input unsigned int
 * @param b second input unsigned int
 * @param c control boolean for select
 * @return int return a if true else b
 */
__APEX_INT_F_QUALS unsigned select(bool c, unsigned a, unsigned b) {
  return c ? a : b;
}

/////////////////////////////////////////////////////
// Vbool builtins                                  //
/////////////////////////////////////////////////////

/**
 * Vector count any
 * @param v Input vector
 * @return bool True if any CU is set
 */
__APEX_INT_F_QUALS bool vany(vbool v) {
  return __builtin_apex_vany(v);
}

/**
 * Vector count all
 * @param v Input vector
 * @return bool True if all CU is set
 */
__APEX_INT_F_QUALS bool vall(vbool v) {
  return __builtin_apex_vall(v);
}

/////////////////////////////////////////////////////
// Vector add & div by 2                           //
/////////////////////////////////////////////////////

/**
 * Signed vector add and half
 * @param a first input vector
 * @param b second input vector
 * @return vector (va + vb) / 2
 */
__APEX_INT_F_QUALS vec16s vhaddss(vec16s a, vec16s b) {
  return __builtin_apex_vhadds(a, b);
}

/**
 * Unsigned vector add and half
 * @param a first input vector
 * @param b second input vector
 * @return vector (va + vb) / 2
 */
__APEX_INT_F_QUALS vec16u vhadduu(vec16u a, vec16u b) {
  return __builtin_apex_vhaddu(a, b);
}

/**
 * Signed vector add, plus one then half
 * @param a first input vector
 * @param b second input vector
 * @return vector (va + vb + 1) / 2
 */
__APEX_INT_F_QUALS vec16s vrhaddss(vec16s a, vec16s b) {
  return __builtin_apex_vrhadds(a, b);
}

/**
 * Unsigned vector add, plus one then half
 * @param a first input vector
 * @param b second input vector
 * @return vector (va + vb + 1) / 2
 */
__APEX_INT_F_QUALS vec16u vrhadduu(vec16u a, vec16u b) {
  return __builtin_apex_vrhaddu(a, b);
}

/////////////////////////////////////////////////////
// Vector other                                    //
/////////////////////////////////////////////////////

/**
 * Unsigned vector absolute difference
 * @param a first input vector
 * @param b second input vector
 * @return vector | va - vb |
 */
__APEX_INT_F_QUALS vec16u vabs_diffu(vec16u a, vec16u b) {
  return __builtin_apex_vabs_diffu(a, b);
}

/////////////////////////////////////////////////////
// Scalar add & div by 2                           //
/////////////////////////////////////////////////////

/**
 * Signed add and half
 * @param a first input int
 * @param b second input int
 * @return int (a + b) / 2
 */
__APEX_INT_F_QUALS int haddss(int a, int b) {
  return __builtin_apex_hadds(a, b);
}

/**
 * Unsigned add and half
 * @param a first input int
 * @param b second input int
 * @return unsigned (a + b) / 2
 */
__APEX_INT_F_QUALS unsigned hadduu(unsigned a, unsigned b) {
  return __builtin_apex_haddu(a, b);
}

/**
 * Signed add, plus one then half
 * @param a first input int
 * @param b second input int
 * @return int (a + b + 1) / 2
 */
__APEX_INT_F_QUALS int rhaddss(int a, int b) {
  return __builtin_apex_rhadds(a, b);
}

/**
 * Unsigned add, plus one then half
 * @param a first input int
 * @param b second input int
 * @return int (a + b + 1) / 2
 */
__APEX_INT_F_QUALS unsigned rhadduu(unsigned a, unsigned b) {
  return __builtin_apex_rhaddu(a, b);
}

/////////////////////////////////////////////////////
// Control builtins                                //
/////////////////////////////////////////////////////

/**
 * Wait for a given number of cycles.
 * This instruction will prevent the processor from
 * issuing new instructions for the number of cycles
 * described by immediate parameter.
 * This is defined as a macro because the immediate value
 * needs to be encoded in the instruction.
 * @param imm The number of cycles to wait
 */
#define wait(imm) __builtin_apex_wait(imm)

__APEX_INT_F_QUALS_NOOV void swbreak() {
  __builtin_apex_swbreak();
}

/**
 * @}
 */

#endif

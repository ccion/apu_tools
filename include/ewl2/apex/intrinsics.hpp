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
 * This header provides the definitions of the APEX vector intrinsics.
 * Each intrinsic is defined as a function.
 * While some intrinsic function share the same name, they are different
 * because they have different parameter types.
 */

#ifndef _APEX_VECTOR_INTRINSICS_HPP
#define _APEX_VECTOR_INTRINSICS_HPP

#include <apex/scalar-types.h>
#include <apex/vector-types.h>

#include <apex/intr-func-quals.h>

/**
 * @addtogroup varithInst Arithmetic Intrinsics
 * @brief Vector arithmetic intrinsics
 * @{
 */

/**
 * Addition of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va + vb
 */
__APEX_INT_F_QUALS vec16s vadd(vec16s va, vec16s vb)
{
  return va + vb;
}

/**
 * Addition of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va + vb
 */
__APEX_INT_F_QUALS vec16u vadd(vec16u va, vec16u vb)
{
  return va + vb;
}

/**
 * Addition of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va + vb
 */
__APEX_INT_F_QUALS vec32s vadd(vec32s va, vec32s vb)
{
  return va + vb;
}

/**
 * Addition of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va + vb
 */
__APEX_INT_F_QUALS vec32u vadd(vec32u va, vec32u vb)
{
  return va + vb;
}

/**
 * Addition of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va + vb
 */
__APEX_INT_F_QUALS vec16s vadd(vec16s va, vec16s vb, vbool* restrict vf)
{
  return __builtin_apex_vaddc(va, vb, vf);
}

/**
 * Addition of two vectors with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va + vb
 */
__APEX_INT_F_QUALS vec16u vadd(vec16u va, vec16u vb, vbool* restrict vf)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = vadd(ta, tb, vf);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Addition of two vectors with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va + vb
 */
__APEX_INT_F_QUALS vec32s vadd(vec32s va, vec32s vb, vbool* restrict vf)
{
  vec16s va_lo = __builtin_apex_vec32_get_lo(va);
  vec16s va_hi = __builtin_apex_vec32_get_hi(va);
  vec16s vb_lo = __builtin_apex_vec32_get_lo(vb);
  vec16s vb_hi = __builtin_apex_vec32_get_hi(vb);
  vbool carry;
  vec16s lo = __builtin_apex_vaddc(va_lo, vb_lo, &carry);
  vec16s hi = __builtin_apex_vadde(va_hi, vb_hi, carry, &carry);
  *vf = carry;
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Addition of two vectors with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va + vb
 */
__APEX_INT_F_QUALS vec32u vadd(vec32u va, vec32u vb, vbool* restrict vf)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec32s tb = __builtin_convertvector(vb, vec32s);
  vec32s tc = vadd(ta, tb, vf);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Addition of two vectors with carry
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec16s vaddx(vec16s va, vec16s vb, vbool vc)
{
  vbool vf;
  return __builtin_apex_vadde(va, vb, vc, &vf);
}

/**
 * Addition of two vectors with carry
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec16u vaddx(vec16u va, vec16u vb, vbool vc)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = vaddx(ta, tb, vc);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Addition of two vectors with carry
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec32s vaddx(vec32s va, vec32s vb, vbool vc)
{
  vec16s va_lo = __builtin_apex_vec32_get_lo(va);
  vec16s va_hi = __builtin_apex_vec32_get_hi(va);
  vec16s vb_lo = __builtin_apex_vec32_get_lo(vb);
  vec16s vb_hi = __builtin_apex_vec32_get_hi(vb);
  vbool carry;
  vec16s lo = __builtin_apex_vadde(va_lo, vb_lo, vc, &carry);
  vec16s hi = __builtin_apex_vadde(va_hi, vb_hi, carry, &carry);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Addition of two vectors with carry
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec32u vaddx(vec32u va, vec32u vb, vbool vc)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec32s tb = __builtin_convertvector(vb, vec32s);
  vec32s tc = vaddx(ta, tb, vc);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Addition of two vectors with carry and carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The input carry
 * @param[out] vf Pointer to the output carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec16s vaddx(vec16s va, vec16s vb, vbool vc, vbool* restrict vf)
{
  return __builtin_apex_vadde(va, vb, vc, vf);
}

/**
 * Addition of two vectors with carry and carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The input carry
 * @param[out] vf Pointer to the output carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec16u vaddx(vec16u va, vec16u vb, vbool vc, vbool* restrict vf)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = vaddx(ta, tb, vc, vf);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Addition of two vectors with carry and carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The input carry
 * @param[out] vf Pointer to the output carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec32s vaddx(vec32s va, vec32s vb, vbool vc, vbool* restrict vf)
{
  vec16s va_lo = __builtin_apex_vec32_get_lo(va);
  vec16s va_hi = __builtin_apex_vec32_get_hi(va);
  vec16s vb_lo = __builtin_apex_vec32_get_lo(vb);
  vec16s vb_hi = __builtin_apex_vec32_get_hi(vb);
  vbool carry;
  vec16s lo = __builtin_apex_vadde(va_lo, vb_lo, vc, &carry);
  vec16s hi = __builtin_apex_vadde(va_hi, vb_hi, carry, &carry);
  *vf = carry;
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Addition of two vectors with carry and carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The input carry
 * @param[out] vf Pointer to the output carry
 * @return va + vb + vc
 */
__APEX_INT_F_QUALS vec32u vaddx(vec32u va, vec32u vb, vbool vc, vbool* restrict vf)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec32s tb = __builtin_convertvector(vb, vec32s);
  vec32s tc = vaddx(ta, tb, vc, vf);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Addition of two signed vectors, with saturation
 * Positive results will saturate at 0x7FFF and negative results will
 * saturate  at 0x8000.
 * @param va The first vector
 * @param vb The second vector
 * @return va + vb
 */
__APEX_INT_F_QUALS vec16s vadd_sat(vec16s va, vec16s vb)
{
  return __builtin_apex_vadd_sat(va, vb);
}

/**
 * Addition of two unsigned vectors, with saturation
 * Positive results will saturate at 0xFFFF.
 * @param va The first vector
 * @param vb The second vector
 * @return va + vb
 */
__APEX_INT_F_QUALS vec16u vadd_sat(vec16u va, vec16u vb)
{
  return __builtin_apex_vadd_satu(va, vb);
}

/**
 * Subtract one vector from another
 * @param va The first vector
 * @param vb The second vector
 * @return va - vb
 */
__APEX_INT_F_QUALS vec16s vsub(vec16s va, vec16s vb)
{
  return va - vb;
}

/**
 * Subtract one vector from another
 * @param va The first vector
 * @param vb The second vector
 * @return va - vb
 */
__APEX_INT_F_QUALS vec16u vsub(vec16u va, vec16u vb)
{
  return va - vb;
}

/**
 * Subtract one vector from another
 * @param va The first vector
 * @param vb The second vector
 * @return va - vb
 */
__APEX_INT_F_QUALS vec32s vsub(vec32s va, vec32s vb)
{
  return va - vb;
}

/**
 * Subtract one vector from another
 * @param va The first vector
 * @param vb The second vector
 * @return va - vb
 */
__APEX_INT_F_QUALS vec32u vsub(vec32u va, vec32u vb)
{
  return va - vb;
}

/**
 * Subtract one vector from another, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va - vb
 */
__APEX_INT_F_QUALS vec16s vsub(vec16s va, vec16s vb, vbool* restrict vf)
{
  return __builtin_apex_vsubc(va, vb, vf);
}

/**
 * Subtract one vector from another, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va - vb
 */
__APEX_INT_F_QUALS vec16u vsub(vec16u va, vec16u vb, vbool* restrict vf)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = vsub(ta, tb, vf);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Subtract one vector from another, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va - vb
 */
__APEX_INT_F_QUALS vec32s vsub(vec32s va, vec32s vb, vbool* restrict vf)
{
  vec16s va_lo = __builtin_apex_vec32_get_lo(va);
  vec16s va_hi = __builtin_apex_vec32_get_hi(va);
  vec16s vb_lo = __builtin_apex_vec32_get_lo(vb);
  vec16s vb_hi = __builtin_apex_vec32_get_hi(vb);
  vbool carry;
  vec16s lo = __builtin_apex_vsubc(va_lo, vb_lo, &carry);
  vec16s hi = __builtin_apex_vsube(va_hi, vb_hi, carry, &carry);
  *vf = carry;
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Subtract one vector from another, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param[out] vf Pointer to the carry
 * @return va - vb
 */
__APEX_INT_F_QUALS vec32u vsub(vec32u va, vec32u vb, vbool* restrict vf)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec32s tb = __builtin_convertvector(vb, vec32s);
  vec32s tc = vsub(ta, tb, vf);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Subtract one vector and the carry from another vector
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec16s vsubx(vec16s va, vec16s vb, vbool vc)
{
  vbool vf;
  return __builtin_apex_vsube(va, vb, vc, &vf);
}

/**
 * Subtract one vector and the carry from another vector
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec16u vsubx(vec16u va, vec16u vb, vbool vc)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = vsubx(ta, tb, vc);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Subtract one vector and the carry from another vector
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec32s vsubx(vec32s va, vec32s vb, vbool vc)
{
  vec16s va_lo = __builtin_apex_vec32_get_lo(va);
  vec16s va_hi = __builtin_apex_vec32_get_hi(va);
  vec16s vb_lo = __builtin_apex_vec32_get_lo(vb);
  vec16s vb_hi = __builtin_apex_vec32_get_hi(vb);
  vbool carry;
  vec16s lo = __builtin_apex_vsube(va_lo, vb_lo, vc, &carry);
  vec16s hi = __builtin_apex_vsube(va_hi, vb_hi, carry, &carry);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Subtract one vector and the carry from another vector
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec32u vsubx(vec32u va, vec32u vb, vbool vc)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec32s tb = __builtin_convertvector(vb, vec32s);
  vec32s tc = vsubx(ta, tb, vc);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Subtract one vector and the carry from another vector, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @param[out] vf Pointer to the output carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec16s vsubx(vec16s va, vec16s vb, vbool vc, vbool* restrict vf)
{
  return __builtin_apex_vsube(va, vb, vc, vf);
}

/**
 * Subtract one vector and the carry from another vector, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @param[out] vf Pointer to the output carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec16u vsubx(vec16u va, vec16u vb, vbool vc, vbool* restrict vf)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = vsubx(ta, tb, vc, vf);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Subtract one vector and the carry from another vector, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @param[out] vf Pointer to the output carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec32s vsubx(vec32s va, vec32s vb, vbool vc, vbool* restrict vf)
{
  vec16s va_lo = __builtin_apex_vec32_get_lo(va);
  vec16s va_hi = __builtin_apex_vec32_get_hi(va);
  vec16s vb_lo = __builtin_apex_vec32_get_lo(vb);
  vec16s vb_hi = __builtin_apex_vec32_get_hi(vb);
  vbool carry;
  vec16s lo = __builtin_apex_vsube(va_lo, vb_lo, vc, &carry);
  vec16s hi = __builtin_apex_vsube(va_hi, vb_hi, carry, &carry);
  *vf = carry;
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Subtract one vector and the carry from another vector, with carry generation
 * @param va The first vector
 * @param vb The second vector
 * @param vc The carry
 * @param[out] vf Pointer to the output carry
 * @return va - vb - vc
 */
__APEX_INT_F_QUALS vec32u vsubx(vec32u va, vec32u vb, vbool vc, vbool* restrict vf)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec32s tb = __builtin_convertvector(vb, vec32s);
  vec32s tc = vsubx(ta, tb, vc, vf);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Signed vector subtraction, with saturation
 * Positive results will saturate at 0x7FFF and negative results will
 * saturate  at 0x8000.
 * @param va The first vector
 * @param vb The second vector
 * @return va - vb
 */
__APEX_INT_F_QUALS vec16s vsub_sat(vec16s va, vec16s vb)
{
  return __builtin_apex_vsub_sat(va, vb);
}

/**
 * Unsigned vector subtraction, with saturation
 * Positive results will saturate at 0xFFFF.
 * @param va The first vector
 * @param vb The second vector
 * @return va - vb
 */
__APEX_INT_F_QUALS vec16u vsub_sat(vec16u va, vec16u vb)
{
  return __builtin_apex_vsub_satu(va, vb);
}

/**
 * Vector absolute difference of 2 signed vectors
 * @param va The first vector
 * @param vb The second vector
 * @return |va - vb|
 */
__APEX_INT_F_QUALS vec16s vabs_diff(vec16s va, vec16s vb)
{
  return __builtin_apex_vabs_diff(va, vb);
}

/**
 * Vector absolute difference of 2 unsigned vectors
 * @param va The first vector
 * @param vb The second vector
 * @return |va - vb|
 */
__APEX_INT_F_QUALS vec16u vabs_diff(vec16u va, vec16u vb)
{
  return __builtin_apex_vabs_diffu(va, vb);
}

/**
 * Vector Add/Subtract based on condition
 * @param va The first vector
 * @param vb The second vector
 * @param vc The condition
 * @return vc ? (va + vb) : (va - vb)
 */
__APEX_INT_F_QUALS vec16s vasb(vec16s va, vec16s vb, vbool vc)
{
  return __builtin_apex_vasb(va, vb, vc, 0);
}

/**
 * Vector Add/Subtract based on condition
 * @param a The first vector
 * @param b The second vector
 * @param c The condition
 * @return vc ? (va + vb) : (va - vb)
 */
__APEX_INT_F_QUALS vec16u vasb(vec16u a, vec16u b, vbool c)
{
  return (vec16u)vasb((vec16s)a, (vec16s)b, c);
}

/**
 * Vector add with absolute value of second vector
 * The instruction will check the first bit of vb to determine it's sign
 * @param a The first vector
 * @param b The second vector
 * @return va + |vb|
 */
__APEX_INT_F_QUALS vec16s vasbs(vec16s a, vec16s b)
{
  return __builtin_apex_vasbs(a, b);
}

/**
 * Vector add with absolute value of second vector
 * The instruction will check the first bit of vb to determine it's sign
 * @param a The first vector
 * @param b The second vector
 * @return va + |vb|
 */
__APEX_INT_F_QUALS vec16u vasbs(vec16u a, vec16u b)
{
  return (vec16u)vasbs((vec16s)a, (vec16s)b);
}

/**
 * Multiplication of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va * vb
 */
__APEX_INT_F_QUALS vec16s vmul(vec16s va, vec16s vb)
{
  return va * vb;
}

/**
 * Multiplication of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va * vb
 */
__APEX_INT_F_QUALS vec16u vmul(vec16u va, vec16u vb)
{
  return va * vb;
}

/**
 * Multiplication of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va * vb
 */
__APEX_INT_F_QUALS vec32s vmul(vec32s va, vec32s vb)
{
  return va * vb;
}

/**
 * Multiplication of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va * vb
 */
__APEX_INT_F_QUALS vec32u vmul(vec32u va, vec32u vb)
{
  return va * vb;
}

/**
 * Vector accumulate low (32-bit += 16-bit, zero-extend)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec16s* restrict a, vec16u* restrict b, vec16s c)
{
  __builtin_apex_vacl(a, (vec16s*)b, c);
}

/**
 * Vector accumulate low (32-bit += 16-bit, zero-extend)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec16s* restrict a, vec16u* restrict b, vec16u c)
{
  __builtin_apex_vaclu(a, (vec16s*)b, (vec16s)c);
}

/**
 * Vector accumulate low (32-bit += 16-bit, zero-extend)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec16u* restrict a, vec16u* restrict b, vec16u c)
{
  __builtin_apex_vaclu((vec16s*)a, (vec16s*)b, (vec16s)c);
}

/**
 * Vector accumulate low (32-bit += 16-bit, sign-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec32s* restrict a, vec16s c)
{
  vec32s tmp = *a;
  vec16s lo = __builtin_apex_vec32_get_lo(tmp);
  vec16s hi = __builtin_apex_vec32_get_hi(tmp);
  vec16s *lop = (&lo);
  vec16s *hip = (&hi);
  __builtin_apex_vacl(hip, lop, c);
  tmp = __builtin_apex_vec32_pack(lo, hi);
  *a = tmp;
}

/**
 * Vector accumulate low (32-bit += 16-bit, zero-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec32u* restrict a, vec16u c)
{
  vec32s tmp = (vec32s)(*a);
  vec16s lo = __builtin_apex_vec32_get_lo(tmp);
  vec16s hi = __builtin_apex_vec32_get_hi(tmp);
  vec16s *lop = (&lo);
  vec16s *hip = (&hi);
  vec16s tc = __builtin_convertvector(c, vec16s);
  __builtin_apex_vaclu(hip, lop, tc);
  tmp = __builtin_apex_vec32_pack(lo, hi);
  *a = (vec32u)(tmp);
}

/**
 * Vector accumulate low (32-bit += 16-bit, zero-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec32s* restrict a, vec16u c)
{
  vacl((vec32u*)a, c);
}

/**
 * Vector accumulate low (32-bit += 16-bit, zero-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacl(vec32u* restrict a, vec16s c)
{
  vacl(a, (vec16u)c);
}

/**
 * Vector accumulate middle (32-bit += 16-bit, sign-extend)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec16s* restrict a, vec16u* restrict b, vec16s c)
{
  __builtin_apex_vacm(a, (vec16s*)b, c);
}

/**
 * Vector accumulate middle (32-bit += 16-bit, zero-extend)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec16s* restrict a, vec16u* restrict b, vec16u c)
{
  __builtin_apex_vacmu(a, (vec16s*)b, (vec16s)c);
}

/**
 * Vector accumulate middle (32-bit += 16-bit, zero-extend)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec16u* restrict a, vec16u* restrict b, vec16u c)
{
  __builtin_apex_vacmu((vec16s*)a, (vec16s*)b, (vec16s)c);
}

/**
 * Vector accumulate middle (32-bit += 16-bit, sign-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec32s* restrict a, vec16s c)
{
  vec32s tmp = *a;
  vec16s lo = __builtin_apex_vec32_get_lo(tmp);
  vec16s hi = __builtin_apex_vec32_get_hi(tmp);
  vec16s *lop = (&lo);
  vec16s *hip = (&hi);
  __builtin_apex_vacm(hip, lop, c);
  tmp = __builtin_apex_vec32_pack(lo, hi);
  *a = tmp;
}

/**
 * Vector accumulate middle (32-bit += 16-bit, zero-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec32u* restrict a, vec16u c)
{
  vec32s tmp = (vec32s)(*a);
  vec16s lo = __builtin_apex_vec32_get_lo(tmp);
  vec16s hi = __builtin_apex_vec32_get_hi(tmp);
  vec16s *lop = (&lo);
  vec16s *hip = (&hi);
  vec16s tc = __builtin_convertvector(c, vec16s);
  __builtin_apex_vacmu(hip, lop, tc);
  tmp = __builtin_apex_vec32_pack(lo, hi);
  *a = (vec32u)(tmp);
}

/**
 * Vector accumulate middle (32-bit += 16-bit, zero-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec32s* restrict a, vec16u c)
{
  vacm((vec32u*)a, c);
}

/**
 * Vector accumulate middle (32-bit += 16-bit, zero-extend)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vacm(vec32u* restrict a, vec16s c)
{
  vacm(a, (vec16u)c);
}

/**
 * Vector accumulate high (32-bit += 16-bit)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vach(vec16s* restrict a, vec16u* restrict b, vec16s c)
{
  *a = *a + c;
}

/**
 * Vector accumulate high (32-bit += 16-bit)
 * @param a Output vector
 * @param b The first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vach(vec16s* restrict a, vec16u* restrict b, vec16u c)
{
  *a = *a + (vec16s)c;
}

/**
 * Vector accumulate high (32-bit += 16-bit)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vach(vec32s* restrict a, vec16s c)
{
  vec32s tmp = *a;
  vec16s lo = __builtin_apex_vec32_get_lo(tmp);
  vec16s hi = __builtin_apex_vec32_get_hi(tmp);
  vec16u *lop = (vec16u*)(&lo);
  vec16s *hip = (&hi);
  vach(hip, lop, c);
  tmp = __builtin_apex_vec32_pack(lo, hi);
  *a = tmp;
}

/**
 * Vector accumulate high (32-bit += 16-bit)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vach(vec32u* restrict a, vec16u c)
{
  vach((vec32s*)a, (vec16s)c);
}

/**
 * Vector accumulate high (32-bit += 16-bit)
 * @param a Output and first input vector
 * @param c The second input vector
 */
__APEX_INT_F_QUALS void vach(vec32u* restrict a, vec16s c)
{
  vach((vec32s*)a, c);
}

/**
 * Vector absolute value
 * @param va Input vector
 * @return Output absolute vector
 */
__APEX_INT_F_QUALS vec08u vabs(vec08s va)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  return __builtin_convertvector(__builtin_apex_vabs(ta), vec08u);
}

/**
 * Vector absolute value
 * @param va Input vector
 * @return Output absolute vector
 */
__APEX_INT_F_QUALS vec16u vabs(vec16s va)
{
  vec16u res = __builtin_apex_vabs(va);
  return res;
}

/**
 * Vector absolute value
 * @param va Input vector
 * @return Output absolute vector
 */
__APEX_INT_F_QUALS vec32u vabs(vec32s va)
{
  vec16s hi = __builtin_apex_vec32_get_hi(va);
  vec16s sgn = hi >> (vec16s)15;
  vec32s p1 = __builtin_apex_vec32_pack(sgn, sgn);
  vec32s p2 = ((va + p1) ^ p1);
  return __builtin_convertvector(p2, vec32u);
}

/**
 * Vector saturate with lower and upper bounds
 * @param va Input source vector
 * @param vb Input vector of lower bound
 * @param vc Input vector of upper bound
 * @return Output saturated vector
 */
__APEX_INT_F_QUALS vec16s vsat(vec16s va, vec16s vb, vec16s vc)
{
  return __builtin_apex_vsat_vv(va, vb, vc);
}

/**
 * Vector saturate with lower and upper bounds
 * @param va Input source vector
 * @param vb Input vector of lower bound
 * @param vc Input vector of upper bound
 * @return Output saturated vector
 */
__APEX_INT_F_QUALS vec16u vsat(vec16u va, vec16u vb, vec16u vc)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = __builtin_convertvector(vc, vec16s);
  vec16s td = vsat(ta, tb, tc);
  return __builtin_convertvector(td, vec16u);
}

/**
 * Vector count leading zero bits
 * @param va Input vector
 * @return vector of leading zero bits count
 */
__APEX_INT_F_QUALS vec16s vclz(vec16s va)
{
  return __builtin_apex_vclz(va);
}

/**
 * Vector count leading zero bits
 * @param va Input vector
 * @return vector of leading zero bits count
 */
__APEX_INT_F_QUALS vec16u vclz(vec16u va)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = vclz(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector count leading zero bits
 * @param va Input vector
 * @return vector of leading zero bits count
 */
__APEX_INT_F_QUALS vec16s vclz(vec32s va)
{
  vec16s hi = __builtin_apex_vec32_get_hi(va);
  vec16s lo = __builtin_apex_vec32_get_lo(va);
  vec16s cnthi = vclz(hi);
  vec16s cntlo = vclz(lo);
  vbool cond = (vbool)(cnthi == (vec16s)16);
  return __builtin_apex_vsel_16((vec16s)16 + cntlo, cnthi, cond);
}

/**
 * Vector count leading zero bits
 * @param va Input vector
 * @return vector of leading zero bits count
 */
__APEX_INT_F_QUALS vec16u vclz(vec32u va)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec16s tb = vclz(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector count number of 1 bits
 * @param va Input vector
 * @return vector of 1 bits count
 */
__APEX_INT_F_QUALS vec16s vpcnt(vec16s va)
{
  return __builtin_apex_vpcnt(va);
}

/**
 * Vector count number of 1 bits
 * @param va Input vector
 * @return vector of 1 bits count
 */
__APEX_INT_F_QUALS vec16u vpcnt(vec16u va)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = vpcnt(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector count number of 1 bits
 * @param va Input vector
 * @return vector of 1 bits count
 */
__APEX_INT_F_QUALS vec16s vpcnt(vec32s va)
{
  vec16s hi = __builtin_apex_vec32_get_hi(va);
  vec16s lo = __builtin_apex_vec32_get_lo(va);
  vec16s cnthi = vpcnt(hi);
  vec16s cntlo = vpcnt(lo);
  return cnthi + cntlo;
}

/**
 * Vector count number of 1 bits
 * @param va Input vector
 * @return vector of 1 bits count
 */
__APEX_INT_F_QUALS vec16u vpcnt(vec32u va)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec16s tb = vpcnt(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector count leading same bits
 * @param va Input vector
 * @return vector of leading same bits count
 */
__APEX_INT_F_QUALS vec16s vclb(vec16s va)
{
  vec16u ta = __builtin_convertvector(va, vec16u);
  return __builtin_apex_vcld(ta);
}

/**
 * Vector count leading same bits
 * @param va Input vector
 * @return vector of leading same bits count
 */
__APEX_INT_F_QUALS vec16u vclb(vec16u va)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = vclb(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector count leading same bits
 * @param va Input vector
 * @return vector of leading same bits count
 */
__APEX_INT_F_QUALS vec16s vclb(vec32s va)
{
  vec32u abs = vabs(va);
  vec16u samebits = vclz(abs);
  return __builtin_convertvector(samebits, vec16s);
}

/**
 * Vector count leading same bits
 * @param va Input vector
 * @return vector of leading same bits count
 */
__APEX_INT_F_QUALS vec16u vclb(vec32u va)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  vec16s tb = vclb(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * @}
 *
 * @addtogroup vbitewiseInst Bitwise Intrinsics
 * @brief Vector bitewise intrinsics 
 * @{
 */

/**
 * Bitwise And of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va & vb
 */
__APEX_INT_F_QUALS vec08s vand(vec08s va, vec08s vb)
{
  return va & vb;
}

/**
 * Bitwise And of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va & vb
 */
__APEX_INT_F_QUALS vec08u vand(vec08u va, vec08u vb)
{
  return va & vb;
}

/**
 * Bitwise And of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va & vb
 */
__APEX_INT_F_QUALS vec16s vand(vec16s va, vec16s vb)
{
  return va & vb;
}

/**
 * Bitwise And of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va & vb
 */
__APEX_INT_F_QUALS vec16u vand(vec16u va, vec16u vb)
{
  return va & vb;
}

/**
 * Bitwise And of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va & vb
 */
__APEX_INT_F_QUALS vec32s vand(vec32s va, vec32s vb)
{
  return va & vb;
}

/**
 * Bitwise And of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va & vb
 */
__APEX_INT_F_QUALS vec32u vand(vec32u va, vec32u vb)
{
  return va & vb;
}

/**
 * Bitwise Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va | vb
 */
__APEX_INT_F_QUALS vec08s vor(vec08s va, vec08s vb)
{
  return va | vb;
}

/**
 * Bitwise Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va | vb
 */
__APEX_INT_F_QUALS vec08u vor(vec08u va, vec08u vb)
{
  return va | vb;
}

/**
 * Bitwise Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va | vb
 */
__APEX_INT_F_QUALS vec16s vor(vec16s va, vec16s vb)
{
  return va | vb;
}

/**
 * Bitwise Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va | vb
 */
__APEX_INT_F_QUALS vec16u vor(vec16u va, vec16u vb)
{
  return va | vb;
}

/**
 * Bitwise Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va | vb
 */
__APEX_INT_F_QUALS vec32s vor(vec32s va, vec32s vb)
{
  return va | vb;
}

/**
 * Bitwise Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va | vb
 */
__APEX_INT_F_QUALS vec32u vor(vec32u va, vec32u vb)
{
  return va | vb;
}

/**
 * Bitwise Exclusive-Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va ^ vb
 */
__APEX_INT_F_QUALS vec08s vxor(vec08s va, vec08s vb)
{
  return va ^ vb;
}

/**
 * Bitwise Exclusive-Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va ^ vb
 */
__APEX_INT_F_QUALS vec08u vxor(vec08u va, vec08u vb)
{
  return va ^ vb;
}

/**
 * Bitwise Exclusive-Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va ^ vb
 */
__APEX_INT_F_QUALS vec16s vxor(vec16s va, vec16s vb)
{
  return va ^ vb;
}

/**
 * Bitwise Exclusive-Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va ^ vb
 */
__APEX_INT_F_QUALS vec16u vxor(vec16u va, vec16u vb)
{
  return va ^ vb;
}

/**
 * Bitwise Exclusive-Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va ^ vb
 */
__APEX_INT_F_QUALS vec32s vxor(vec32s va, vec32s vb)
{
  return va ^ vb;
}

/**
 * Bitwise Exclusive-Or of two vectors
 * @param va The first vector
 * @param vb The second vector
 * @return va ^ vb
 */
__APEX_INT_F_QUALS vec32u vxor(vec32u va, vec32u vb)
{
  return va ^ vb;
}

/**
 * Bitwise Not (Vector Ones' Complement) of one vector
 * @param va The vector
 * @return va ^ (-1)
 */
__APEX_INT_F_QUALS vec08s vnot(vec08s va)
{
  return va ^ (vec08s)(-1);
}

/**
 * Bitwise Not (Vector Ones' Complement) of one vector
 * @param va The vector
 * @return va ^ (-1)
 */
__APEX_INT_F_QUALS vec08u vnot(vec08u va)
{
  return (vec08u)vnot((vec08s)va);
}

/**
 * Bitwise Not (Vector Ones' Complement) of one vector
 * @param va The vector
 * @return va ^ (-1)
 */
__APEX_INT_F_QUALS vec16s vnot(vec16s va)
{
  return va ^ (vec16s)(-1);
}

/**
 * Bitwise Not (Vector Ones' Complement) of one vector
 * @param va The vector
 * @return va ^ (-1)
 */
__APEX_INT_F_QUALS vec16u vnot(vec16u va)
{
  return (vec16u)vnot((vec16s)va);
}

/**
 * Bitwise Not (Vector Ones' Complement) of one vector
 * @param va The vector
 * @return va ^ (-1)
 */
__APEX_INT_F_QUALS vec32s vnot(vec32s va)
{
  return va ^ (vec32s)(-1);
}

/**
 * Bitwise Not (Vector Ones' Complement) of one vector
 * @param va The vector
 * @return va ^ (-1)
 */
__APEX_INT_F_QUALS vec32u vnot(vec32u va)
{
    return (vec32u)vnot((vec32s)va);
}

/**
 * Vector Ones' Complement
 * @param va The vector
 * @return vnot(va)
 */
__APEX_INT_F_QUALS vec08s vcomplement(vec08s va)
{
  return vnot(va);
}

/**
 * Vector Ones' Complement
 * @param va The vector
 * @return vnot(va)
 */
__APEX_INT_F_QUALS vec08u vcomplement(vec08u va)
{
  return vnot(va);
}

/**
 * Vector Ones' Complement
 * @param va The vector
 * @return vnot(va)
 */
__APEX_INT_F_QUALS vec16s vcomplement(vec16s va)
{
  return vnot(va);
}

/**
 * Vector Ones' Complement
 * @param va The vector
 * @return vnot(va)
 */
__APEX_INT_F_QUALS vec16u vcomplement(vec16u va)
{
  return vnot(va);
}

/**
 * Vector Ones' Complement
 * @param va The vector
 * @return vnot(va)
 */
__APEX_INT_F_QUALS vec32s vcomplement(vec32s va)
{
  return vnot(va);
}

/**
 * Vector Ones' Complement
 * @param va The vector
 * @return vnot(va)
 */
__APEX_INT_F_QUALS vec32u vcomplement(vec32u va)
{
  return vnot(va);
}

/**
 * @}
 *
 * @addtogroup vshiftInst Shift Intrinsics
 * @brief Vector shift intrinsics 
 * @{
 */

/**
 * Vector Shift Left (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va << vb
 */
__APEX_INT_F_QUALS vec16s vsl(vec16s va, vec16s vb)
{
  return va << vb;
}

/**
 * Vector Shift Left (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va << vb
 */
__APEX_INT_F_QUALS vec16u vsl(vec16u va, vec16u vb)
{
  return va << vb;
}

/**
 * Vector Shift Left (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va << vb
 */
__APEX_INT_F_QUALS vec32s vsl(vec32s va, vec16s vb)
{
  vec32s tb = __builtin_convertvector(vb, vec32s);
  return va << tb;
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec16s vsr(vec16s va, vec16s vb)
{
  return va >> vb;
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec16u vsr(vec16u va, vec16u vb)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = ta >> tb;
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec32s vsr(vec32s va, vec32s vb)
{
  return va >> vb;
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec32s vsr(vec32s va, vec16s vb)
{
  vec32s tb = __builtin_convertvector(vb, vec32s);
  return va >> tb;
}

/**
 * Vector Shift Left (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va << vb
 */
__APEX_INT_F_QUALS vec16s vsll(vec16s va, vec16s vb)
{
  return va << vb;
}

/**
 * Vector Shift Left (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va << vb
 */
__APEX_INT_F_QUALS vec16u vsll(vec16u va, vec16u vb)
{
  return va << vb;
}

/**
 * Vector Shift Left (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va << vb
 */
__APEX_INT_F_QUALS vec32s vsll(vec32s va, vec32s vb)
{
  return va << vb;
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec16s vsra(vec16s va, vec16s vb)
{
  return va >> vb;
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec16u vsra(vec16u va, vec16u vb)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s tc = ta >> tb;
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec32s vsra(vec32s va, vec32s vb)
{
  return va >> vb;
}

/**
 * Vector Shift Right (Arithmetic)
 * @param va The vector
 * @param s The shift amount
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec32s vsra(vec32u va, int s)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  return ta >> (vec32s)s;
}

/**
 * Vector Shift Right (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec16s vsrl(vec16s va, vec16s vb)
{
  vec16u ta = __builtin_convertvector(va, vec16u);
  vec16u tb = __builtin_convertvector(vb, vec16u);
  vec16u tc = ta >> tb;
  return __builtin_convertvector(tc, vec16s);
}

/**
 * Vector Shift Right (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec16u vsrl(vec16u va, vec16u vb)
{
  return va >> vb;
}

/**
 * Vector Shift Right (Logical)
 * @param va The vector
 * @param vb The shift amount vector
 * @return va >> vb
 */
__APEX_INT_F_QUALS vec32s vsrl(vec32s va, vec32s vb)
{
  vec32u ta = __builtin_convertvector(va, vec32u);
  vec32u tb = __builtin_convertvector(vb, vec32u);
  vec32u tc = ta >> tb;
  return __builtin_convertvector(tc, vec32s);
}

/**
 * Vector Left Shift-in with OV (Logical)
 * @param va Input vector
 * @param vc Input OV vector being shifted in to LSB
 * @param vf Output vector of result MSB
 * @return vector va left shift by 1 bit, with vc shifted into LSB
 */
__APEX_INT_F_QUALS vec16s vslo(vec16s va, vbool vc, vbool* restrict vf)
{
  return __builtin_apex_vslo(va, vc, vf);
}

/**
 * Vector Left Shift-in with OV (Logical)
 * @param va Input vector
 * @param vc Input OV vector being shifted in to LSB
 * @return vector va left shift by 1 bit, with vc shifted into LSB
 */
__APEX_INT_F_QUALS vec16s vslo(vec16s va, vbool vc)
{
  vbool vf;
  return vslo(va, vc, &vf);
}

/**
 * Vector left Shift-in with VC (Logical)
 * @param va Input vector
 * @param vc Input vector condition being shifted in to LSB
 * @return vector va left shift by 1 bit, with vc shifted into LSB
 */
__APEX_INT_F_QUALS vec16s vslc(vec16s va, vbool vc)
{
  return __builtin_apex_vslc(vc, va);
}

/**
 * Vector Right Shift-in with OV (Logical)
 * @param va Input vector
 * @param vc Input OV vector being shifted in to MSB
 * @param vf Output vector of result LSB
 * @return vector va right shift by 1 bit, with vc shifted into MSB
 */
__APEX_INT_F_QUALS vec16s vsro(vec16s va, vbool vc, vbool* restrict vf)
{
  return __builtin_apex_vsro(va, vc, vf);
}

/**
 * Vector Right Shift-in with OV (Logical)
 * @param va Input vector
 * @param vc Input OV vector being shifted in to MSB
 * @return vector va right shift by 1 bit, with vc shifted into MSB
 */
__APEX_INT_F_QUALS vec16s vsro(vec16s va, vbool vc)
{
  vbool vf;
  return vsro(va, vc, &vf);
}

/**
 * Vector Right Shift-in with VC (Logical)
 * @param va Input vector
 * @param vc Input vector condition being shifted in to MSB
 * @return vector va right shift by 1 bit, with vc shifted into MSB
 */
__APEX_INT_F_QUALS vec16s vsrc(vec16s va, vbool vc)
{
  return __builtin_apex_vsrc(vc, va);
}

/**
 * @}
 *
 * @addtogroup vcmpInst Comparison Intrinsics
 * @brief Vector comparison intrinsics 
 * @{
 */

/**
 * Vector Set Comparison Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va == vb
 */
__APEX_INT_F_QUALS vbool vseq(vec16s va, vec16s vb)
{
  return __builtin_convertvector(va == vb, vbool);
}

/**
 * Vector Set Comparison Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va == vb
 */
__APEX_INT_F_QUALS vbool vsequ(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va == vb, vbool);
}

/**
 * Vector Set Comparison Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va == vb
 */
__APEX_INT_F_QUALS vbool vseq(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va == vb, vbool);
}

/**
 * Vector Set Comparison Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va == vb
 */
__APEX_INT_F_QUALS vbool vseq(vec32s va, vec32s vb)
{
  return __builtin_convertvector(va == vb, vbool);
}

/**
 * Vector Set Comparison Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va == vb
 */
__APEX_INT_F_QUALS vbool vseq(vec32u va, vec32u vb)
{
  return __builtin_convertvector(va == vb, vbool);
}

/**
 * Vector Set Comparison Not Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va != vb
 */
__APEX_INT_F_QUALS vbool vsne(vec16s va, vec16s vb)
{
  return __builtin_convertvector(va != vb, vbool);
}

/**
 * Vector Set Comparison Not Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va != vb
 */
__APEX_INT_F_QUALS vbool vsneu(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va != vb, vbool);
}

/**
 * Vector Set Comparison Not Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va != vb
 */
__APEX_INT_F_QUALS vbool vsne(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va != vb, vbool);
}

/**
 * Vector Set Comparison Not Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va != vb
 */
__APEX_INT_F_QUALS vbool vsne(vec32s va, vec32s vb)
{
  return __builtin_convertvector(va != vb, vbool);
}

/**
 * Vector Set Comparison Not Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va != vb
 */
__APEX_INT_F_QUALS vbool vsne(vec32u va, vec32u vb)
{
  return __builtin_convertvector(va != vb, vbool);
}

/**
 * Vector Set Greater than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va >= vb
 */
__APEX_INT_F_QUALS vbool vsge(vec16s va, vec16s vb)
{
  return __builtin_convertvector(va >= vb, vbool);
}

/**
 * Vector Set Greater than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va >= vb
 */
__APEX_INT_F_QUALS vbool vsgeu(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va >= vb, vbool);
}

/**
 * Vector Set Greater than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va >= vb
 */
__APEX_INT_F_QUALS vbool vsge(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va >= vb, vbool);
}

/**
 * Vector Set Greater than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va >= vb
 */
__APEX_INT_F_QUALS vbool vsge(vec32s va, vec32s vb)
{
  return __builtin_convertvector(va >= vb, vbool);
}

/**
 * Vector Set Greater than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va >= vb
 */
__APEX_INT_F_QUALS vbool vsge(vec32u va, vec32u vb)
{
  return __builtin_convertvector(va >= vb, vbool);
}

/**
 * Vector Set Greater than.
 * @param va The first vector
 * @param vb The second vector
 * @return va > vb
 */
__APEX_INT_F_QUALS vbool vsgt(vec16s va, vec16s vb)
{
  return __builtin_convertvector(va > vb, vbool);
}

/**
 * Vector Set Greater than.
 * @param va The first vector
 * @param vb The second vector
 * @return va > vb
 */
__APEX_INT_F_QUALS vbool vsgtu(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va > vb, vbool);
}

/**
 * Vector Set Greater than.
 * @param va The first vector
 * @param vb The second vector
 * @return va > vb
 */
__APEX_INT_F_QUALS vbool vsgt(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va > vb, vbool);
}

/**
 * Vector Set Greater than.
 * @param va The first vector
 * @param vb The second vector
 * @return va > vb
 */
__APEX_INT_F_QUALS vbool vsgt(vec32s va, vec32s vb)
{
  return __builtin_convertvector(va > vb, vbool);
}

/**
 * Vector Set Greater than.
 * @param va The first vector
 * @param vb The second vector
 * @return va > vb
 */
__APEX_INT_F_QUALS vbool vsgt(vec32u va, vec32u vb)
{
  return __builtin_convertvector(va > vb, vbool);
}

/**
 * Vector Set Less than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va <= vb
 */
__APEX_INT_F_QUALS vbool vsle(vec16s va, vec16s vb)
{
  return __builtin_convertvector(va <= vb, vbool);
}

/**
 * Vector Set Less than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va <= vb
 */
__APEX_INT_F_QUALS vbool vsleu(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va <= vb, vbool);
}

/**
 * Vector Set Less than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va <= vb
 */
__APEX_INT_F_QUALS vbool vsle(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va <= vb, vbool);
}

/**
 * Vector Set Less than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va <= vb
 */
__APEX_INT_F_QUALS vbool vsle(vec32s va, vec32s vb)
{
  return __builtin_convertvector(va <= vb, vbool);
}

/**
 * Vector Set Less than or Equal.
 * @param va The first vector
 * @param vb The second vector
 * @return va <= vb
 */
__APEX_INT_F_QUALS vbool vsle(vec32u va, vec32u vb)
{
  return __builtin_convertvector(va <= vb, vbool);
}

/**
 * Vector Set Less than.
 * @param va The first vector
 * @param vb The second vector
 * @return va < vb
 */
__APEX_INT_F_QUALS vbool vslt(vec16s va, vec16s vb)
{
  return __builtin_convertvector(va < vb, vbool);
}

/**
 * Vector Set Less than.
 * @param va The first vector
 * @param vb The second vector
 * @return va < vb
 */
__APEX_INT_F_QUALS vbool vsltu(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va < vb, vbool);
}

/**
 * Vector Set Less than.
 * @param va The first vector
 * @param vb The second vector
 * @return va < vb
 */
__APEX_INT_F_QUALS vbool vslt(vec16u va, vec16u vb)
{
  return __builtin_convertvector(va < vb, vbool);
}

/**
 * Vector Set Less than.
 * @param va The first vector
 * @param vb The second vector
 * @return va < vb
 */
__APEX_INT_F_QUALS vbool vslt(vec32s va, vec32s vb)
{
  return __builtin_convertvector(va < vb, vbool);
}

/**
 * Vector Set Less than.
 * @param va The first vector
 * @param vb The second vector
 * @return va < vb
 */
__APEX_INT_F_QUALS vbool vslt(vec32u va, vec32u vb)
{
  return __builtin_convertvector(va < vb, vbool);
}

/**
 * @}
 *
 * @addtogroup velemInst Element Intrinsics
 * @brief Vector element intrinsics 
 * @{
 */

/**
 * Read vector element value at CU[i]
 * @param va The vector
 * @param i The index
 * @return va[i]
 */
__APEX_INT_F_QUALS bool vget(vbool va, int i)
{
  vec16s t = __builtin_convertvector(va, vec16s);
  return (bool)__builtin_apex_vget(t, i);
}

/**
 * Read vector element value at CU[i]
 * @param v The vector
 * @param i The index
 * @return va[i]
 */
__APEX_INT_F_QUALS int08s vget(vec08s v, int i)
{
  vec16s t = __builtin_convertvector(v, vec16s);
  return (int08s)__builtin_apex_vget(t, i);
}

/**
 * Read vector element value at CU[i]
 * @param v The vector
 * @param i The index
 * @return va[i]
 */
__APEX_INT_F_QUALS int08u vget(vec08u v, int i)
{
  vec16s t = __builtin_convertvector(v, vec16s);
  return (int08u)__builtin_apex_vget(t, i);
}

/**
 * Read vector element value at CU[i]
 * @param v The vector
 * @param i The index
 * @return va[i]
 */
__APEX_INT_F_QUALS int16s vget(vec16s v, int i)
{
  return (int16s)__builtin_apex_vget(v, i);
}

/**
 * Read vector element value at CU[i]
 * @param v The vector
 * @param i The index
 * @return va[i]
 */
__APEX_INT_F_QUALS int16u vget(vec16u v, int i)
{
  vec16s t = __builtin_convertvector(v, vec16s);
  return (int16u)__builtin_apex_vget(t, i);
}

/**
 * Read vector element value at CU[i]
 * @param va The vector
 * @param c The index
 * @return va[c]
 */
__APEX_INT_F_QUALS int32s vget(vec32s va, int c)
{
  vec16u vlo = (vec16u)__builtin_apex_vec32_get_lo(va);
  vec16s vhi = __builtin_apex_vec32_get_hi(va);
  unsigned los = (unsigned)vget(vlo, c);
  int his = (int)vget(vhi, c);
  return (int32s)(los | (his << 16));
}

/**
 * Read vector element value at CU[i]
 * @param va The vector
 * @param c The index
 * @return va[c]
 */
__APEX_INT_F_QUALS int32u vget(vec32u va, int c)
{
  vec32s ta = __builtin_convertvector(va, vec32s);
  return (int32u)vget(ta, c);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08s vput(vec08s s0, int08s s1, int i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_apex_vput(ta, (int)s1, i);
  return __builtin_convertvector(tb, vec08s);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08s vput(vec08s s0, int s1, int i)
{
  return vput(s0, (int08s)s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08s vput(vec08s s0, vec08s s1, int i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_convertvector(s1, vec16s);
  vec16s tc = __builtin_apex_vputv(ta, tb, i);
  return __builtin_convertvector(tc, vec08s);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08s vput(vec08s s0, vec08s s1, vec08s i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_convertvector(s1, vec16s);
  vec16s tc = __builtin_convertvector(i, vec16s);
  vec16s td = __builtin_apex_vputvv(ta, tb, tc);
  return __builtin_convertvector(td, vec08s);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08u vput(vec08u s0, int08u s1, int i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_apex_vput(ta, (int)s1, i);
  return __builtin_convertvector(tb, vec08u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08u vput(vec08u s0, int s1, int i)
{
  return vput(s0, (int08u)s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08u vput(vec08u s0, vec08u s1, int i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_convertvector(s1, vec16s);
  vec16s tc = __builtin_apex_vputv(ta, tb, i);
  return __builtin_convertvector(tc, vec08u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec08u vput(vec08u s0, vec08u s1, vec08u i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_convertvector(s1, vec16s);
  vec16s tc = __builtin_convertvector(i, vec16s);
  vec16s td = __builtin_apex_vputvv(ta, tb, tc);
  return __builtin_convertvector(td, vec08u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16s vput(vec16s s0, int16s s1, int i)
{
  return __builtin_apex_vput(s0, (int)s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16s vput(vec16s s0, int s1, int i)
{
  return vput(s0, (int16s)s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16s vput(vec16s s0, vec16s s1, int i)
{
  return __builtin_apex_vputv(s0, s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16s vput(vec16s s0, vec16s s1, vec16s i)
{
  return __builtin_apex_vputvv(s0, s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16u vput(vec16u s0, int16u s1, int i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = vput(ta, (int16s)s1, i);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16u vput(vec16u s0, int s1, int i)
{
  return vput(s0, (int16u)s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16u vput(vec16u s0, vec16u s1, int i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_convertvector(s1, vec16s);
  vec16s tc = vput(ta, tb, i);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec16u vput(vec16u s0, vec16u s1, vec16u i)
{
  vec16s ta = __builtin_convertvector(s0, vec16s);
  vec16s tb = __builtin_convertvector(s1, vec16s);
  vec16s tc = __builtin_convertvector(i, vec16s);
  vec16s td = vput(ta, tb, tc);
  return __builtin_convertvector(td, vec16u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec32s vput(vec32s s0, int32s s1, int i)
{
  vec16s vlo = __builtin_apex_vec32_get_lo(s0);
  vec16s vhi = __builtin_apex_vec32_get_hi(s0);
  vec16s rlo = vput(vlo, (int16s)s1, i);
  vec16s rhi = vput(vhi, (int16s)(s1 >> 16), i);
  return __builtin_apex_vec32_pack(rlo, rhi);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec32s vput(vec32s s0, vec32s s1, int i)
{
  vec16s s0lo = __builtin_apex_vec32_get_lo(s0);
  vec16s s0hi = __builtin_apex_vec32_get_hi(s0);
  vec16s s1lo = __builtin_apex_vec32_get_lo(s1);
  vec16s s1hi = __builtin_apex_vec32_get_hi(s1);
  vec16s rlo = vput(s0lo, s1lo, i);
  vec16s rhi = vput(s0hi, s1hi, i);
  return __builtin_apex_vec32_pack(rlo, rhi);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec32u vput(vec32u s0, int32u s1, int i)
{
  vec32s ta = __builtin_convertvector(s0, vec32s);
  vec32s tb = vput(ta, (int32s)s1, i);
  return __builtin_convertvector(tb, vec32u);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec32u vput(vec32u s0, int s1, int i)
{
  return vput(s0, (int32u)s1, i);
}

/**
 * Write vector element from vector s1 in vector s0 at CU[i]
 * @param s0 The base vector
 * @param s1 The new value
 * @param i The index
 * @return s0, with s1 at position i
 */
__APEX_INT_F_QUALS vec32u vput(vec32u s0, vec32u s1, int i)
{
  vec32s ta = __builtin_convertvector(s0, vec32s);
  vec32s tb = __builtin_convertvector(s1, vec32s);
  vec32s tc = vput(ta, tb, i);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * @}
 *
 * @addtogroup vmemInst Memory Intrinsics
 * @brief Vector memory intrinsics 
 * @{
 */

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec08s vload(const vec08s* restrict ptr, vec16s vi)
{
  int32s p = (int32s)ptr;
  vec16s t = __builtin_apex_vilb((vi) + (vec16s)p);
  return __builtin_convertvector(t, vec08s);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec08s vload(const vec08s* restrict ptr, vec08s vi)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  return vload(ptr, tvi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec08s vload(const vec08s* restrict ptr, vec08u vi)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  return vload(ptr, tvi2);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec08u vload(const vec08u* restrict ptr, vec16s vi)
{
  int32s p = (int32s)ptr;
  vec16u t = __builtin_apex_vilbu((vi) + (vec16s)p);
  return __builtin_convertvector(t, vec08u);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec08u vload(const vec08u* restrict ptr, vec08s vi)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  return vload(ptr, tvi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec08u vload(const vec08u* restrict ptr, vec08u vi)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  return vload(ptr, tvi2);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec16s vload(const vec16s* restrict ptr, vec16s vi)
{
  int32s p = (int32s)ptr;
  return __builtin_apex_vilw(vi + vi + (vec16s)p);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec16s vload(const vec16s* restrict ptr, vec08s vi)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  return vload(ptr, tvi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec16s vload(const vec16s* restrict ptr, vec08u vi)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  return vload(ptr, tvi2);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec16u vload(const vec16u* restrict ptr, vec16s vi)
{
  int32s p = (int32s)ptr;
  vec16s tr = __builtin_apex_vilw(vi + vi + (vec16s)p);
  return __builtin_convertvector(tr, vec16u);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec16u vload(const vec16u* restrict ptr, vec08s vi)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  return vload(ptr, tvi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec16u vload(const vec16u* restrict ptr, vec08u vi)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  return vload(ptr, tvi2);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec32s vload(const vec32s* restrict ptr, vec16s vi)
{
  int32s p = (int32s)ptr;
  vec16s lo = __builtin_apex_vilw(vi + vi + vi + vi + (vec16s)p);
  vec16s hi = __builtin_apex_vilw(vi + vi + vi + vi + (vec16s)p + (vec16s)2);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec32s vload(const vec32s* restrict ptr, vec08s vi)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  return vload(ptr, tvi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec32s vload(const vec32s* restrict ptr, vec08u vi)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  return vload(ptr, tvi2);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec32u vload(const vec32u* restrict ptr, vec16s vi)
{
  vec32s vr = vload((const vec32s *)ptr, vi);
  return __builtin_convertvector(vr, vec32u);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec32u vload(const vec32u* restrict ptr, vec08s vi)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  return vload(ptr, tvi);
}

/**
 * Load from vector address
 * @param ptr The base address
 * @param vi The vector index
 * @return ptr[vi]
 */
__APEX_INT_F_QUALS vec32u vload(const vec32u* restrict ptr, vec08u vi)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  return vload(ptr, tvi2);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec08s* restrict ptr, vec16s vi, vec08s v)
{
  int32s p = (int32s)ptr;
  vec16s t = __builtin_convertvector(v, vec16s);
  __builtin_apex_visb(t, (vi) + (vec16s)p);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec08s* restrict ptr, vec08s vi, vec08s v)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  vstore(ptr, tvi, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec08s* restrict ptr, vec08u vi, vec08s v)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  vstore(ptr, tvi2, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec08u* restrict ptr, vec16s vi, vec08u v)
{
  int32s p = (int32s)ptr;
  vec16s t = __builtin_convertvector(v, vec16s);
  __builtin_apex_visb(t, vi + (vec16s)p);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec08u* restrict ptr, vec08s vi, vec08u v)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  vstore(ptr, tvi, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec08u* restrict ptr, vec08u vi, vec08u v)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  vstore(ptr, tvi2, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec16s* restrict ptr, vec16s vi, vec16s v)
{
  int32s p = (int32s)ptr;
  __builtin_apex_visw(v, vi + vi + (vec16s)p);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec16s* restrict ptr, vec08s vi, vec16s v)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  vstore(ptr, tvi, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec16s* restrict ptr, vec08u vi, vec16s v)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  vstore(ptr, tvi2, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec16u* restrict ptr, vec16s vi, vec16u v)
{
  int32s p = (int32s)ptr;
  vec16s tv = __builtin_convertvector(v, vec16s);
  __builtin_apex_visw(tv, vi + vi + (vec16s)p);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec16u* restrict ptr, vec08s vi, vec16u v)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  vstore(ptr, tvi, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec16u* restrict ptr, vec08u vi, vec16u v)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  vstore(ptr, tvi2, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec32s* restrict ptr, vec16s vi, vec32s v)
{
  int32s p = (int32s)ptr;
  vec16s vlo = __builtin_apex_vec32_get_lo(v);
  vec16s vhi = __builtin_apex_vec32_get_hi(v);
  __builtin_apex_visw(vlo, vi + vi + vi + vi + (vec16s)p);
  __builtin_apex_visw(vhi, vi + vi + vi + vi + (vec16s)p + (vec16s)2);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec32s* restrict ptr, vec08s vi, vec32s v)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  vstore(ptr, tvi, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec32s* restrict ptr, vec08u vi, vec32s v)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  vstore(ptr, tvi2, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec32u* restrict ptr, vec16s vi, vec32u v)
{
  vec32s tv = __builtin_convertvector(v, vec32s);
  vstore((vec32s*)ptr, vi, tv);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec32u* restrict ptr, vec08s vi, vec32u v)
{
  vec16s tvi = __builtin_convertvector(vi, vec16s);
  vstore(ptr, tvi, v);
}

/**
 * Store a value to a vector address
 * @param ptr The base address
 * @param vi The vector index
 * @param v The value that will be written
 */
__APEX_INT_F_QUALS void vstore(vec32u* restrict ptr, vec08u vi, vec32u v)
{
  vec16u tvi = __builtin_convertvector(vi, vec16u);
  vec16s tvi2 = __builtin_convertvector(tvi, vec16s);
  vstore(ptr, tvi2, v);
}

/**
 * @}
 *
 * @addtogroup vspecshiftInst Specialized Shift Intrinsics
 * @brief Vector specialized shift intrinsics 
 * @{
 */

/**
 * Vector Shift Left (Logical) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param vs The shift amount
 */
__APEX_INT_F_QUALS void vsllx(vec16s* restrict vc, vec16s* restrict vd, vec16s va, vec16s vb, vec16s vs)
{
  vec32s ta = __builtin_apex_vec32_pack(va, vb);
  vec32s tb = __builtin_convertvector(vs, vec32s);
  vec32s tc = ta << tb;
  *vc = __builtin_apex_vec32_get_lo(tc);
  *vd = __builtin_apex_vec32_get_hi(tc);
}

/**
 * Vector Shift Right (Arithmetic) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param vs The shift amount
 */
__APEX_INT_F_QUALS void vsrax(vec16s* restrict vc, vec16s* restrict vd, vec16s va, vec16s vb, vec16s vs)
{
  vec32s ta = __builtin_apex_vec32_pack(va, vb);
  vec32s tb = __builtin_convertvector(vs, vec32s);
  vec32s tc = ta >> tb;
  *vc = __builtin_apex_vec32_get_lo(tc);
  *vd = __builtin_apex_vec32_get_hi(tc);
}

/**
 * Vector Shift Right (Logical) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param vs The shift amount
 */
__APEX_INT_F_QUALS void vsrlx(vec16s* restrict vc, vec16s* restrict vd, vec16s va, vec16s vb, vec16s vs)
{
  vec32s ta = __builtin_apex_vec32_pack(va, vb);
  vec32s tb = __builtin_convertvector(vs, vec32s);
  vec32u tau = __builtin_convertvector(ta, vec32u);
  vec32u tbu = __builtin_convertvector(tb, vec32u);
  vec32u tcu = tau >> tbu;
  vec32s tc = __builtin_convertvector(tcu, vec32s);
  *vc = __builtin_apex_vec32_get_lo(tc);
  *vd = __builtin_apex_vec32_get_hi(tc);
}

/**
 * Vector Shift Left (Logical) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param vs The shift amount
 */
__APEX_INT_F_QUALS void vsllx(vec16u* restrict vc, vec16u* restrict vd, vec16u va, vec16u vb, vec16u vs)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s ts = __builtin_convertvector(vs, vec16s);
  vsllx((vec16s*)vc, (vec16s*)vd, ta, tb, ts);
}

/**
 * Vector Shift Right (Arithmetic) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param vs The shift amount
 */
__APEX_INT_F_QUALS void vsrax(vec16u* restrict vc, vec16u* restrict vd, vec16u va, vec16u vb, vec16u vs)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s ts = __builtin_convertvector(vs, vec16s);
  vsrax((vec16s*)vc, (vec16s*)vd, ta, tb, ts);
}

/**
 * Vector Shift Right (Logical) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param vs The shift amount
 */
__APEX_INT_F_QUALS void vsrlx(vec16u* restrict vc, vec16u* restrict vd, vec16u va, vec16u vb, vec16u vs)
{
  vec16s ta = __builtin_convertvector(va, vec16s);
  vec16s tb = __builtin_convertvector(vb, vec16s);
  vec16s ts = __builtin_convertvector(vs, vec16s);
  vsrlx((vec16s*)vc, (vec16s*)vd, ta, tb, ts);
}

/**
 * Vector Shift Right (Arithmetic) of vec16 pairs
 * @param vc [out] Pointer to the lo part
 * @param vd [out] Pointer to the hi part
 * @param va The lo part
 * @param vb The hi part
 * @param s The shift amount
 */
__APEX_INT_F_QUALS void vsr(vec16u* restrict vc, vec16u* restrict vd, vec16u va, vec16u vb, int s)
{
  vec16s ta  = __builtin_convertvector(va, vec16s);
  vec16s tb  = __builtin_convertvector(vb, vec16s);
  vec32s tab = __builtin_apex_vec32_pack(ta, tb);
  vec32s tc = tab >> (vec32s)s;
  vec16s tcl = __builtin_apex_vec32_get_lo(tc);
  vec16s tch = __builtin_apex_vec32_get_hi(tc);
  *vc = __builtin_convertvector(tcl, vec16u);
  *vd = __builtin_convertvector(tch, vec16u);
}

/**
 * @}
 *
 * @addtogroup vspecmulInst Specialized Multiplication Intrinsics
 * @brief Vector specialized multiplication intrinsics 
 * @{
 */

/**
 * Vector multiplication unsigned-low unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_ulul(vec16s a, vec16s b)
{
  vec16s tc = __builtin_apex_vmul_lulu(a, b);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-low unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_ulul(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  return vmul_ulul(ta, tb);
}

/**
 * Vector multiplication unsigned-low unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(unsigned-high)
 */
__APEX_INT_F_QUALS vec16u vmul_uluh(vec16s a, vec16s b)
{
  vec16s tc = __builtin_apex_vmul_hulu(b, a);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-low unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(unsigned-high)
 */
__APEX_INT_F_QUALS vec16u vmul_uluh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  return vmul_uluh(ta, tb);
}

/**
 * Vector multiplication unsigned-low signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16s vmul_ulsh(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hslu(b, a);
}

/**
 * Vector multiplication unsigned-low signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_ulsh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_ulsh(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-high unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_uhul(vec16s a, vec16s b)
{
  vec16s tc = __builtin_apex_vmul_hulu(a, b);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-high unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_uhul(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  return vmul_uhul(ta, tb);
}

/**
 * Vector multiplication unsigned-high unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(unsigned-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_uhuh(vec16s a, vec16s b)
{
  vec16s tc = __builtin_apex_vmul_huhu(a, b);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-high unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(unsigned-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_uhuh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  return vmul_uhuh(ta, tb);
}

/**
 * Vector multiplication unsigned-high signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16s vmul_uhsh(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hshu(b, a);
}

/**
 * Vector multiplication unsigned-high signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_uhsh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_uhsh(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-high unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16s vmul_shul(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hslu(a, b);
}

/**
 * Vector multiplication signed-high unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_shul(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_shul(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-high unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(unsigned-high) 
 */
__APEX_INT_F_QUALS vec16s vmul_shuh(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hshu(a, b);
}

/**
 * Vector multiplication signed-high unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(unsigned-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_shuh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_shuh(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-high signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16s vmul_shsh(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hshs(a, b);
}

/**
 * Vector multiplication signed-high signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_shsh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_shsh(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-low unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-low) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16s vmul_slul(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_lslu(a, b);
}

/**
 * Vector multiplication signed-low unsigned-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-low) * vb(unsigned-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_slul(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_slul(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-low signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(signed-low) 
 */
__APEX_INT_F_QUALS vec16s vmul_ulsl(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_lslu(b, a);
}

/**
 * Vector multiplication unsigned-low signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-low) * vb(signed-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_ulsl(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_ulsl(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication unsigned-high signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(signed-low) 
 */
__APEX_INT_F_QUALS vec16s vmul_uhsl(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_huls(a, b);
}

/**
 * Vector multiplication unsigned-high signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(unsigned-high) * vb(signed-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_uhsl(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_uhsl(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-low signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-lo) * vb(signed-lo) 
 */
__APEX_INT_F_QUALS vec16s vmul_slsl(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_lsls(b, a);
}

/**
 * Vector multiplication signed-low signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-lo) * vb(signed-lo) 
 */
__APEX_INT_F_QUALS vec16u vmul_slsl(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_slsl(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-high signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(signed-low) 
 */
__APEX_INT_F_QUALS vec16s vmul_shsl(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hsls(a, b);
}

/**
 * Vector multiplication signed-high signed-low
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-high) * vb(signed-low) 
 */
__APEX_INT_F_QUALS vec16u vmul_shsl(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_shsl(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-low unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-low) * vb(unsigned-high) 
 */
__APEX_INT_F_QUALS vec16s vmul_sluh(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_huls(b, a);
}

/**
 * Vector multiplication signed-low unsigned-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-low) * vb(unsigned-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_sluh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_sluh(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector multiplication signed-low signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-low) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16s vmul_slsh(vec16s a, vec16s b)
{
  return __builtin_apex_vmul_hsls(b, a);
}

/**
 * Vector multiplication signed-low signed-high
 * @param a The first vector
 * @param b The second vector
 * @return va(signed-low) * vb(signed-high) 
 */
__APEX_INT_F_QUALS vec16u vmul_slsh(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmul_slsh(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
* Vector 16 x 16 -> 32-bit multiplication
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmul(vec16s* restrict h, vec16u* restrict l, vec16s a, vec16s b)
{
  vec16u a0b0 = vmul_ulul(a, b);
  vec16s a1b1 = vmul_shsh(a, b);
  *l = a0b0;
  *h = a1b1;
  vec16s a1b0 = vmul_shul(a, b); vacm(h, l, a1b0);
  vec16s a0b1 = vmul_ulsh(a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit multiplication
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmul(vec16s* restrict h, vec16u* restrict l, vec16u a, vec16s b)
{
  vec16u a0b0 = vmul_ulul(a, (vec16u)b);
  vec16s a1b1 = vmul_uhsh((vec16s)a, b);
  *l = a0b0;
  *h = a1b1;
  vec16u a1b0 = vmul_uhul(a, (vec16u)b); vacm(h, l, a1b0);
  vec16s a0b1 = vmul_ulsh((vec16s)a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit multiplication
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmul(vec16s* restrict h, vec16u* restrict l, vec16s a, vec16u b)
{
  vmul(h, l, b, a);
}

/**
* Vector 16 x 16 -> 32-bit multiplication
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmul(vec16u* restrict h, vec16u* restrict l, vec16u a, vec16u b)
{
  vec16u a0b0 = vmul_ulul(a, b);
  vec16u a1b1 = vmul_uhuh(a, b);
  *l = a0b0;
  *h = a1b1;
  vec16u a1b0 = vmul_uhul(a, b); vacm(h, l, a1b0);
  vec16u a0b1 = vmul_uluh(a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit mult-add
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmac(vec16s* restrict h, vec16u* restrict l, vec16s a, vec16s b)
{
  vec16u a0b0 = vmul_ulul(a, b); vacl(h, l, a0b0);
  vec16s a1b1 = vmul_shsh(a, b); *h += a1b1;
  vec16s a1b0 = vmul_shul(a, b); vacm(h, l, a1b0);
  vec16s a0b1 = vmul_ulsh(a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit mult-add
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmac(vec16s* restrict h, vec16u* restrict l, vec16u a, vec16s b)
{
  vec16u a0b0 = vmul_ulul(a, (vec16u)b); vacl(h, l, a0b0);
  vec16s a1b1 = vmul_uhsh((vec16s)a, b); *h += a1b1;
  vec16u a1b0 = vmul_uhul(a, (vec16u)b); vacm(h, l, a1b0);
  vec16s a0b1 = vmul_ulsh((vec16s)a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit mult-add
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmac(vec16s* restrict h, vec16u* restrict l, vec16s a, vec16u b)
{
  vmac(h, l, b, a);
}

/**
* Vector 16 x 16 -> 32-bit mult-add
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
*/
__APEX_INT_F_QUALS void vmac(vec16u* restrict h, vec16u* restrict l, vec16u a, vec16u b)
{
  vec16u a0b0 = vmul_ulul(a, b); vacl(h, l, a0b0);
  vec16u a1b1 = vmul_uhuh(a, b); *h += a1b1;
  vec16u a1b0 = vmul_uhul(a, b); vacm(h, l, a1b0);
  vec16u a0b1 = vmul_uluh(a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit mult-add with src
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
* @param ch High 16-bit of addend input vector
* @param cl Low 16-bit of addend input vector
*/
__APEX_INT_F_QUALS void vmad(vec16s* restrict h, vec16u* restrict l, vec16s a, vec16s b, vec16s ch, vec16u cl)
{
  *h = ch;
  *l = cl;
  vec16u a0b0 = vmul_ulul(a, b); vacl(h, l, a0b0);
  vec16s a1b1 = vmul_shsh(a, b); *h += a1b1;
  vec16s a1b0 = vmul_shul(a, b); vacm(h, l, a1b0);
  vec16s a0b1 = vmul_ulsh(a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit mult-add with src
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
* @param ch High 16-bit of addend input vector
* @param cl Low 16-bit of addend input vector
*/
__APEX_INT_F_QUALS void vmad(vec16s* restrict h, vec16u* restrict l, vec16u a, vec16s b, vec16s ch, vec16u cl)
{
  *h = ch;
  *l = cl;
  vec16u a0b0 = vmul_ulul(a, (vec16u)b); vacl(h, l, a0b0);
  vec16s a1b1 = vmul_uhsh((vec16s)a, b); *h += a1b1;
  vec16u a1b0 = vmul_uhul(a, (vec16u)b); vacm(h, l, a1b0);
  vec16s a0b1 = vmul_ulsh((vec16s)a, b); vacm(h, l, a0b1);
}

/**
* Vector 16 x 16 -> 32-bit mult-add with src
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
* @param ch High 16-bit of addend input vector
* @param cl Low 16-bit of addend input vector
*/
__APEX_INT_F_QUALS void vmad(vec16s* restrict h, vec16u* restrict l, vec16s a, vec16u b, vec16s ch, vec16u cl)
{
  vmad(h, l, b, a, ch, cl);
}

/**
* Vector 16 x 16 -> 32-bit mult-add with src
* @param h [out] Pointer to output vector for high 16-bit result
* @param l [out] Pointer to output vector for low 16-bit result
* @param a First input vector
* @param b Second input vector
* @param ch High 16-bit of addend input vector
* @param cl Low 16-bit of addend input vector
*/
__APEX_INT_F_QUALS void vmad(vec16u* restrict h, vec16u* restrict l, vec16u a, vec16u b, vec16u ch, vec16u cl)
{
  *h = ch;
  *l = cl;
  vec16u a0b0 = vmul_ulul(a, b); vacl(h, l, a0b0);
  vec16u a1b1 = vmul_uhuh(a, b); *h += a1b1;
  vec16u a1b0 = vmul_uhul(a, b); vacm(h, l, a1b0);
  vec16u a0b1 = vmul_uluh(a, b); vacm(h, l, a0b1);
}

/**
 * @}
 *
 * @addtogroup vswapInst Swap Intrinsics
 * @brief Vector swap intrinsics 
 * @{
 */
/**
 * Vector select
 * @param a Input first vector
 * @param b Input second vector
 * @param c Input condition vector
 * @return vc ? va : vb 
 */
__APEX_INT_F_QUALS vec16s vselect(vec16s a, vec16s b, vbool c)
{
  return __builtin_apex_vsel_16(a, b, c);
}

/**
 * Vector select
 * @param a Input first vector
 * @param b Input second vector
 * @param c Input condition vector
 * @return vc ? va : vb 
 */
__APEX_INT_F_QUALS vec16u vselect(vec16u a, vec16u b, vbool c)
{
  return (vec16u)vselect((vec16s)a, (vec16s)b, c);
}

/**
 * Vector select
 * @param a Input first vector
 * @param b Input second vector
 * @param c Input condition vector
 * @return vc ? va : vb 
 */
__APEX_INT_F_QUALS vec16s vselect(vec08s a, vec08s b, vbool c)
{
  vec08s res = __builtin_apex_vsel_08(a, b, c);
  return (vec16s)res;
}

/**
 * Vector select
 * @param a Input first vector
 * @param b Input second vector
 * @param c Input condition vector
 * @return vc ? va : vb 
 */
__APEX_INT_F_QUALS vec16u vselect(vec08u a, vec08u b, vbool c)
{
  return (vec16u)vselect((vec16u)a, (vec16u)b, c);
}

/**
 * Vector select
 * @param a Input first vector
 * @param b Input second vector
 * @param c Input condition vector
 * @return vc ? va : vb 
 */
__APEX_INT_F_QUALS vec32s vselect(vec32s a, vec32s b, vbool c)
{
  return __builtin_apex_vsel_32(a, b, c);
}

/**
 * Vector select
 * @param a Input first vector
 * @param b Input second vector
 * @param c Input condition vector
 * @return vc ? va : vb 
 */
__APEX_INT_F_QUALS vec32u vselect(vec32u a, vec32u b, vbool c)
{
  return (vec32u)vselect((vec32s)a, (vec32s)b, c);
}

/**
 * Vector conditional swap
 * @param a The first input vector
 * @param b The second input vector
 * @param c Input condition vector
 * @return if(vc) swap(va,vb)
 */
__APEX_INT_F_QUALS void vswap(vec16s* restrict a, vec16s* restrict b, vbool c)
{
  __builtin_apex_vswap(a, b, c);
}

/**
 * Vector conditional swap
 * @param a The first input vector
 * @param b The second input vector
 * @param c Input condition vector
 * @return if(vc) swap(va,vb)
 */
__APEX_INT_F_QUALS void vswap(vec16u* restrict a, vec16u* restrict b, vbool c)
{
  vswap((vec16s*)a, (vec16s*)b, c);
}

/**
 * Vector conditional swap
 * @param a The first input vector
 * @param b The second input vector
 * @param c Input condition vector
 * @return if(vc) swap(va,vb)
 */
__APEX_INT_F_QUALS void vswap(vec32s* restrict a, vec32s* restrict b, vbool c)
{
  vec32s la = *a;
  vec32s lb = *b;
  vec16s alo = __builtin_apex_vec32_get_lo(la);
  vec16s ahi = __builtin_apex_vec32_get_hi(la);
  vec16s blo = __builtin_apex_vec32_get_lo(lb);
  vec16s bhi = __builtin_apex_vec32_get_hi(lb);
  vswap(&alo, &blo, c);
  vswap(&ahi, &bhi, c);
  la = __builtin_apex_vec32_pack(alo, ahi);
  lb = __builtin_apex_vec32_pack(blo, bhi);
  *a = la;
  *b = lb;
}

/**
 * Vector conditional swap
 * @param a The first input vector
 * @param b The second input vector
 * @param c Input condition vector
 * @return if(vc) swap(va,vb)
 */
__APEX_INT_F_QUALS void vswap(vec32u* restrict a, vec32u* restrict b, vbool c)
{
  vswap((vec32s*)a, (vec32s*)b, c);
}

/**
 * @}
 *
 * @addtogroup vrotInst Move/Rotate Intrinsics
 * @brief Vector move/rotate intrinsics 
 * @{
 */
/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec16s vml(vec16s a, vec16s b)
{
  return __builtin_apex_vmrlv(a, b);
}
 
/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec16u vml(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vml(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec08s vml(vec08s a, vec08s b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vml(ta, tb);
  return __builtin_convertvector(tc, vec08s);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec08u vml(vec08u a, vec08u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vml(ta, tb);
  return __builtin_convertvector(tc, vec08u);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec32s vml(vec32s a, vec32s b)
{
  vec16s a_lo = __builtin_apex_vec32_get_lo(a);
  vec16s a_hi = __builtin_apex_vec32_get_hi(a);
  vec16s b_lo = __builtin_apex_vec32_get_lo(b);
  vec16s b_hi = __builtin_apex_vec32_get_hi(b);
  vec16s lo = vml(a_lo, b_lo);
  vec16s hi = vml(a_hi, b_hi);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec32u vml(vec32u a, vec32u b)
{
  vec32s ta = __builtin_convertvector(a, vec32s);
  vec32s tb = __builtin_convertvector(b, vec32s);
  vec32s tc = vml(ta, tb);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec16s vmsl(vec16s a, vec16s b)
{
  return vml(a, b);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec16u vmsl(vec16u a, vec16u b)
{
  return vml(a, b);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec08s vmsl(vec08s a, vec08s b)
{
  return vml(a, b);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec08u vmsl(vec08u a, vec08u b)
{
  return vml(a, b);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec32s vmsl(vec32s a, vec32s b)
{
  return vml(a, b);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec32u vmsl(vec32u a, vec32u b)
{
  return vml(a, b);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=0
 */
__APEX_INT_F_QUALS vec16s vmsl(vec16s a)
{
  return __builtin_apex_vmrlr(a, 0);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=0
 */
__APEX_INT_F_QUALS vec16u vmsl(vec16u a)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = vmsl(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=0
 */
__APEX_INT_F_QUALS vec08s vmsl(vec08s a)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = vmsl(ta);
  return __builtin_convertvector(tb, vec08s);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=0
 */
__APEX_INT_F_QUALS vec08u vmsl(vec08u a)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = vmsl(ta);
  return __builtin_convertvector(tb, vec08u);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=0
 */
__APEX_INT_F_QUALS vec32s vmsl(vec32s a)
{
  vec16s a_lo = __builtin_apex_vec32_get_lo(a);
  vec16s a_hi = __builtin_apex_vec32_get_hi(a);
  vec16s lo = vmsl(a_lo);
  vec16s hi = vmsl(a_hi);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Vector element shift left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=0
 */
__APEX_INT_F_QUALS vec32u vmsl(vec32u a)
{
  vec32s ta = __builtin_convertvector(a, vec32s);
  vec32s tb = vmsl(ta);
  return __builtin_convertvector(tb, vec32u);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec16s vmrl(vec16s a, vec16s b)
{
  return vml(a, b);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec16u vmrl(vec16u a, vec16u b)
{
  return vml(a, b);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec08s vmrl(vec08s a, vec08s b)
{
  return vml(a, b);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec08u vmrl(vec08u a, vec08u b)
{
  return vml(a, b);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec32s vmrl(vec32s a, vec32s b)
{
  return vml(a, b);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift left by one CU; va[31]=vb[0]
 */
__APEX_INT_F_QUALS vec32u vmrl(vec32u a, vec32u b)
{
  return vml(a, b);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=va[0]
 */
__APEX_INT_F_QUALS vec16s vmrl(vec16s a)
{
  return vml(a, a);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=va[0]
 */
__APEX_INT_F_QUALS vec16u vmrl(vec16u a)
{
  return vml(a, a);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=va[0]
 */
__APEX_INT_F_QUALS vec08s vmrl(vec08s a)
{
  return vml(a, a);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=va[0]
 */
__APEX_INT_F_QUALS vec08u vmrl(vec08u a)
{
  return vml(a, a);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=va[0]
 */
__APEX_INT_F_QUALS vec32s vmrl(vec32s a)
{
  return vml(a, a);
}

/**
 * Vector element rotate left
 * @param a Output vector and first input vector
 * @return va shift left by one CU; va[31]=va[0]
 */
__APEX_INT_F_QUALS vec32u vmrl(vec32u a)
{
  return vml(a, a);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec16s vmr(vec16s a, vec16s b)
{
  return __builtin_apex_vmrrv(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec16u vmr(vec16u a, vec16u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmr(ta, tb);
  return __builtin_convertvector(tc, vec16u);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec08s vmr(vec08s a, vec08s b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmr(ta, tb);
  return __builtin_convertvector(tc, vec08s);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec08u vmr(vec08u a, vec08u b)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = __builtin_convertvector(b, vec16s);
  vec16s tc = vmr(ta, tb);
  return __builtin_convertvector(tc, vec08u);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec32s vmr(vec32s a, vec32s b)
{
  vec16s a_lo = __builtin_apex_vec32_get_lo(a);
  vec16s a_hi = __builtin_apex_vec32_get_hi(a);
  vec16s b_lo = __builtin_apex_vec32_get_lo(b);
  vec16s b_hi = __builtin_apex_vec32_get_hi(b);
  vec16s lo = vmr(a_lo, b_lo);
  vec16s hi = vmr(a_hi, b_hi);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec32u vmr(vec32u a, vec32u b)
{
  vec32s ta = __builtin_convertvector(a, vec32s);
  vec32s tb = __builtin_convertvector(b, vec32s);
  vec32s tc = vmr(ta, tb);
  return __builtin_convertvector(tc, vec32u);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec16s vmsr(vec16s a, vec16s b)
{
  return vmr(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec16u vmsr(vec16u a, vec16u b)
{
  return vmr(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec08s vmsr(vec08s a, vec08s b)
{
  return vmr(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec08u vmsr(vec08u a, vec08u b)
{
  return vmr(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec32s vmsr(vec32s a, vec32s b)
{
  return vmr(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec32u vmsr(vec32u a, vec32u b)
{
  return vmr(a, b);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=0
 */
__APEX_INT_F_QUALS vec16s vmsr(vec16s a)
{
  return __builtin_apex_vmrrr(a, 0);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=0
 */
__APEX_INT_F_QUALS vec16u vmsr(vec16u a)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = vmsr(ta);
  return __builtin_convertvector(tb, vec16u);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=0
 */
__APEX_INT_F_QUALS vec08s vmsr(vec08s a)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = vmsr(ta);
  return __builtin_convertvector(tb, vec08s);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=0
 */
__APEX_INT_F_QUALS vec08u vmsr(vec08u a)
{
  vec16s ta = __builtin_convertvector(a, vec16s);
  vec16s tb = vmsr(ta);
  return __builtin_convertvector(tb, vec08u);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=0
 */
__APEX_INT_F_QUALS vec32s vmsr(vec32s a)
{
  vec16s a_lo = __builtin_apex_vec32_get_lo(a);
  vec16s a_hi = __builtin_apex_vec32_get_hi(a);
  vec16s lo = vmsr(a_lo);
  vec16s hi = vmsr(a_hi);
  return __builtin_apex_vec32_pack(lo, hi);
}

/**
 * Vector element shift right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=0
 */
__APEX_INT_F_QUALS vec32u vmsr(vec32u a)
{
  vec32s ta = __builtin_convertvector(a, vec32s);
  vec32s tb = vmsr(ta);
  return __builtin_convertvector(tb, vec32u);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec16s vmrr(vec16s a, vec16s b)
{
  return vmr(a, b);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec16u vmrr(vec16u a, vec16u b)
{
  return vmr(a, b);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec08s vmrr(vec08s a, vec08s b)
{
  return vmr(a, b);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec08u vmrr(vec08u a, vec08u b)
{
  return vmr(a, b);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec32s vmrr(vec32s a, vec32s b)
{
  return vmr(a, b);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @param b The second vector
 * @return va shift right by one CU; va[0]=vb[31]
 */
__APEX_INT_F_QUALS vec32u vmrr(vec32u a, vec32u b)
{
  return vmr(a, b);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=va[31]
 */
__APEX_INT_F_QUALS vec16s vmrr(vec16s a)
{
  return vmr(a, a);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=va[31]
 */
__APEX_INT_F_QUALS vec16u vmrr(vec16u a)
{
  return vmr(a, a);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=va[31]
 */
__APEX_INT_F_QUALS vec08s vmrr(vec08s a)
{
  return vmr(a, a);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=va[31]
 */
__APEX_INT_F_QUALS vec08u vmrr(vec08u a)
{
  return vmr(a, a);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=va[31]
 */
__APEX_INT_F_QUALS vec32s vmrr(vec32s a)
{
  return vmr(a, a);
}

/**
 * Vector element rotate right
 * @param a Output vector and first input vector
 * @return va shift right by one CU; va[0]=va[31]
 */
__APEX_INT_F_QUALS vec32u vmrr(vec32u a)
{
  return vmr(a, a);
}

/**
 * Vector splate hi
 * @param i Input integer
 * @return vector of high 16-bit of i
 */
__APEX_INT_F_QUALS vec16u vextract_hi(int i)
{
  return (vec16u)(i >> 16);
}

/**
 * Vector splate lo
 * @param i Input integer
 * @return vector of low 16-bit of i
 */
__APEX_INT_F_QUALS vec16u vextract_lo(int i)
{
  return (vec16u)(i & 0xffff);
}

/**
 * @}
 */

/////////////////////////////////////////////////////
// Other Intrinsics                                //
/////////////////////////////////////////////////////

#include <apex/instructions.hpp>

/////////////////////////////////////////////////////
// End of Other Intrinsics                         //
/////////////////////////////////////////////////////


/////////////////////////////////////////////////////
// Handle functions with reference parameters      //
/////////////////////////////////////////////////////

#ifndef __cplusplus

#ifdef __OPENCL_C_VERSION__
  // TODO: find a way to implement some instances of vadd, vsub,
  //       vaddx, vsubx, vacl, vacm, vach, vslo, vsro, vsllx, vsrax,
  //       vsr, vsrlx, and vswap without using variadic macros.
#else

// vadd
#define __vadd2(a,b)        vadd((a), (b))
#define __vadd3(a,b,c)      vadd((a), (b), &(c))
#define vadd(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vadd3, __vadd2)(__VA_ARGS__)

// vsub
#define __vsub2(a,b)        vsub((a), (b))
#define __vsub3(a,b,c)      vsub((a), (b), &(c))
#define vsub(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vsub3, __vsub2)(__VA_ARGS__)

// vaddx
#define __vaddx3(a,b,c)     vaddx((a), (b), (c))
#define __vaddx4(a,b,c,d)   vaddx((a), (b), (c), &(d))
#define vaddx(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __vaddx4, __vaddx3)(__VA_ARGS__)

// vsubx
#define __vsubx3(a,b,c)     vsubx((a), (b), (c))
#define __vsubx4(a,b,c,d)   vsubx((a), (b), (c), &(d))
#define vsubx(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __vsubx4, __vsubx3)(__VA_ARGS__)

// vacl
#define __vacl2(a, c)    vacl(&(a), (c))
#define __vacl3(a, b, c) vacl(&(a), &(b), (c))
#define vacl(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vacl3, __vacl2)(__VA_ARGS__)

// vacm
#define __vacm2(a, c)    vacm(&(a), (c))
#define __vacm3(a, b, c) vacm(&(a), &(b), (c))
#define vacm(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vacm3, __vacm2)(__VA_ARGS__)

// vach
#define __vach2(a, c)    vach(&(a), (c))
#define __vach3(a, b, c) vach(&(a), &(b), (c))
#define vach(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vach3, __vach2)(__VA_ARGS__)

// vslo
#define __vslo2(a, b)    vslo((a), (b))
#define __vslo3(a, b, c) vslo((a), (b), &(c))
#define vslo(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vslo3, __vslo2)(__VA_ARGS__)

// vsro
#define __vsro2(a, b)    vsro((a), (b))
#define __vsro3(a, b, c) vsro((a), (b), &(c))
#define vsro(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __none, __vsro3, __vsro2)(__VA_ARGS__)

// Specialized shifts
#define __vsllx(a, b, c ,d, e) vsllx(&(a), &(b), (c), (d), (e))
#define vsllx(...) __vsllx(__VA_ARGS__)

#define __vsrax(a, b, c ,d, e) vsrax(&(a), &(b), (c), (d), (e))
#define vsrax(...) __vsrax(__VA_ARGS__)

// vsr() which takes 5 parameters, alias to vsrax(i)
#define __vsr2(a, b) vsr(a, b)
#define __vsr5(a, b, c, d, e) vsr(&(a), &(b), (c), (d), (e))
#define vsr(...) __GET_MACRO_APEX_VSR(__VA_ARGS__, __vsr5, __none, __none, __vsr2)(__VA_ARGS__)

#define __vsrlx(a, b, c ,d, e) vsrlx(&(a), &(b), (c), (d), (e))
#define vsrlx(...) __vsrlx(__VA_ARGS__)

// Swap functions
#define __vswap(a, b, c) vswap(&(a), &(b), (c))
#define vswap(...) __vswap(__VA_ARGS__)

// vmul
#define __vmul2(a, b) vmul((a), (b))
#define __vmul4(a, b, c, d) vmul(&(a), &(b), (c), (d))
#define vmul(...) __GET_MACRO_APEX_CARRY(__VA_ARGS__, __vmul4, __none, __vmul2)(__VA_ARGS__)

// vmac
#define __vmac(a, b, c ,d) vmac(&(a), &(b), (c), (d))
#define vmac(...) __vmac(__VA_ARGS__)

// vmad
#define __vmad(a, b, c ,d, e, f) vmad(&(a), &(b), (c), (d), (e), (f))
#define vmad(...) __vmad(__VA_ARGS__)
#endif /* __OPENCL_C_VERSION__ */

#else // else, we are in C++ mode

// vadd
__APEX_INT_F_QUALS vec16s vadd(vec16s va, vec16s vb, vbool& restrict vf)
{
  return vadd(va, vb, &vf);
}

__APEX_INT_F_QUALS vec16u vadd(vec16u va, vec16u vb, vbool& restrict vf)
{
  return vadd(va, vb, &vf);
}

__APEX_INT_F_QUALS vec32s vadd(vec32s va, vec32s vb, vbool& restrict vf)
{
  return vadd(va, vb, &vf);
}

__APEX_INT_F_QUALS vec32u vadd(vec32u va, vec32u vb, vbool& restrict vf)
{
  return vadd(va, vb, &vf);
}

// vsub
__APEX_INT_F_QUALS vec16s vsub(vec16s va, vec16s vb, vbool& restrict vf)
{
  return vsub(va, vb, &vf);
}

__APEX_INT_F_QUALS vec16u vsub(vec16u va, vec16u vb, vbool& restrict vf)
{
  return vsub(va, vb, &vf);
}

__APEX_INT_F_QUALS vec32s vsub(vec32s va, vec32s vb, vbool& restrict vf)
{
  return vsub(va, vb, &vf);
}

__APEX_INT_F_QUALS vec32u vsub(vec32u va, vec32u vb, vbool& restrict vf)
{
  return vsub(va, vb, &vf);
}

// vaddx
__APEX_INT_F_QUALS vec16s vaddx(vec16s va, vec16s vb, vbool vc, vbool& restrict vf)
{
  return vaddx(va, vb, vc, &vf);
}

__APEX_INT_F_QUALS vec16u vaddx(vec16u va, vec16u vb, vbool vc, vbool& restrict vf)
{
  return vaddx(va, vb, vc, &vf);
}

__APEX_INT_F_QUALS vec32s vaddx(vec32s va, vec32s vb, vbool vc, vbool& restrict vf)
{
  return vaddx(va, vb, vc, &vf);
}

__APEX_INT_F_QUALS vec32u vaddx(vec32u va, vec32u vb, vbool vc, vbool& restrict vf)
{
  return vaddx(va, vb, vc, &vf);
}

// vsubx
__APEX_INT_F_QUALS vec16s vsubx(vec16s va, vec16s vb, vbool vc, vbool& restrict vf)
{
  return vsubx(va, vb, vc, &vf);
}

__APEX_INT_F_QUALS vec16u vsubx(vec16u va, vec16u vb, vbool vc, vbool& restrict vf)
{
  return vsubx(va, vb, vc, &vf);
}

__APEX_INT_F_QUALS vec32s vsubx(vec32s va, vec32s vb, vbool vc, vbool& restrict vf)
{
  return vsubx(va, vb, vc, &vf);
}

__APEX_INT_F_QUALS vec32u vsubx(vec32u va, vec32u vb, vbool vc, vbool& restrict vf)
{
  return vsubx(va, vb, vc, &vf);
}

// vacl
__APEX_INT_F_QUALS void vacl(vec16s& restrict a, vec16u& restrict b, vec16s c)
{
  vacl(&a, &b, c);
}

__APEX_INT_F_QUALS void vacl(vec16s& restrict a, vec16u& restrict b, vec16u c)
{
  vacl(&a, &b, c);
}

__APEX_INT_F_QUALS void vacl(vec16u& restrict a, vec16u& restrict b, vec16u c)
{
  vacl(&a, &b, c);
}

__APEX_INT_F_QUALS void vacl(vec32s& restrict a, vec16s c)
{
  vacl(&a, c);
}

__APEX_INT_F_QUALS void vacl(vec32u& restrict a, vec16u c)
{
  vacl(&a, c);
}

__APEX_INT_F_QUALS void vacl(vec32s& restrict a, vec16u c)
{
  vacl(&a, c);
}

__APEX_INT_F_QUALS void vacl(vec32u& restrict a, vec16s c)
{
  vacl(&a, c);
}

// vacm
__APEX_INT_F_QUALS void vacm(vec16s& restrict a, vec16u& restrict b, vec16s c)
{
  vacm(&a, &b, c);
}

__APEX_INT_F_QUALS void vacm(vec16s& restrict a, vec16u& restrict b, vec16u c)
{
  vacm(&a, &b, c);
}

__APEX_INT_F_QUALS void vacm(vec16u& restrict a, vec16u& restrict b, vec16u c)
{
  vacm(&a, &b, c);
}

__APEX_INT_F_QUALS void vacm(vec32s& restrict a, vec16s c)
{
  vacm(&a, c);
}

__APEX_INT_F_QUALS void vacm(vec32u& restrict a, vec16u c)
{
  vacm(&a, c);
}

__APEX_INT_F_QUALS void vacm(vec32s& restrict a, vec16u c)
{
  vacm(&a, c);
}

__APEX_INT_F_QUALS void vacm(vec32u& restrict a, vec16s c)
{
  vacm(&a, c);
}

// vach
__APEX_INT_F_QUALS void vach(vec16s& restrict a, vec16u& restrict b, vec16s c)
{
  vach(&a, &b, c);
}

__APEX_INT_F_QUALS void vach(vec16s& restrict a, vec16u& restrict b, vec16u c)
{
  vach(&a, &b, c);
}

__APEX_INT_F_QUALS void vach(vec32s& restrict a, vec16s c)
{
  vach(&a, c);
}

__APEX_INT_F_QUALS void vach(vec32u& restrict a, vec16u c)
{
  vach(&a, c);
}

__APEX_INT_F_QUALS void vach(vec32u& restrict a, vec16s c)
{
  vach(&a, (vec16u)c);
}

// vslo
__APEX_INT_F_QUALS vec16s vslo(vec16s va, vbool vc, vbool& restrict vf)
{
  return vslo(va, vc, &vf);
}

// vsro
__APEX_INT_F_QUALS vec16s vsro(vec16s va, vbool vc, vbool& restrict vf)
{
  return vsro(va, vc, &vf);
}

// Specialized shifts
__APEX_INT_F_QUALS void vsllx(vec16s& restrict vc, vec16s& restrict vd, vec16s va, vec16s vb, vec16s vs)
{
  vsllx(&vc, &vd, va, vb, vs);
}

__APEX_INT_F_QUALS void vsllx(vec16u& restrict vc, vec16u& restrict vd, vec16u va, vec16u vb, vec16u vs)
{
  vsllx(&vc, &vd, va, vb, vs);
}

__APEX_INT_F_QUALS void vsrax(vec16s& restrict vc, vec16s& restrict vd, vec16s va, vec16s vb, vec16s vs)
{
  vsrax(&vc, &vd, va, vb, vs);
}

__APEX_INT_F_QUALS void vsrax(vec16u& restrict vc, vec16u& restrict vd, vec16u va, vec16u vb, vec16u vs)
{
  vsrax(&vc, &vd, va, vb, vs);
}

__APEX_INT_F_QUALS void vsr(vec16u& restrict vc, vec16u& restrict vd, vec16u va, vec16u vb, int s)
{
  vsr(&vc, &vd, va, vb, s);
}

__APEX_INT_F_QUALS void vsrlx(vec16s& restrict vc, vec16s& restrict vd, vec16s va, vec16s vb, vec16s vs)
{
  vsrlx(&vc, &vd, va, vb, vs);
}

__APEX_INT_F_QUALS void vsrlx(vec16u& restrict vc, vec16u& restrict vd, vec16u va, vec16u vb, vec16u vs)
{
  vsrlx(&vc, &vd, va, vb, vs);
}

// Swap functions
__APEX_INT_F_QUALS void vswap(vec16s& restrict a, vec16s& restrict b, vbool c)
{
  vswap(&a, &b, c);
}

__APEX_INT_F_QUALS void vswap(vec16u& restrict a, vec16u& restrict b, vbool c)
{
  vswap(&a, &b, c);
}

__APEX_INT_F_QUALS void vswap(vec32s& restrict a, vec32s& restrict b, vbool c)
{
  vswap(&a, &b, c);
}

__APEX_INT_F_QUALS void vswap(vec32u& restrict a, vec32u& restrict b, vbool c)
{
  vswap(&a, &b, c);
}

// vmul 16x16->32
__APEX_INT_F_QUALS void vmul(vec16s& h, vec16u& l, vec16s a, vec16s b)
{
  vmul(&h, &l, a, b);
}
__APEX_INT_F_QUALS void vmul(vec16s& restrict h, vec16u& restrict l, vec16u a, vec16s b)
{
  vmul(&h, &l, a, b);
}
__APEX_INT_F_QUALS void vmul(vec16s& restrict h, vec16u& restrict l, vec16s a, vec16u b)
{
  vmul(&h, &l, a, b);
}
__APEX_INT_F_QUALS void vmul(vec16u& restrict h, vec16u& restrict l, vec16u a, vec16u b)
{
  vmul(&h, &l, a, b);
}

// vmac 16x16->32
__APEX_INT_F_QUALS void vmac(vec16s& restrict h, vec16u& restrict l, vec16s a, vec16s b)
{
  vmac(&h, &l, a, b);
}
__APEX_INT_F_QUALS void vmac(vec16s& restrict h, vec16u& restrict l, vec16u a, vec16s b)
{
  vmac(&h, &l, a, b);
}
__APEX_INT_F_QUALS void vmac(vec16s& restrict h, vec16u& restrict l, vec16s a, vec16u b)
{
  vmac(&h, &l, a, b);
}
__APEX_INT_F_QUALS void vmac(vec16u& restrict h, vec16u& restrict l, vec16u a, vec16u b)
{
  vmac(&h, &l, a, b);
}

// vmad 16x16->32
__APEX_INT_F_QUALS void vmad(vec16s& restrict h, vec16u& restrict l, vec16s a, vec16s b, vec16s ch, vec16u cl)
{
  vmad(&h, &l, a, b, ch, cl);
}
__APEX_INT_F_QUALS void vmad(vec16s& restrict h, vec16u& restrict l, vec16u a, vec16s b, vec16s ch, vec16u cl)
{
  vmad(&h, &l, a, b, ch, cl);
}
__APEX_INT_F_QUALS void vmad(vec16s& restrict h, vec16u& restrict l, vec16s a, vec16u b, vec16s ch, vec16u cl)
{
  vmad(&h, &l, a, b, ch, cl);
}
__APEX_INT_F_QUALS void vmad(vec16u& restrict h, vec16u& restrict l, vec16u a, vec16u b, vec16u ch, vec16u cl)
{
  vmad(&h, &l, a, b, ch, cl);
}
#endif

/////////////////////////////////////////////////////
// End of functions with reference parameters      //
/////////////////////////////////////////////////////

#undef __APEX_INT_F_QUALS

#endif

/* EWL
 * Copyright © 1995-2018 Freescale Corporation.  All rights reserved.
 *
 *
 *
 */

#ifndef _EWL_MAX_ALIGN_T_H
#define _EWL_MAX_ALIGN_T_H

#include <ansi_parms.h>

#if _EWL_C11

_EWL_BEGIN_NAMESPACE_STD
_EWL_BEGIN_EXTERN_C

#ifndef _EWL_MAX_ALIGN_T_TYPE
  #define _EWL_MAX_ALIGN_T_TYPE long double
#endif

#ifndef _EWL_MAX_ALIGN_T_DEFINED
  #define _EWL_MAX_ALIGN_T_DEFINED
  typedef _EWL_MAX_ALIGN_T_TYPE max_align_t;
#endif

_EWL_END_EXTERN_C
_EWL_END_NAMESPACE_STD

#if __cplusplus
using std::max_align_t;
#endif

#endif /* _EWL_C11 */
#endif /* _EWL_MAX_ALIGN_T_H */

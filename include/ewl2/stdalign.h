/* EWL
 * Copyright © 1995-2018 Freescale Corporation.  All rights reserved.
 *
 *
 *
 */

#ifndef _EWL_STDALIGN_H
#define _EWL_STDALIGN_H

#include <ansi_parms.h>

#if _EWL_C11
#if defined(__llvm__)

#ifndef __cplusplus
 #define alignas _Alignas
 #define alignof _Alignof
#endif

#define __alignas_is_defined    1
#define __alignof_is_defined    1

#else
  #error unsupported macros for C11 spec in <stdalign.h>
#endif /* __llvm__ */

#endif /* _EWL_C11 */
#endif /* _EWL_STDALIGN_H */

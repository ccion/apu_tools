/* EWL
 * Copyright © 1995-2018 Freescale Corporation.  All rights reserved.
 *
 *
 *
 */

#ifndef _EWL_STDNORETURN_H
#define _EWL_STDNORETURN_H

#include <ansi_parms.h>

#if _EWL_C11

#if defined(__llvm__)
 #define noreturn _Noreturn
#else
 #error unsupported macros for C11 spec in <stdnoreturn.h>
#endif /* __llvm__ */

#endif /* _EWL_C11 */
#endif /* _EWL_STDNORETURN_H */

/* EWL
 * Copyright © 1995-2018 Freescale Corporation.  All rights reserved.
 *
 *
 *
 */

#ifndef _EWL_UCHAR_H
#define _EWL_UCHAR_H

#include <ansi_parms.h>

#if _EWL_UNICODE_CHAR

#ifndef __cplusplus

#include <stdint.h>

/* Define the 16-bit and 32-bit character types. */
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif /* __cplusplus */

#endif /* _EWL_UNICODE_CHAR */
#endif /* _EWL_UCHAR_H */


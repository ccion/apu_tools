/* EWL
 * Copyright � 1995-2009 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2009/12/21 12:33:27 $
 * $Revision: 1.4 $
 */

#ifndef _EWL_GLOBALS_H
#define _EWL_GLOBALS_H

#if defined(__COLDFIRE__)
    #include <coldfire/ansi_prefix.CF.h>        /* ColdFire */
#elif defined(__HC12__)
    #include <hc/ansi_prefix.hc.h>              /* HC12 */
#elif defined(__AIOP_EABI__)
    #include <aiop/ansi_prefix.PA_EABI.bare.h>    /* AIOP */
#elif defined(__PPC_EABI__)
    #include <pa/ansi_prefix.PA_EABI.bare.h>    /* Embedded Power Architecture */
#elif defined(__m56800E__) || defined(__m56800__)
    #include <dsp/ansi_prefix.dsp.h>            /* Hawk DSP */
#elif defined (__arm) || defined(__arm__)
	#include <arm/ansi_prefix.ARM.h>			/* ARM */
#elif defined (_ENTERPRISE_C_) || defined (__STARCORE__)
	#include <sc/ansi_prefix_StarCore.h>		/* StarCore */
#elif defined (__INTEL__)
	#include <x86/ansi_prefix_winx86.h>			/* Windows x86 */
#elif defined (__APEX__)
	#include <apex/ansi_prefix.APEX.h>			/* APEX */
#else
    /* Unknown platform! */
    #error ewlGlobals.h could not include prefix file
#endif

#endif /* _EWL_GLOBALS_H */

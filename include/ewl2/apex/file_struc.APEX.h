/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _EWL_FILE_STRUC_APEX_H
#define _EWL_FILE_STRUC_APEX_H

#define _EWL_FILE_STRUC_H

#include <ansi_parms.h>

/* APEX uses a simple file structure, since most of the work is done
   on the host.
*/
struct FILE {
	int handle;
	int opened;
};

_EWL_BEGIN_NAMESPACE_STD

typedef struct FILE FILE;
typedef long fpos_t;

_EWL_END_NAMESPACE_STD

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#ifndef FOPEN_MAX
#define FOPEN_MAX 16
#endif

#endif

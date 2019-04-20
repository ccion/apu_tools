/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _APEX_RUNTIME_INFO_H
#define _APEX_RUNTIME_INFO_H

#ifdef __cplusplus
extern "C"
#endif
int apuGetNumberOfCUs();

#ifdef __cplusplus
extern "C"
#endif
int apuQuerySystem(int attribute);

#endif

/*===---------------------------------------------------------------------===//
 * (C) Copyright Freescale 2016, All rights reserved.
 * FREESCALE CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Freescale, Inc.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 *===---------------------------------------------------------------------===*/

#ifndef _EWL_STDIO_APEX_H
#define _EWL_STDIO_APEX_H

_EWL_IMP_EXP_C FILE * _EWL_CDECL	fopen(const char * _EWL_RESTRICT filename, const char * _EWL_RESTRICT mode) _EWL_CANT_THROW;

_EWL_IMP_EXP_C FILE * _EWL_CDECL	fdopen(int fd, const char * _EWL_RESTRICT mode) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		close(int fd) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		fprintf(FILE * _EWL_RESTRICT stream, const char * _EWL_RESTRICT format, ...) _EWL_CANT_THROW;

_EWL_IMP_EXP_C size_t _EWL_CDECL	fwrite_word(const void * _EWL_RESTRICT ptr, size_t, size_t, int lsb_first, FILE * _EWL_RESTRICT f) _EWL_CANT_THROW;

_EWL_IMP_EXP_C size_t _EWL_CDECL	fread_word(const void * _EWL_RESTRICT ptr, size_t, size_t, int lsb_first, FILE * _EWL_RESTRICT f) _EWL_CANT_THROW;

_EWL_IMP_EXP_C FILE * _EWL_CDECL	tmpfile(void) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		remove(const char *s) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		rename(const char *oldname, const char *newname) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		mkstemp(char* s) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		feof(FILE * _EWL_RESTRICT f) _EWL_CANT_THROW;

_EWL_IMP_EXP_C int _EWL_CDECL		ferror(FILE * _EWL_RESTRICT f) _EWL_CANT_THROW;

#endif /* _EWL_STDIO_APEX_H */

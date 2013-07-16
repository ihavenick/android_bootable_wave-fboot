/*
 ; This file is part of Badadroid project.
 ;
 ; Copyright (C) 2012 Rebellos, mijoma, b_kubica
 ;
 ; Based on cstdlib string.h
 ;
 ; Badadroid is free software: you can redistribute it and/or modify
 ; it under the terms of the GNU General Public License as published by
 ; the Free Software Foundation, either version 3 of the License, or
 ; (at your option) any later version.
 ;
 ; Badadroid is distributed in the hope that it will be useful,
 ; but WITHOUT ANY WARRANTY; without even the implied warranty of
 ; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ; GNU General Public License for more details.
 ;
 ; You should have received a copy of the GNU General Public License
 ; along with Badadroid.  If not, see <http://www.gnu.org/licenses/>.
 ;
 ;
*/

#ifndef _STRING_H_
#define _STRING_H_

#define NULL 0
typedef unsigned long  size_t;

extern void*  memccpy(void *, const void *, int, size_t);
extern void*  memchr(const void *, int, size_t);
extern void*  memrchr(const void *, int, size_t);
extern int    memcmp(const void *, const void *, size_t);
extern void*  memcpy(void *, const void *, size_t);
extern void*  memmove(void *, const void *, size_t);
extern void*  memset(void *, int, size_t);
extern void*  memmem(const void *, size_t, const void *, size_t);
extern void   memswap(void *, void *, size_t);

extern char*  index(const char *, int);
extern char*  rindex(const char *, int);
extern char*  strchr(const char *, int);
extern char*  strrchr(const char *, int);

extern size_t strlen(const char *);
extern int    strcmp(const char *, const char *);
extern char*  strcpy(char *, const char *);
extern char*  strcat(char *, const char *);

extern int    strcasecmp(const char *, const char *);
extern int    strncasecmp(const char *, const char *, size_t);
extern char*  strdup(const char *);

extern char*  strstr(const char *, const char *);
extern char*  strcasestr(const char *haystack, const char *needle);
extern char*  strtok(char *, const char *);
extern char*  strtok_r(char *, const char *, char**);

extern char*  strerror(int);
extern int    strerror_r(int errnum, char *buf, size_t n);

extern size_t strnlen(const char *, size_t);
extern char*  strncat(char *, const char *, size_t);
extern char*  strndup(const char *, size_t);
extern int    strncmp(const char *, const char *, size_t);
extern char*  strncpy(char *, const char *, size_t);

extern size_t strlcat(char *, const char *, size_t);
extern size_t strlcpy(char *, const char *, size_t);

extern size_t strcspn(const char *, const char *);
extern char*  strpbrk(const char *, const char *);
extern char*  strsep(char **, const char *);
extern size_t strspn(const char *, const char *);

extern char*  strsignal(int  sig);

extern int    strcoll(const char *, const char *);
extern size_t strxfrm(char *, const char *, size_t);


#endif /* _STRING_H_ */

/*
 Copyright (c) 2010, Florian Reuter
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without 
 modification, are permitted provided that the following conditions 
 are met:
 
 * Redistributions of source code must retain the above copyright 
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright 
   notice, this list of conditions and the following disclaimer in 
   the documentation and/or other materials provided with the 
   distribution.
 * Neither the name of Florian Reuter nor the names of its contributors 
   may be used to endorse or promote products derived from this 
   software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
 OF THE POSSIBILITY OF SUCH DAMAGE.
 
*/
#ifndef _PLIB_PLIB_H_
#define _PLIB_PLIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#undef HAVE_STDINT_H
#undef HAVE_STDDEF_H
#undef HAVE_STDIO_H
#ifndef WIN32
#define WIN32
#endif

#ifdef WIN32
#include <windows.h>
#endif

#ifdef HAVE_STDDEF_H
#include <stddef.h>
typedef size_t pofs_t; // maximum file offset for eg. read write ops
#elif defined(WIN32)
typedef size_t pofs_t; // maximum file offset for eg. read write ops
#else
#error "system types can not be determined"
#endif

#ifdef HAVE_STDIO_H
#include <stdio.h>
#elif defined(WIN32)
#include <stdio.h>
#include <io.h>
#else
#error "system io can not be determined"
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>

typedef int8_t pint8_t;
typedef uint8_t puint8_t;

typedef int16_t pint16_t;
typedef uint16_t puint16_t;

typedef int32_t pint32_t;
typedef uint32_t puint32_t;

typedef int64_t pint64_t;
typedef uint64_t puint64_t;

// INTN_MAX, INTN_MIN, UINTN_MAX
#elif defined(WIN32)

typedef __int8 pint8_t;
typedef unsigned __int8 puint8_t;

typedef __int16 pint16_t;
typedef unsigned __int16 puint16_t;

typedef __int32 pint32_t;
typedef unsigned __int32 puint32_t;

typedef __int64 pint64_t;
typedef unsigned __int64 puint64_t;

typedef int pbool_t;

#else
#error "system types can not be determined"
#endif

#define snprintf _snprintf

#define P_WIN32

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* _PLIB_PLIB_H_ */
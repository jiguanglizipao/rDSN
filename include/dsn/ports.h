/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Microsoft Corporation
 * 
 * -=- Robust Distributed System Nucleus (rDSN) -=- 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
# pragma once

#if defined(_WIN32)

# define _WINSOCK_DEPRECATED_NO_WARNINGS 1

# include <Winsock2.h>
# include <ws2tcpip.h>
# include <Windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32.lib")

__pragma(warning(disable:4127))

#define __thread __declspec(thread)
#define __selectany __declspec(selectany) extern 
#define getcwd_ _getcwd
#define rmdir_ _rmdir
#define mkdir_ _mkdir

# elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)

# include <unistd.h>
# include <sys/stat.h>

# define __selectany __attribute__((weak)) extern 
#define getcwd_ getcwd
#define rmdir_ rmdir
#define mkdir_(path) mkdir(path, 0666)

# ifndef O_BINARY
# define O_BINARY 0
#endif

#else

#error "unsupported platform"
#endif

# ifndef TIME_MS_MAX
# define TIME_MS_MAX 0x0FFFFFFF
# endif

# ifndef FIELD_OFFSET
# define FIELD_OFFSET(s, field)  (((size_t)&((s *)(10))->field) - 10)
# endif

# ifndef CONTAINING_RECORD 
# define CONTAINING_RECORD(address, type, field) \
    ((type *)((char*)(address)-FIELD_OFFSET(type, field)))
# endif

# ifndef MAX_COMPUTERNAME_LENGTH
# define MAX_COMPUTERNAME_LENGTH 32
# endif

# ifndef ARRAYSIZE
# define ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))
# endif

# ifndef __in_param
# define __in_param
# endif

# ifndef __out_param
# define __out_param
# endif

# ifndef __inout_param
# define __inout_param
# endif

// stl headers
# include <string>
# include <memory>
# include <map>
# include <unordered_map>
# include <set>
# include <unordered_set>
# include <vector>
# include <list>
# include <algorithm>

// common c headers
# include <cassert>
# include <cstring>
# include <cstdlib>
# include <fcntl.h> // for file open flags
# include <cstdio>

// common utilities
# include <atomic>

// common macros
#define PROVIDER_TYPE_MAIN 0
#define PROVIDER_TYPE_ASPECT 1

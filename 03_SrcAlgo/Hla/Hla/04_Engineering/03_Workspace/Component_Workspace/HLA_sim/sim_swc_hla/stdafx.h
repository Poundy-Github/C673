// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#ifndef WINVER
#define WINVER 0x0501
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0501
#endif

#define NOMINMAX

// ATL includes
#include <atlbase.h>
#include <atlcom.h>
#include <atlstr.h>
#include <atldbcli.h>

#include <cstdint>

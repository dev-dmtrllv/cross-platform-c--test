#ifndef PCH_H
#define PCH_H

#ifdef _WIN32 // WINDOWS ONLY

#	define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#	include <windows.h>
#	include <io.h>

#	ifdef NOVAENGINE_EXPORTS

#		ifdef _WIN64
#			define V8_COMPRESS_POINTERS 1
#			define V8_31BIT_SMIS_ON_64BIT_ARCH 1
#		endif

#		define API extern "C" __declspec(dllexport)
#		define API_CLASS(className) extern "C" class __declspec(dllexport) className
#		pragma comment(lib, "winmm.lib")
#		pragma comment(lib, "DbgHelp.lib")
#		pragma comment(lib, "Shlwapi.lib")
#		pragma comment(lib, "v8_monolith.lib")

#	else

#		define API extern "C" __declspec(dllimport)
#		define API_CLASS(className) extern "C" class __declspec(dllimport) className

#	endif // NOVA_ENGINE_EXPORTS

#elif __GNUC__
#	if __x86_64__ || __ppc64__
#		define V8_COMPRESS_POINTERS 1
#		define V8_31BIT_SMIS_ON_64BIT_ARCH 1
#	endif

#	define API extern "C"
#	define API_CLASS(className) extern "C" class className
#endif // END ALL EXCEPT WINDOWS


// Standard Header Files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>

#ifdef NOVAENGINE_EXPORTS
// V8 includes
#include <libplatform/libplatform.h>
#include <v8.h>
#endif

#ifdef _ITERATOR_DEBUG_LEVEL

#endif

#endif //PCH_H

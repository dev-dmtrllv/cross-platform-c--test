#ifndef PCH_H
#define PCH_H

#ifdef _WIN32 // WINDOWS ONLY

#	define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#	include <windows.h>

#	ifdef NOVAENGINE_EXPORTS

#		define API extern "C" __declspec(dllexport)
#		define API_CLASS(className) extern "C" class __declspec(dllexport) className
#		define V8_COMPRESS_POINTERS 1
#		define V8_31BIT_SMIS_ON_64BIT_ARCH 1
#		pragma comment(lib, "winmm.lib")
#		pragma comment(lib, "DbgHelp.lib")
#		pragma comment(lib, "Shlwapi.lib")
#		pragma comment(lib, "v8_monolith.lib")

#	else

#		define API extern "C" __declspec(dllimport)
#		define API_CLASS(className) extern "C" class __declspec(dllimport) className

#	endif // NOVA_ENGINE_EXPORTS

#else

#	define API extern "C"
#	define API_CLASS(className) extern "C" class className

#endif // END ALL EXCEPT WINDOWS


// Standard Header Files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>

#ifdef NOVAENGINE_EXPORTS

// V8 includes
#include <libplatform/libplatform.h>
#include <v8.h>
#endif

#endif //PCH_H

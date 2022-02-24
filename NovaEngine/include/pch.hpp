#ifndef PCH_H
#define PCH_H

#ifdef _WIN32 // WINDOWS ONLY

// Windows Header Files
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#ifdef NOVAENGINE_EXPORTS
#define API extern "C" __declspec(dllexport)
#define API_CLASS(className) extern "C" class __declspec(dllexport) className
#else
#define API extern "C" __declspec(dllimport)
#define API_CLASS(className) extern "C" class __declspec(dllimport) className
#endif // NOVA_ENGINE_EXPORTS

#else // WINDOWS ONLY

#define API extern "C"
#define API_CLASS(className) extern "C" class className

#endif // END ALL EXCEPT WINDOWS

// Standard Header Files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef NOVAENGINE_EXPORTS
// V8 includes
#include <libplatform/libplatform.h>
#include <v8.h>
#endif

#endif //PCH_H

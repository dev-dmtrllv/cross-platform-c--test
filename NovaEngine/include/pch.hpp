#ifndef PCH_H
#define PCH_H

#ifdef _WIN32 // WINDOWS ONLY

// Windows Header Files
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

// macros
#ifdef NOVAENGINE_EXPORTS
#define API extern "C" __declspec(dllexport)
#else
#define API extern "C" __declspec(dllimport)
#endif

#ifdef NOVAENGINE_EXPORTS
#define API_CLASS(name) extern "C" class __declspec(dllexport) name

// V8 includes
#include <libplatform/libplatform.h>
#include <v8.h>

#else
#define API_CLASS(name) extern "C" class __declspec(dllimport) name
#endif // NOVA_ENGINE_EXPORTS

#endif // WINDOWS ONLY

// Standard Header Files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#endif //PCH_H

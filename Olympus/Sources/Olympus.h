#pragma once

#ifdef WIN32
	#include <windows.h>
#endif//WIN32

#ifdef OLYMPUS_DLL
	#define OLYMPUS_API __declspec(dllexport)
#else
	#define OLYMPUS_API __declspec(dllimport)
#endif//OLYMPUS_DLL
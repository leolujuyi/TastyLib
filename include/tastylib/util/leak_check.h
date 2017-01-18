#ifndef TASTYLIB_LEAKCHECK_H_
#define TASTYLIB_LEAKCHECK_H_

// Uncomment the command below to enable memory leaks check.
//#define LEAK_CHECK_ENABLED

#if defined(LEAK_CHECK_ENABLED) && defined(_MSC_VER)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

/*
The function to check memory leaks. It is available
only when compiled with Visual Studio under Debug model.
Memory dump messages will be printed to the output window.
*/
inline void checkMemoryLeaks() {
#ifdef _CRTDBG_MAP_ALLOC
    _CrtDumpMemoryLeaks();
#endif
}

#endif

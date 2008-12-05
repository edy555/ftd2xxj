#include "ftd2xxj.h"

#define LOGGER_IMPLEMENTATION
#include "logger.h"

void __attribute__ ((constructor)) ftd2xxj_Initialize(void){
    Logger_Initialize("FTD2XXJ");
}

FT_HANDLE ToNativeHandle(jlong handle){      
    return (FT_HANDLE)((unsigned long) handle);
}

jlong ToJavaHandle(FT_HANDLE handle){    
    return (jlong)handle;
}

#ifdef _WINDOWS

#include <windows.h>

/**
 * Windows dynamic link library entry point.
 * 
 * Currently only used for windows.
 */
BOOL WINAPI DllMain(HANDLE module, DWORD reason, LPVOID reserved)
{
  switch(reason)
    {
        case DLL_PROCESS_ATTACH:           
            Logger_Finest("(%s: %i): DLL_PROCESS_ATTACH\n", __FILE__, __LINE__); 
          break;
          
        case DLL_PROCESS_DETACH:
            Logger_Finest("(%s: %i): DLL_PROCESS_DETACH\n", __FILE__, __LINE__); 
          break;
          
        case DLL_THREAD_ATTACH:
            Logger_Finest("(%s: %i): DLL_THREAD_ATTACH\n", __FILE__, __LINE__); 
          break;
          
        case DLL_THREAD_DETACH:
            Logger_Finest("(%s: %i): DLL_THREAD_DETACH\n", __FILE__, __LINE__); 
          break;
          
        default:
            Logger_Finest("(%s: %i) - Unknown reason: %X\n", __FILE__, __LINE__, 
                (unsigned int)reason); 
          break;
    }
  return TRUE;
}

#endif

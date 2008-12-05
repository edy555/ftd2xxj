#ifndef FTD2XX_OS_INDIPENDENT_H
#define FTD2XX_OS_INDIPENDENT_H

#ifndef __cplusplus
    typedef enum {false = 0, true = 1} bool;
#endif  

    #ifdef _WINDOWS
        #include <windows.h>
        #include "windows/ftd2xx.h"
    #else
        #include "linux/ftd2xx.h"
    #endif
#endif

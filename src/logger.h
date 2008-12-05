/**
 * @file logger.h
 * API to log diagnostics information and to determin whether logging is
 * enabled, or not.<br>
 * <br>
 * <b>Example:</b><br>
 * <pre>
 * Logger_Initialize("MY_API_NAME"); // init the logging system
 * 
 * ...
 * 
 * Logger_Log(INFO, "Log with level INFO (%i)", INFO); // log info message
 * </pre>
 * 
 * The example first initializes the current logging level using the environment 
 * variable "MY_API_NAME". Valid values are the name of a particular 
 * <code>Logging_Level</code>.<br>
 * <br>
 * Finally the message "Log with level INFO (5)" is logged.
 */
#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

/**
 * Defines the linkage of declared functions. If this file is included by an 
 * application they're marked as <code>external</code>.
 */

#ifndef _WINDOWS
    #define LOGGER_EXPORT
    #define LOGGER_CALL
#else
    #define LOGGER_CALL __stdcall
    #ifdef LOGGER_IMPLEMENTATION
        #define LOGGER_EXPORT __declspec(dllexport)
    #else
        #define LOGGER_EXPORT __declspec(dllimport)
    #endif
#endif

typedef enum{ 
    OFF 	= 0,    
    SEVERE	= 1,
    WARNING	= 2,
    CONFIG	= 3,
    INFO	= 4,
    FINE	= 5,
    FINER	= 6,
    FINEST	= 7,
    ALL		= 8   
} Logging_Level;

#ifdef __cplusplus
extern "C"
{
#endif

LOGGER_EXPORT void LOGGER_CALL Logger_Initialize(const char* environmentVariableName);
LOGGER_EXPORT int LOGGER_CALL Logger_IsLoggable(Logging_Level level);
LOGGER_EXPORT Logging_Level LOGGER_CALL Logger_GetLoggingLevel();
LOGGER_EXPORT void LOGGER_CALL Logger_SetLoggingLevel(Logging_Level level);
LOGGER_EXPORT void LOGGER_CALL Logger_SetOutputStream(Logging_Level level, FILE* outputStream);
LOGGER_EXPORT void LOGGER_CALL Logger_Log(Logging_Level level, const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Info(const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Config(const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Fine(const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Finer(const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Finest(const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Warning(const char *format, ...);
LOGGER_EXPORT void LOGGER_CALL Logger_Severe(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* LOGGER_H_ */

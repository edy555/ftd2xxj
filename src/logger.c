#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

/**
 * Define linkage to be non-external for implementation purpose.
 */
#define LOGGER_IMPLEMENTATION
#include "logger.h"

#define MAX_BUFFER_SIZE 1024
#define TIME_BUFFER_SIZE 50

static const char LEVEL_NAMES[][10] = {
    "OFF",
    "FINEST",
    "FINER",
    "FINE",
    "CONFIG",
    "INFO",
    "WARNING",
    "SEVERE",
    "ALL"    
};

static FILE* outputStreams[9] = {NULL};

/**
 * Stores the current logging level. The default value is <code>OFF</code>.
 */
static Logging_Level currentLevel = OFF;

/**
 * Retrieves the <code>Logging_Level</code> of a particular level name.
 * 
 * @return the <code>Logging_Level</code>, or <code>OFF</code> if the level name 
 * is not valid.
 */
static Logging_Level LevelFor(const char* levelName){
    Logging_Level result = OFF;
    
    if(levelName != NULL){
        Logging_Level level = OFF;
        for(level = OFF; level <= ALL; level++){        	
            if(strcmp(levelName, LEVEL_NAMES[level]) == 0){
                result = level;
                break;
            }            
        }
    }
    
    return result;
}

/**
 * initializes the output streams with theire default values.
 */
static void InitializeOutputStreams(){
    
    outputStreams[FINEST] = stdout;
    outputStreams[FINER] = stdout;
    outputStreams[FINE] = stdout;
    outputStreams[CONFIG] = stdout;
    outputStreams[INFO] = stdout;
    outputStreams[WARNING] = stdout;
    outputStreams[SEVERE] = stderr;
}

/**
 * Initializes the current logging level by extracting the value from a 
 * particular environment variable. If the environment variable is not specified 
 * or it's value is invalid the level is set to <code>OFF</code>.
 * 
 * @param environmentVariableName the name of the environment variable which 
 * stores the level to use.
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Initialize(const char* environmentVariableName){
    
    InitializeOutputStreams();
    
    currentLevel = LevelFor(getenv(environmentVariableName));
}

/**
 * Retrieves the current logging level.
 * 
 * @return the current level.
 */
LOGGER_EXPORT Logging_Level LOGGER_CALL Logger_GetLoggingLevel(){
    return currentLevel;
}

/**
 * Sets the new logging level.
 * 
 * @param the new logging level.
 */
LOGGER_EXPORT void LOGGER_CALL Logger_SetLoggingLevel(Logging_Level level){
    currentLevel = level;
}
    
/**
 * Sets the output stream for a particular logging level.
 * 
 * @param level the level for which to set the target stream.
 * @param outputStream the stream to be used when logging messages with 
 * <code>level</code>.
 */
LOGGER_EXPORT void LOGGER_CALL Logger_SetOutputStream(Logging_Level level, FILE* outputStream){
    outputStreams[level] = outputStream;
}

/**
 * Determines whether a message with a particular <code>Logging_Level</code>
 * will be logged or not.
 * 
 * @param level the level to check for.
 * 
 * @return <code>0</code> if the level is less than the current logging or the 
 *      current logging level is OFF. 
 *      level, <code>1</code> otherwise.
 */
LOGGER_EXPORT int LOGGER_CALL Logger_IsLoggable(Logging_Level level){
    return (level <= currentLevel) ? 1 : 0;
}

static void Logv(Logging_Level level, const char *format, va_list parameters)
{     
    time_t currentTime = time(NULL);
    char buffer[MAX_BUFFER_SIZE] = {0};  
    char timeBuffer[TIME_BUFFER_SIZE] = {0};    
    
    if(!Logger_IsLoggable(level))
        return;
    
    /*
     * Extend format by time and logging level information
     */
    strftime(timeBuffer, TIME_BUFFER_SIZE, "%d.%m.%Y %H:%M:%S", localtime(&currentTime));
    sprintf(buffer, "%s\n%s: %s\n\n", timeBuffer, LEVEL_NAMES[level], format);

    vfprintf(outputStreams[level], buffer, parameters);
    fflush(outputStreams[level]);
}

/**
 * Logs a message using the format and all optional parameters to the output 
 * stream, but assoziated with <code>level</code>, but only if 
 * <code>level</code> is loggable.
 * 
 * @param level the level to be used logging the message.
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_SetLoggingLevel
 * @see Logger_GetLoggingLevel
 * @see Logger_SetOutputStream
 * @see Logger_GetOutputStream
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Log(Logging_Level level, const char *format, ...)
{   
    va_list parameters;

    va_start(parameters, format);
    
    Logv(level, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>INFO</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Info(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
   
    Logv(INFO, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>CONFIG</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Config(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
    
    Logv(CONFIG, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>WARNING</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Warning(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
    
    Logv(WARNING, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>SEVERE</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Severe(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
    
    Logv(SEVERE, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>FINE</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Fine(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
    
    Logv(FINE, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>FINER</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Finer(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
    
    Logv(FINER, format, parameters);
    
    va_end(parameters);
}

/**
 * Logs the message with level <code>FINEST</code>.
 * 
 * @param format the format specification recognized by <code>printf</code>.
 * 
 * @see Logger_Log
 */
LOGGER_EXPORT void LOGGER_CALL Logger_Finest(const char *format, ...){
    va_list parameters;

    va_start(parameters, format);
    
    Logv(FINEST, format, parameters);
    
    va_end(parameters);
}

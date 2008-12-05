#include "com_ftdichip_ftd2xx_Port.h"

#include <ftd2xx.h>
#include "error.h"
#include "ftd2xxj.h"

#define LOGGER_IMPLEMENTATION
#include "logger.h"

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_reset
  (JNIEnv *env, jclass port, jlong handle){
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_ResetPort(ftHandle);
    
    Logger_Fine("(%s: %i) - FT_ResetPort(%i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setBaudRate
  (JNIEnv *env, jclass port, jlong handle, jlong baudRate){
   
   FT_HANDLE ftHandle = ToNativeHandle(handle);
   FT_STATUS result = FT_SetBaudRate(ftHandle, (DWORD)baudRate);
    
   Logger_Fine("(%s: %i) - FT_SetBaudRate(%i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)baudRate, (int)result); 
    
   HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setDivisor
  (JNIEnv *env, jclass port, jlong handle, jint divisor){
     
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_SetDivisor(ftHandle, (USHORT)divisor);
    
    Logger_Fine("(%s: %i) - FT_SetDivisor(%i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (USHORT)divisor, (int)result); 
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setDataCharacteristics
  (JNIEnv *env, jclass port, jlong handle, jint dataBits, jint stopBits, jint parity){
     
     FT_HANDLE ftHandle = ToNativeHandle(handle);
     FT_STATUS result = FT_SetDataCharacteristics(ftHandle, 
        (UCHAR)dataBits, (UCHAR)stopBits, (UCHAR)parity);
    
    Logger_Fine("(%s: %i) - FT_SetDataCharacteristics(%i, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (UCHAR)stopBits, (UCHAR)parity, (int)result); 
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setFlowControl
  (JNIEnv *env, jclass port, jlong handle, jint flowControlMode, jchar xon, jchar xoff){
     
     FT_HANDLE ftHandle = ToNativeHandle(handle);
     FT_STATUS result = FT_SetFlowControl(ftHandle, 
        (USHORT)flowControlMode, xon, xoff);
    
    Logger_Fine("(%s: %i) - FT_SetFlowControl(%i, %i, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (USHORT)flowControlMode, xon, xoff, (int)result); 
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setDTR
  (JNIEnv *env, jclass port, jlong handle, jboolean enable){
     
     FT_HANDLE ftHandle = ToNativeHandle(handle);
     FT_STATUS result = FT_OK;
     
     if(enable == JNI_TRUE){
         result = FT_SetDtr(ftHandle);
         
         Logger_Fine("(%s: %i) - FT_SetDtr(%i): %i", __FILE__, __LINE__, 
            (unsigned int)ftHandle, (int)result);
     }
     else{
        result = FT_ClrDtr(ftHandle);
        
        Logger_Fine("(%s: %i) - FT_ClrDtr(%i): %i", __FILE__, __LINE__, 
            (unsigned int)ftHandle, (int)result);
     }
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setRTS
  (JNIEnv *env, jclass port, jlong handle, jboolean enable){
     
     FT_HANDLE ftHandle = ToNativeHandle(handle);
     FT_STATUS result = FT_OK;
     
     if(enable == JNI_TRUE){
         result = FT_SetRts(ftHandle);
         
         Logger_Fine("(%s: %i) - FT_SetRts(%i): %i", __FILE__, __LINE__, 
            (unsigned int)ftHandle, (int)result);
     }
     else{
        result = FT_ClrRts(ftHandle);
        
        Logger_Fine("(%s: %i) - FT_ClrRts(%i): %i", __FILE__, __LINE__, 
            (unsigned int)ftHandle, (int)result);
     }
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Port_setBreakOn
  (JNIEnv *env, jclass port, jlong handle, jboolean enable){
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_OK;
     
     if(enable == JNI_TRUE){
         result = FT_SetBreakOn(ftHandle);
         
         Logger_Fine("(%s: %i) - FT_SetBreakOn(%i): %i", __FILE__, __LINE__, 
            (unsigned int)ftHandle, (int)result);
     }
     else{
        result = FT_SetBreakOff(ftHandle);
        
        Logger_Fine("(%s: %i) - FT_SetBreakOff(%i): %i", __FILE__, __LINE__, 
            (unsigned int)ftHandle, (int)result);
     }
    
    HandleError(env, result);
}

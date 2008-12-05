#include "com_ftdichip_ftd2xx_Device.h"

#include <ftd2xx.h>
#include <stdlib.h>
#include "error.h"
#include "ftd2xxj.h"

#define LOGGER_IMPLEMENTATION
#include "logger.h"

JNIEXPORT jlong JNICALL Java_com_ftdichip_ftd2xx_Device_open
  (JNIEnv *env, jclass deviceClass, jlong deviceIndex){
   
   FT_HANDLE handle = NULL;
   FT_STATUS result = FT_Open(deviceIndex, &handle);
   
   Logger_Fine("(%s: %i) - FT_Open(%i, %X): %i\n", __FILE__, __LINE__, 
        (int)deviceIndex, (unsigned int)handle, (int)result);
   
   HandleError(env, result);
   
   return ToJavaHandle(handle);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_close
  (JNIEnv *env, jclass deviceClass, jlong handle){
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_Close(ftHandle);
    
    Logger_Fine("(%s: %i) - FT_Close(%X): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_reset
  (JNIEnv *env, jclass deviceClass, jlong handle){
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_ResetDevice(ftHandle);
   
    Logger_Fine("(%s: %i) - FT_ResetDevice(%X): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_purgeReceiveBuffer
  (JNIEnv *env, jclass deviceClass, jlong handle){
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_Purge(ftHandle, FT_PURGE_RX);
    
    Logger_Fine("(%s: %i) - FT_Purge(%X, FT_PURGE_RX): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_purgeTransmitBuffer
  (JNIEnv *env, jclass deviceClass, jlong handle){
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_Purge(ftHandle, FT_PURGE_TX);
    
    Logger_Fine("(%s: %i) - FT_Purge(%X, FT_PURGE_TX): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_setTimeouts
  (JNIEnv *env, jclass deviceClass, jlong handle, jlong readTimeout, jlong writeTimeout){
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_SetTimeouts(ftHandle, readTimeout, writeTimeout);
    
    Logger_Fine("(%s: %i) - FT_SetTimeouts(%X, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)readTimeout, (int)writeTimeout, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT jlong JNICALL Java_com_ftdichip_ftd2xx_Device_getTransmitQueueStatus
  (JNIEnv *env, jclass deviceClass, jlong handle){
    
    DWORD rxQueueStatus = 0;
    DWORD txQueueStatus = 0;
    DWORD eventStatus = 0;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_GetStatus(ftHandle, &rxQueueStatus, &txQueueStatus, &eventStatus);
    
    Logger_Fine("(%s: %i) - FT_GetStatus(%X, %i, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)rxQueueStatus, (int)txQueueStatus, (int)eventStatus, (int)result);
    
    HandleError(env, result);
    
    return (jlong)txQueueStatus;
}

JNIEXPORT jlong JNICALL Java_com_ftdichip_ftd2xx_Device_getReceiveQueueStatus
  (JNIEnv *env, jclass deviceClass, jlong handle){
    
    DWORD rxQueueStatus = 0;
    DWORD txQueueStatus = 0;
    DWORD eventStatus = 0;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_GetStatus(ftHandle, &rxQueueStatus, &txQueueStatus, &eventStatus);
    
    Logger_Fine("(%s: %i) - FT_GetStatus(%X, %i, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)rxQueueStatus, (int)txQueueStatus, (int)eventStatus, (int)result);
    
    HandleError(env, result);
    
    return (jlong)rxQueueStatus;
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_setResetPipeRetryCount
  (JNIEnv *env, jclass deviceClass, jlong handle, jlong count){
    FT_HANDLE ftHandle = ToNativeHandle(handle);    
    FT_STATUS result = FT_SetResetPipeRetryCount(ftHandle, count);
    
    Logger_Fine("(%s: %i) - FT_SetResetPipeRetryCount(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)count, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT jlong JNICALL Java_com_ftdichip_ftd2xx_Device_getModemStatus
  (JNIEnv *env, jclass deviceClass, jlong handle){
    
    DWORD status = FT_OK;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_GetModemStatus(ftHandle, &status);
    
    Logger_Fine("(%s: %i) - FT_GetModemStatus(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)status, (int)result);
    
    HandleError(env, result);
    
    return (jlong)status;
}

JNIEXPORT jint JNICALL Java_com_ftdichip_ftd2xx_Device_getLatencyTimer
  (JNIEnv *env, jclass deviceClass, jlong handle){
    UCHAR timer = 0;
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_GetLatencyTimer(ftHandle, &timer);
    
    Logger_Fine("(%s: %i) - FT_GetLatencyTimer(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, timer, (int)result);
    
    HandleError(env, result);
    
    return (jint)timer;
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_setLatencyTimer
  (JNIEnv *env, jclass deviceClass, jlong handle, jint timer){
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_SetLatencyTimer(ftHandle, (UCHAR)timer);
    
    Logger_Fine("(%s: %i) - FT_SetLatencyTimer(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (UCHAR)timer, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT jint JNICALL Java_com_ftdichip_ftd2xx_Device_getBitBangMode
  (JNIEnv *env, jclass deviceClass, jlong handle){
    
    UCHAR mode = 0;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_GetBitMode(ftHandle, &mode);
    
    Logger_Fine("(%s: %i) - FT_GetBitMode(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, mode, (int)result);
    
    HandleError(env, result);
    
    return (jint)mode;
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_setBitBangMode
  (JNIEnv *env, jclass deviceClass, jlong handle, jint mask, jint mode){
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_SetBitMode(ftHandle, (UCHAR)mask, (UCHAR)mode);
    
    Logger_Fine("(%s: %i) - FT_SetBitMode(%X, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (UCHAR)mask, (UCHAR)mode, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_setUSBParameters
  (JNIEnv *env, jclass deviceClass, jlong handle, jlong rxTransferSize, jlong txTransferSize){
   
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_SetUSBParameters(ftHandle, (DWORD)rxTransferSize, (DWORD)txTransferSize);
    
    Logger_Fine("(%s: %i) - FT_SetUSBParameters(%X, %u, %u): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (unsigned int)rxTransferSize, (unsigned int)txTransferSize, (int)result);
    
    HandleError(env, result);
}

JNIEXPORT jint JNICALL Java_com_ftdichip_ftd2xx_Device_read
  (JNIEnv *env, jclass deviceClass, jlong handle, jbyteArray buffer, jint offset, jint length){
   DWORD numBytesRead = -1;
   jbyte* nativeBuffer = (jbyte*)malloc(length * sizeof(jbyte));
   
   /*
    * To get initial values. Otherwise they would be initialized to 0 which may 
    * lead to problems when nothing was read.
    */
   (*env)->GetByteArrayRegion(env, buffer, offset, length, nativeBuffer);
   
   FT_HANDLE ftHandle = ToNativeHandle(handle);
   FT_STATUS result = FT_Read(ftHandle, &nativeBuffer[offset], (DWORD)length, &numBytesRead);
    
   Logger_Fine("(%s: %i) - FT_Read(%X, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)length, (int)numBytesRead, (int)result); 
    
   if(result != FT_OK){
        HandleError(env, result);
        return -1;
   }
   
   (*env)->SetByteArrayRegion(env, buffer, offset, length, nativeBuffer);
   
   free(nativeBuffer);
   
   return numBytesRead;
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_Device_write
  (JNIEnv *env, jclass deviceClass, jlong handle, jbyteArray buffer, jint offset, jint length){
    
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_OK;
    DWORD totalBytesWritten = 0;
    jbyte* nativeBuffer = (jbyte*)malloc(length * sizeof(jbyte));
   
    (*env)->GetByteArrayRegion(env, buffer, offset, length, nativeBuffer);
   
    if((*env)->ExceptionCheck(env) == JNI_FALSE){
      
        while(result == FT_OK && totalBytesWritten < (DWORD)length){
            DWORD numBytesWritten = 0;
            result = FT_Write(ftHandle, &nativeBuffer[offset], (DWORD)length, &numBytesWritten);
            
            Logger_Fine("(%s: %i) - FT_Write(%X, %i, %u): %i", __FILE__, __LINE__, 
                (unsigned int)ftHandle, (unsigned int)length, (unsigned int)numBytesWritten, (int)result); 
            
            totalBytesWritten += numBytesWritten;
        }
        
        HandleError(env, result);
    }
    
    free(nativeBuffer);   
}

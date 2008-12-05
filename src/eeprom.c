#include "com_ftdichip_ftd2xx_EEPROM.h"

#include <ftd2xx.h>
#include "error.h"
#include "ftd2xxj.h"
#include "deviceDescriptor.h"

#define LOGGER_IMPLEMENTATION
#include "logger.h"

JNIEXPORT jobject JNICALL Java_com_ftdichip_ftd2xx_EEPROM_readDeviceDescriptor
  (JNIEnv *env, jclass eeprom, jlong handle){

     FT_STATUS result = FT_OK;
     FT_HANDLE ftHandle = ToNativeHandle(handle);
          
     char manufacturer[MAX_TEXT_SIZE] = {0};
     char manufacturerID[MAX_TEXT_SIZE] = {0};
     char description[MAX_TEXT_SIZE] = {0};
     char serialNumber[MAX_TEXT_SIZE] = {0};
     
     FT_PROGRAM_DATA data = {0};	
	 data.Signature1 = 0;
	 data.Signature2 = -1;
     data.Manufacturer = manufacturer;
     data.ManufacturerId = manufacturerID;
     data.Description = description;
     data.SerialNumber = serialNumber;
   
     result = FT_EE_Read(ftHandle, &data);  
     
     Logger_Fine("(%s: %i) - FT_EE_Read(%X,[%s, %s, %s, %s]): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, data.Manufacturer, data.ManufacturerId, 
        data.Description, data.SerialNumber, (int)result);
     
     if(result != FT_OK){
         HandleError(env, result);
         return NULL;
     } 

     return CreateDeviceDescriptor(env, &data);
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_EEPROM_writeDeviceDescriptor
  (JNIEnv *env, jclass eeprom, jlong handle, jobject deviceDescriptor){

    FT_STATUS result = FT_OK;
    FT_HANDLE ftHandle = ToNativeHandle(handle);

   char manufacturer[MAX_TEXT_SIZE] = {0};
   char manufacturerID[MAX_TEXT_SIZE] = {0};
   char description[MAX_TEXT_SIZE] = {0};
   char serialNumber[MAX_TEXT_SIZE] = {0};
   FT_PROGRAM_DATA data = {0};
 
   data.Manufacturer = manufacturer;
   data.ManufacturerId = manufacturerID;
   data.Description = description;
   data.SerialNumber = serialNumber;
    
   FillProgramData(env, deviceDescriptor, &data);
   
   result = FT_EE_Program(ftHandle, &data);  
    
   Logger_Fine("(%s: %i) - FT_EE_Program(%X,[%s, %s, %s, %s]): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, data.Manufacturer, data.ManufacturerId, 
        data.Description, data.SerialNumber, (int)result); 
    
   HandleError(env, result);
}

JNIEXPORT jint JNICALL Java_com_ftdichip_ftd2xx_EEPROM_readUserAreaSize
  (JNIEnv *env, jclass eeprom, jlong handle){
     
    DWORD size = 0;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    FT_STATUS result = FT_EE_UASize(ftHandle, &size);
    
    Logger_Fine("(%s: %i) - FT_EE_UASize(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)size, (int)result);
    
    HandleError(env, result);
    
    return (jint)size;
}

JNIEXPORT jint JNICALL Java_com_ftdichip_ftd2xx_EEPROM_readUserArea
  (JNIEnv *env, jclass eeprom, jlong handle, jbyteArray buffer){
      
    FT_STATUS result = FT_OK;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
    DWORD dataLength = (*env)->GetArrayLength(env, buffer);
    DWORD numBytesRead = 0;
    
    jbyte* data = (*env)->GetByteArrayElements(env, buffer, NULL);
    
    result = FT_EE_UARead(ftHandle, (PUCHAR)data, dataLength, &numBytesRead);   
    
    Logger_Fine("(%s: %i) - FT_EE_UARead(%X, %i, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)dataLength, (int)numBytesRead, (int)result);
    
    HandleError(env, result);
    
    (*env)->ReleaseByteArrayElements(env, buffer, data, 0);
    
    return (jint)numBytesRead;     
}

JNIEXPORT void JNICALL Java_com_ftdichip_ftd2xx_EEPROM_writeUserArea
  (JNIEnv *env, jclass eeprom, jlong handle, jbyteArray buffer){

    FT_STATUS result = FT_OK;
    FT_HANDLE ftHandle = ToNativeHandle(handle);
     
    DWORD dataLength = (*env)->GetArrayLength(env, buffer);
    
    jbyte* data = (*env)->GetByteArrayElements(env, buffer, NULL);
    
    result = FT_EE_UAWrite(ftHandle, (PUCHAR)data, (DWORD)dataLength);   
    
    Logger_Fine("(%s: %i) - FT_EE_UAWrite(%X, %i): %i", __FILE__, __LINE__, 
        (unsigned int)ftHandle, (int)dataLength, (int)result);
    
    HandleError(env, result);
    
    (*env)->ReleaseByteArrayElements(env, buffer, data, 0);
}

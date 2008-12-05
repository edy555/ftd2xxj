#include "deviceDescriptor.h"
#include <stdlib.h>
#include <string.h>

static const char STRING_CLASS[] = "java/lang/String";

static const char DEVICE_DESCRIPTOR_CLASS[] = "com/ftdichip/ftd2xx/DeviceDescriptor";
static const char DEVICE_DESCRIPTOR_REV4_CLASS[] = "com/ftdichip/ftd2xx/DeviceDescriptorRev4";
static const char DEVICE_DESCRIPTOR_REV5_CLASS[] = "com/ftdichip/ftd2xx/DeviceDescriptorRev5";


/**
 * Sets a field of type <code>long</code> with in a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @param value
 *      The value to set.
 */
static void SetLongField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName, DWORD value){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
 
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "J");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return;
    }

    (*env)->SetLongField(env, deviceDescriptor, fieldID, value);
}

/**
 * Retrieves the value of a field of type <code>long</code> from a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @return
 *      The value of the field.
 */
static DWORD GetLongField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return 0;
    
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return 0;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "J");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return 0;
    }

    return (DWORD)(*env)->GetLongField(env, deviceDescriptor, fieldID);
}


/**
 * Sets a field of type <code>int</code> with in a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @param value
 *      The value to set.
 */
static void SetIntField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName, WORD value){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "I");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return;
    }

    (*env)->SetIntField(env, deviceDescriptor, fieldID, value);
}

/**
 * Retrieves the value of a field of type <code>int</code> from a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @return
 *      The value of the field.
 */
static WORD GetIntField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return 0;
        
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return 0;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "I");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return 0;
    }

    return (*env)->GetIntField(env, deviceDescriptor, fieldID);
}

/**
 * Sets a field of type <code>boolean</code> with in a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @param value
 *      The value to set.
 */
static void SetBooleanField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName, WORD value){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return; 
        
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "Z");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return;
    }

    (*env)->SetBooleanField(env, deviceDescriptor, fieldID, value);
}

/**
 * Retrieves the value of a field of type <code>boolean</code> from a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @return
 *      The value of the field.
 */
static WORD GetBooleanField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return 0;
        
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return JNI_FALSE;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "Z");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return JNI_FALSE;
    }

    return (*env)->GetBooleanField(env, deviceDescriptor, fieldID);
}

/**
 * Sets a field of type <code>java.lang.String</code> with in a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @param value
 *      The value to set.
 */
static void SetStringField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName, const char* value){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    jstring string = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "Ljava/lang/String;");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return;
    }
    
    string = (*env)->NewStringUTF(env, value);
    if(string == NULL){
        /* an error has already been thrown. */
        return;
    }

    (*env)->SetObjectField(env, deviceDescriptor, fieldID, string);
}

/**
 * Retrieves the value of a field of type <code>java.lang.String</code> from a 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param fieldName
 *      The name of the field to set.
 * 
 * @param buffer
 *      The buffer to copy the java string to.
 */
static void GetStringField(JNIEnv* env, jobject deviceDescriptor, const char* fieldName, char* buffer){
    jclass descClass = NULL;
    jfieldID fieldID = NULL;
    jstring string = NULL;
    const char* utfChars;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
    descClass = (*env)->GetObjectClass(env, deviceDescriptor);
    if(descClass == NULL){
        /* an error has already been thrown. */
        return;
    }
    
    fieldID = (*env)->GetFieldID(env, descClass, fieldName, "Ljava/lang/String;");
    if(fieldID == NULL){
        /* an error has already been thrown. */
        return;
    }

    string = (jstring)(*env)->GetObjectField(env, deviceDescriptor, fieldID);
    utfChars = (*env)->GetStringUTFChars(env, string, NULL);
    
    strcpy(buffer, utfChars);
    
    (*env)->ReleaseStringUTFChars(env, string, utfChars);
}

/**
 * Sets all the fields of a <code>DeviceDescriptorRev4</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param data
 *      The EEPROM data to set.
 */
static void FillDeviceDescriptorRev4Extensions(JNIEnv* env, jobject deviceDescriptor, const FT_PROGRAM_DATA* data){
   
   /* if an exception was thrown do nothing */
   if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
   SetBooleanField(env, deviceDescriptor, "inEndPointIsochronous", data->IsoIn);
   SetBooleanField(env, deviceDescriptor, "outEndPointIsochronous", data->IsoOut);
   SetBooleanField(env, deviceDescriptor, "pullDownEnabled", data->PullDownEnable);
   SetBooleanField(env, deviceDescriptor, "serialNumberEnabled", data->SerNumEnable);
   SetBooleanField(env, deviceDescriptor, "usbVersionEnabled", data->USBVersionEnable);
   SetIntField(env, deviceDescriptor, "usbVersion", data->USBVersion);
}

/**
 * Sets all the fields of a <code>DeviceDescriptorRev5</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param data
 *      The EEPROM data to set.
 */
static void FillDeviceDescriptorRev5Extensions(JNIEnv* env, jobject deviceDescriptor, const FT_PROGRAM_DATA* data){
   
   /* if an exception was thrown do nothing */
   if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
   SetBooleanField(env, deviceDescriptor, "inEndPointAIsochronous", data->IsoInA);
   SetBooleanField(env, deviceDescriptor, "inEndPointBIsochronous", data->IsoInB);
   SetBooleanField(env, deviceDescriptor, "outEndPointAIsochronous", data->IsoOutA);
   SetBooleanField(env, deviceDescriptor, "outEndPointBIsochronous", data->IsoOutB);
   SetBooleanField(env, deviceDescriptor, "pullDownEnabled", data->PullDownEnable5);
   SetBooleanField(env, deviceDescriptor, "serialNumberEnabled", data->SerNumEnable5);
   SetBooleanField(env, deviceDescriptor, "usbVersionEnabled", data->USBVersionEnable5);
   SetIntField(env, deviceDescriptor, "usbVersion", data->USBVersion5);
   SetBooleanField(env, deviceDescriptor, "interfaceAHighCurrent", data->AIsHighCurrent);
   SetBooleanField(env, deviceDescriptor, "interfaceBHighCurrent", data->BIsHighCurrent);
   SetBooleanField(env, deviceDescriptor, "interfaceAFifo", data->IFAIsFifo);
   SetBooleanField(env, deviceDescriptor, "interfaceAFifoCpuTarget", data->IFAIsFifoTar);
   SetBooleanField(env, deviceDescriptor, "interfaceAFastSerial", data->IFAIsFastSer);
   SetBooleanField(env, deviceDescriptor, "interfaceAUseVcpDrivers", data->AIsVCP);
   SetBooleanField(env, deviceDescriptor, "interfaceBFifo", data->IFBIsFifo);
   SetBooleanField(env, deviceDescriptor, "interfaceBFifoCpuTarget", data->IFBIsFifoTar);
   SetBooleanField(env, deviceDescriptor, "interfaceBFastSerial", data->IFBIsFastSer);
   SetBooleanField(env, deviceDescriptor, "interfaceBUseVcpDrivers", data->BIsVCP);
}

/**
 * Sets all the fields of a <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param data
 *      The EEPROM data to determine the kind of device descriptor to create.
 */
static void FillDeviceDescriptor(JNIEnv* env, jobject deviceDescriptor, const FT_PROGRAM_DATA* data){
 
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
    SetLongField(env, deviceDescriptor, "signature1", data->Signature1);
    SetLongField(env, deviceDescriptor, "signature2", data->Signature2);
    SetLongField(env, deviceDescriptor, "version", data->Version);
    SetIntField(env, deviceDescriptor, "vendorID", data->VendorId);
    SetIntField(env, deviceDescriptor, "productID", data->ProductId);
    SetStringField(env, deviceDescriptor, "manufacturer", data->Manufacturer);
    SetStringField(env, deviceDescriptor, "manufacturerID", data->ManufacturerId);
    SetStringField(env, deviceDescriptor, "productDescription", data->Description);
    SetStringField(env, deviceDescriptor, "serialNumber", data->SerialNumber);
    SetIntField(env, deviceDescriptor, "maxPower", data->MaxPower);
    SetBooleanField(env, deviceDescriptor, "pnpEnabled", data->PnP);
    SetBooleanField(env, deviceDescriptor, "selfPowered", data->SelfPowered);
    SetBooleanField(env, deviceDescriptor, "remoteWakeupCapable", data->RemoteWakeup);
 
    if(data->Rev4 != 0){
      FillDeviceDescriptorRev4Extensions(env, deviceDescriptor, data);
    }
    
    if(data->Rev5 != 0){
      FillDeviceDescriptorRev5Extensions(env, deviceDescriptor, data);
    }
}

/**
 * Creates a <code>DeviceDescriptor</code> object or one of it`s sub-classes according 
 * to the revision of the device`s chip.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param data
 *      The EEPROM data to set.
 * 
 * @return
 *      The appropriate device descriptor object.
 */
static jobject CreateDeviceDescriptorObject(JNIEnv* env, const FT_PROGRAM_DATA* data){
    const char* deviceDescriptorClassName = DEVICE_DESCRIPTOR_CLASS;
    jclass deviceDescriptorClass = NULL;
    jmethodID constructor = NULL;
    jobject deviceDescriptor = NULL;
    
    if(data->Rev4 != 0){
        deviceDescriptorClassName = DEVICE_DESCRIPTOR_REV4_CLASS;
    }
    
    if(data->Rev5 != 0){
        deviceDescriptorClassName = DEVICE_DESCRIPTOR_REV5_CLASS;
    }
    
    deviceDescriptorClass = (*env)->FindClass(env, deviceDescriptorClassName);
    if(deviceDescriptorClass == NULL){
      /* an error has already been thrown. */
      return NULL;
    }
     
    constructor = (*env)->GetMethodID(env, deviceDescriptorClass, "<init>", "()V");
    if(deviceDescriptorClass == NULL){
      /* an error has already been thrown. */
      return NULL;
    }
     
    deviceDescriptor = (*env)->NewObject(env, deviceDescriptorClass, constructor);
    if(deviceDescriptor == NULL){
      /* an error has already been thrown. */
      return NULL;
    }
     
    return deviceDescriptor;
}

jobject CreateDeviceDescriptor(JNIEnv* env, const FT_PROGRAM_DATA* data){
    jobject deviceDescriptor = CreateDeviceDescriptorObject(env, data);
    
    FillDeviceDescriptor(env, deviceDescriptor, data);
    
    return deviceDescriptor;
}

/**
 * Fills the revision 5 extensions of the data to write to the EEPROM according 
 * to a particular <code>DeviceDescriptorRev5</code> object.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param data
 *      The data to write to the EEPROM.
 * 
 */
static void FillProgramDataRev5Extensions(JNIEnv* env, jobject deviceDescriptor, FT_PROGRAM_DATA* data){
    
    /*if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
    data->IsoInA = GetBooleanField(env, deviceDescriptor, "inEndPointAIsochronous");
    data->IsoInB = GetBooleanField(env, deviceDescriptor, "inEndPointBIsochronous");
    data->IsoOutA = GetBooleanField(env, deviceDescriptor, "outEndPointAIsochronous");
    data->IsoOutB = GetBooleanField(env, deviceDescriptor, "outEndPointBIsochronous");
    data->PullDownEnable5 = GetBooleanField(env, deviceDescriptor, "pullDownEnabled");
    data->SerNumEnable5 = GetBooleanField(env, deviceDescriptor, "serialNumberEnabled");
    data->USBVersionEnable5 = GetBooleanField(env, deviceDescriptor, "usbVersionEnabled");
    data->USBVersion5 = GetIntField(env, deviceDescriptor, "usbVersion");
    data->AIsHighCurrent = GetBooleanField(env, deviceDescriptor, "interfaceAHighCurrent");
    data->BIsHighCurrent = GetBooleanField(env, deviceDescriptor, "interfaceBHighCurrent");
    data->IFAIsFifo = GetBooleanField(env, deviceDescriptor, "interfaceAFifo");
    data->IFAIsFifoTar = GetBooleanField(env, deviceDescriptor, "interfaceAFifoCpuTarget");
    data->IFAIsFastSer = GetBooleanField(env, deviceDescriptor, "interfaceAFastSerial");
    data->AIsVCP = GetBooleanField(env, deviceDescriptor, "interfaceAUseVcpDrivers");
    data->IFBIsFifo = GetBooleanField(env, deviceDescriptor, "interfaceBFifo");
    data->IFBIsFifoTar = GetBooleanField(env, deviceDescriptor, "interfaceBFifoCpuTarget");
    data->IFBIsFastSer = GetBooleanField(env, deviceDescriptor, "interfaceBFastSerial");
    data->BIsVCP = GetBooleanField(env, deviceDescriptor, "interfaceBUseVcpDrivers");      
}

/**
 * Fills the revision 4 extensions of the data to write to the EEPROM according 
 * to a particular <code>DeviceDescriptorRev4</code> object.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param data
 *      The data to write to the EEPROM.
 * 
 */
static void FillProgramDataRev4Extensions(JNIEnv* env, jobject deviceDescriptor, FT_PROGRAM_DATA* data){
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
        
    data->IsoIn = GetBooleanField(env, deviceDescriptor, "inEndPointIsochronous");
    data->IsoOut = GetBooleanField(env, deviceDescriptor, "outEndPointIsochronous");
    data->PullDownEnable = GetBooleanField(env, deviceDescriptor, "pullDownEnabled");
    data->SerNumEnable = GetBooleanField(env, deviceDescriptor, "serialNumberEnabled");
    data->USBVersionEnable = GetBooleanField(env, deviceDescriptor, "usbVersionEnabled");
    data->USBVersion = GetIntField(env, deviceDescriptor, "usbVersion");
}

/**
 * Determines whether a <code>DeviceDescriptor</code> object is of type 
 * code>DeviceDescriptorRev4</code> or not.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @return
 *      <code>true</code> if it is, <code>false</code> otherwise.
 */
static BOOL IsRev4DeviceDescriptor(JNIEnv* env, jobject deviceDescriptor){
    jclass rev4Class = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return FALSE;
    
    rev4Class = (*env)->FindClass(env, DEVICE_DESCRIPTOR_REV4_CLASS);
    if(rev4Class == NULL){
        /* an error has already been thrown. */
        return FALSE;
    }
    
    return (*env)->IsInstanceOf(env, deviceDescriptor, rev4Class);
}

/**
 * Determines whether a <code>DeviceDescriptor</code> object is of type 
 * code>DeviceDescriptorRev4</code> or not.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @return
 *      <code>true</code> if it is, <code>false</code> otherwise.
 */
static BOOL IsRev5DeviceDescriptor(JNIEnv* env, jobject deviceDescriptor){
    jclass rev5Class = NULL;
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return FALSE;
    
    rev5Class = (*env)->FindClass(env, DEVICE_DESCRIPTOR_REV5_CLASS);
    if(rev5Class == NULL){
        /* an error has already been thrown. */
        return FALSE;
    }
    
    return (*env)->IsInstanceOf(env, deviceDescriptor, rev5Class);
}

/**
 * Fills the data to write to the EEPROM according to a particular
 * <code>DeviceDescriptor</code> object.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The <code>DeviceDescriptor</code> object to operate on.
 * 
 * @param data
 *      The data to write to the EEPROM.
 * 
 */
void FillProgramData(JNIEnv* env, jobject deviceDescriptor, FT_PROGRAM_DATA* data){
    
    /* if an exception was thrown do nothing */
    if((*env)->ExceptionCheck(env) == JNI_TRUE)
        return;
           
    data->Signature1 = GetLongField(env, deviceDescriptor, "signature1");
    data->Signature2 = GetLongField(env, deviceDescriptor, "signature2");
    data->Version = GetLongField(env, deviceDescriptor, "version");
    data->VendorId = GetIntField(env, deviceDescriptor, "vendorID");
    data->ProductId = GetIntField(env, deviceDescriptor, "productID");
    
    GetStringField(env, deviceDescriptor, "manufacturer", data->Manufacturer);    
    GetStringField(env, deviceDescriptor, "manufacturerID", data->ManufacturerId);
    GetStringField(env, deviceDescriptor, "productDescription", data->Description);
    GetStringField(env, deviceDescriptor, "serialNumber", data->SerialNumber);
    
    data->MaxPower = GetIntField(env, deviceDescriptor, "maxPower");
    data->PnP = GetBooleanField(env, deviceDescriptor, "pnpEnabled");
    data->SelfPowered = GetBooleanField(env, deviceDescriptor, "selfPowered");
    data->RemoteWakeup = GetBooleanField(env, deviceDescriptor, "remoteWakeupCapable");
 
    if(IsRev4DeviceDescriptor(env, deviceDescriptor)){
      FillProgramDataRev4Extensions(env, deviceDescriptor, data);
    }
    
    if(IsRev5DeviceDescriptor(env, deviceDescriptor)){
      FillProgramDataRev5Extensions(env, deviceDescriptor, data);
    }
}

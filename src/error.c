#include <stdlib.h>

#include "error.h"

static const char FTSTATUS_CLASS_NAME[] = "com/ftdichip/ftd2xx/FTStatus";
static const char FTSTATUS_THROW_EXCEPTION_METHOD_NAME[] = "throwException";
static const char FTSTATUS_THROW_EXCEPTION_METHOD_DESC[] = "(I)V";

void HandleError(JNIEnv* env, FT_STATUS error){
    jclass ftStatusClass = NULL;
    jmethodID methodID = NULL;
         
    if(error == FT_OK)
        return;        
         
    ftStatusClass = (*env)->FindClass(env, FTSTATUS_CLASS_NAME);
    if(ftStatusClass == NULL){
        /* an error has already been thrown. */
        return;
    }     

    methodID = (*env)->GetStaticMethodID(env, ftStatusClass, FTSTATUS_THROW_EXCEPTION_METHOD_NAME, FTSTATUS_THROW_EXCEPTION_METHOD_DESC);
    if(methodID == NULL){
        /* an error has already been thrown. */
        return;
    }

    (*env)->CallStaticVoidMethod(env, ftStatusClass, methodID, error);
}

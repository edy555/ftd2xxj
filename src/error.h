/**
 * Provides functions to convert an error code into the apropriate error text 
 * and throwing the associated (Java) exception. 
 */

#ifndef ERROR_H
#define ERROR_H

#include <jni.h>
#include <ftd2xx.h>

#ifdef __cplusplus__
extern "C" {
#endif

/**
 * Throws an exception accociated with a ftd2xx error.
 * 
 * @param JNIEnv
 *      the JNI environment to throw the error on.
 * 
 * @param error 
 *      the error code for which to throw an exception.
 */
void HandleError(JNIEnv* env, FT_STATUS error);

#ifdef __cplusplus__
} /* extern "C" */
#endif
#endif /* ERROR_H */

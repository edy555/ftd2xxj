#ifndef FTD2XXJ_H
#define FTD2XXJ_H

#include <jni.h>
#include <ftd2xx.h>

#define MAX_TEXT_SIZE 100

#ifdef __cplusplus__
	extern "C" {
#endif


/**
 * Converts a java representation of a device handle to one compatible with the 
 * ftd2xx API.
 * 
 * @param handle
 *      the java handle.
 * 
 * @return the ftd2xx compatible handle.
 */
FT_HANDLE ToNativeHandle(jlong handle);

/**
 * Converts a ftd2xx device handle to a java representation.
 * 
 * @param handle
 *      the device handle.
 * 
 * @return the java representation.
 */
jlong ToJavaHandle(FT_HANDLE handle);

#ifdef __cplusplus__
} /* extern "C" */
#endif
#endif /* FTD2XXJ_H */

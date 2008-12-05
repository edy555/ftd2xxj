#ifndef DEVICE_DESCRIPTOR_H
#define DEVICE_DESCRIPTOR_H

#include <jni.h>
#include <ftd2xx.h>
#include "ftd2xxj.h"

#ifdef __cplusplus__
extern "C" {
#endif

/**
 * Creates a <code>DeviceDescriptor</code> object or one of it`s sub-classes according 
 * to the revision of the device`s chip and fills it`s fields with the device`s
 * EEPROM data.
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
jobject CreateDeviceDescriptor(JNIEnv* env, const FT_PROGRAM_DATA* data);

/**
 * Fills the EEPROM program data according to a particular 
 * <code>DeviceDescriptor</code>.
 * 
 * @param env
 *      The JNI environment pointer.
 * 
 * @param deviceDescriptor
 *      The device descriptor from which to retrieve the information.
 * 
 * @param data
 *      The EEPROM data to fill. 
 */
void FillProgramData(JNIEnv* env, jobject deviceDescriptor, FT_PROGRAM_DATA* data);

#ifdef __cplusplus__
} /* extern "C" */
#endif
#endif /* DEVICE_DESCRIPTOR_H */

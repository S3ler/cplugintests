//
// Created by SomeDude on 04.04.2019.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

/* Not mandatory in this example since we define the function here.
 *
 * But still getOneFromPluginFunction good idea to ensure that the prototypes are compatible.
 *
 * Often required because of header struct declarations.
 */
#include "plugin_interface.h"

int getOneFromPluginFunction (void)
{
  return 1;
}

int writeOnesIntoUint8Array (uint8_t *array, uint16_t array_length)
{
  memset (array, 1, array_length);
  return 1;
}

SharedData getSharedDataFromUint8Array (uint8_t *array, uint16_t array_length)
{
  SharedData sharedData = {0};
  assert(array_length <= SHARED_DATA_MAX_DATA_LENGTH);
  memcpy (sharedData.data, array, array_length);
  sharedData.data_length = array_length;
  return sharedData;
}


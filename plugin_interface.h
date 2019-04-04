//
// Created by SomeDude on 04.04.2019.
//

#ifndef CPLUGINTESTS_PLUGIN_INTERFACE_H
#define CPLUGINTESTS_PLUGIN_INTERFACE_H

#include <stdint.h>

#define SHARED_DATA_MAX_DATA_LENGTH 4

typedef struct SharedData_ {
  uint8_t data[SHARED_DATA_MAX_DATA_LENGTH];
  uint16_t data_length;
} SharedData;

int getOneFromPluginFunction (void);

int writeOnesIntoUint8Array (uint8_t *array, uint16_t array_length);

SharedData getSharedDataFromUint8Array(uint8_t *array, uint16_t array_length);

#endif //CPLUGINTESTS_PLUGIN_INTERFACE_H


#include <assert.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "plugin_interface.h"

int main ()
{
  void *handle;
  char *error;

  handle = dlopen ("/tmp/tmp.PcsjwwYX3D/cmake-build-debug/libplugin_implementation.so", RTLD_LAZY);
  if (!handle)
    {
      fprintf (stderr, "%s\n", dlerror ());
      exit (EXIT_FAILURE);
    }
  dlerror ();
  int (*getOneFromPluginFunction) (void);
  getOneFromPluginFunction = (int (*) (void)) dlsym (handle, "getOneFromPluginFunction");
  error = dlerror ();
  if (error != NULL)
    {
      fprintf (stderr, "%s\n", error);
      exit (EXIT_FAILURE);
    }
  assert(getOneFromPluginFunction () == 1);
  dlclose (handle);

  handle = dlopen ("/tmp/tmp.PcsjwwYX3D/cmake-build-debug/libplugin_implementation.so", RTLD_LAZY);
  if (!handle)
    {
      fprintf (stderr, "%s\n", dlerror ());
      exit (EXIT_FAILURE);
    }
  dlerror ();
  int (*writeOnesIntoUint8Array) (uint8_t *array, uint16_t array_length);
  writeOnesIntoUint8Array = (int (*) (uint8_t *array, uint16_t array_length)) dlsym (handle, "writeOnesIntoUint8Array");
  error = dlerror ();
  if (error != NULL)
    {
      fprintf (stderr, "%s\n", error);
      exit (EXIT_FAILURE);
    }
  uint16_t array_length = 4;
  uint8_t array[4] = {0};
  assert(writeOnesIntoUint8Array ((uint8_t *) &array, array_length) == 1);

  dlclose (handle);

  handle = dlopen ("/tmp/tmp.PcsjwwYX3D/cmake-build-debug/libplugin_implementation.so", RTLD_LAZY);
  if (!handle)
    {
      fprintf (stderr, "%s\n", dlerror ());
      exit (EXIT_FAILURE);
    }
  dlerror ();
  SharedData (*getSharedDataFromUint8Array) (uint8_t *array, uint16_t array_length);
  getSharedDataFromUint8Array = (SharedData (*) (uint8_t *array, uint16_t array_length)) dlsym (handle, "getSharedDataFromUint8Array");
  error = dlerror ();
  if (error != NULL)
    {
      fprintf (stderr, "%s\n", error);
      exit (EXIT_FAILURE);
    }
  SharedData sharedData = getSharedDataFromUint8Array ((uint8_t *) &array, array_length);
  dlclose (handle);

  return EXIT_SUCCESS;
}

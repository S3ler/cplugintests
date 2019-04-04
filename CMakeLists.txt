cmake_minimum_required(VERSION 3.14)
project(cplugintests C)

set(CMAKE_C_STANDARD 99)

add_executable(cplugintests main.c plugin_interface.h)
target_link_libraries(cplugintests dl)

set(PLUGIN_LIBRARY_SRC plugin_implementation.c)
add_library(plugin_implementation SHARED ${PLUGIN_LIBRARY_SRC})

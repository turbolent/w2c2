cmake_minimum_required(VERSION 3.16)
project(w2c2_wasi_testsuite C)

set(CMAKE_C_STANDARD 90)
get_filename_component(W2C2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
add_subdirectory("${W2C2_ROOT}/wasi" wasi EXCLUDE_FROM_ALL)
target_compile_definitions(w2c2wasi PUBLIC W2C2_RUNTIME_CHECKS=1)
# Keep the WASI library's warning flags on its own sources.
set_property(TARGET w2c2wasi PROPERTY INTERFACE_COMPILE_OPTIONS "")

include("${CMAKE_BINARY_DIR}/cases.cmake")

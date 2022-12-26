cmake_minimum_required(VERSION 2.8.12)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(w2c2)

set(CMAKE_C_STANDARD 90)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
    pkg_check_modules(DWARF libdwarf)
endif()

check_include_file (getopt.h HAVE_GETOPT_H)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

FILE(GLOB SOURCES *.c)
FILE(GLOB TEST_SOURCES test.c *_test.c)
list(REMOVE_ITEM SOURCES ${TEST_SOURCES})

FILE(GLOB WASI_SOURCES wasi/*.c)
FILE(GLOB WASI_TEST_SOURCES wasi/test.c wasi/*_test.c)
list(REMOVE_ITEM WASI_SOURCES ${WASI_TEST_SOURCES})

add_executable(w2c2 ${SOURCES})
add_library(wasi ${WASI_SOURCES})

add_library(common INTERFACE)
target_compile_options(common INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wunused-result -Wno-long-long -Wno-unused-function>
)
target_link_libraries(w2c2 PRIVATE common)
target_link_libraries(wasi PRIVATE common)

if(DWARF_FOUND)
    target_compile_definitions(w2c2 PUBLIC HAS_LIBDWARF=1)
    target_include_directories(w2c2 PUBLIC ${DWARF_INCLUDE_DIRS})
    target_link_directories(w2c2 PUBLIC ${DWARF_LIBRARY_DIRS})
    target_link_libraries(w2c2 PUBLIC ${DWARF_LIBRARIES})
endif()

if(Threads_FOUND AND CMAKE_USE_PTHREADS_INIT)
    target_compile_definitions(w2c2 PUBLIC HAS_PTHREAD=1)
    target_link_libraries(w2c2 PUBLIC Threads::Threads)
endif()

if (HAVE_GETOPT_H)
    target_compile_definitions(w2c2 PUBLIC HAS_GETOPT=1)
endif()

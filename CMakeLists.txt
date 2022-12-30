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

include(CheckIncludeFile)
check_include_file(getopt.h HAVE_GETOPT_H)
check_include_file(libgen.h HAVE_LIBGEN_H)
check_include_file(unistd.h HAVE_UNISTD_H)

include(CheckSymbolExists)
check_symbol_exists(strdup string.h HAVE_STRDUP)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

FILE(GLOB SOURCES *.c)
FILE(GLOB TEST_SOURCES test.c *_test.c)
list(REMOVE_ITEM SOURCES ${TEST_SOURCES})

add_executable(w2c2 ${SOURCES})

target_compile_options(w2c2 PUBLIC
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wunused-result -Wno-long-long -Wno-unused-function>
)

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

if(HAVE_UNISTD_H)
    target_compile_definitions(w2c2 PUBLIC HAS_UNISTD=1)
endif()

if(HAVE_GETOPT_H)
    target_compile_definitions(w2c2 PUBLIC HAS_GETOPT=1)
endif()

if(HAVE_LIBGEN_H)
    target_compile_definitions(w2c2 PUBLIC HAS_LIBGEN=1)
endif()

if(HAVE_STRDUP)
    target_compile_definitions(w2c2 PUBLIC HAS_STRDUP=1)
endif()

if(MSVC)
    target_compile_definitions(w2c2 PUBLIC _CRT_SECURE_NO_DEPRECATE)
endif()

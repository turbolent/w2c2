cmake_minimum_required(VERSION 2.8.12)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(w2c2futex)

set(CMAKE_C_STANDARD 90)
set(SHARED_LIB 0 CACHE BOOL "Build as a shared library")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

include(CheckIncludeFile)
check_include_file(unistd.h HAVE_UNISTD_H)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

FILE(GLOB SOURCES *.c)
FILE(GLOB TEST_SOURCES test.c *_test.c)
list(REMOVE_ITEM SOURCES ${TEST_SOURCES})

if (${SHARED_LIB})
	add_library(w2c2futex SHARED ${SOURCES})
else()
	add_library(w2c2futex STATIC ${SOURCES})
endif()

add_executable(w2c2futex_test ${TEST_SOURCES} ${SOURCES})

foreach(TARGET w2c2futex w2c2futex_test)
    target_compile_options(${TARGET} PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wunused-result -Wno-long-long -Wno-unused-function>
    )

    if(Threads_FOUND)
        if(CMAKE_USE_PTHREADS_INIT)
            target_compile_definitions(${TARGET} PUBLIC WASM_THREADS_PTHREADS)
        elseif(CMAKE_USE_WIN32_THREADS_INIT)
            target_compile_definitions(${TARGET} PUBLIC WASM_THREADS_WIN32)
        endif()
        target_link_libraries(${TARGET} PUBLIC Threads::Threads)
    endif()

    if(HAVE_UNISTD_H)
        target_compile_definitions(${TARGET} PUBLIC HAS_UNISTD=1)
    endif()

    if(MSVC)
        target_compile_definitions(${TARGET} PUBLIC _CRT_SECURE_NO_DEPRECATE)
    endif()
endforeach()

cmake_minimum_required(VERSION 2.8.12)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(w2c2wasi)

set(CMAKE_C_STANDARD 90)
set(SHARED_LIB 0 CACHE BOOL "Build as a shared library")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

include(CheckIncludeFile)
check_include_file(unistd.h HAVE_UNISTD_H)
check_include_file(sys/uio.h HAVE_SYSUIO_H)
check_include_file(sys/time.h HAVE_SYSTIME_H)
check_include_file(sys/resource.h HAVE_SYSRESOURCE_H)

include(CheckSymbolExists)
check_symbol_exists(strndup string.h HAVE_STRNDUP)
check_symbol_exists(fcntl fcntl.h HAVE_FCNTL)
check_symbol_exists(lstat "sys/stat.h" HAVE_LSTAT)
check_symbol_exists(getentropy unistd.h HAVE_GETENTROPY)

include(CheckStructHasMember)
check_struct_has_member("struct timespec" tv_sec time.h HAVE_TIMESPEC)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

FILE(GLOB SOURCES *.c)
FILE(GLOB TEST_SOURCES test.c *_test.c)
list(REMOVE_ITEM SOURCES ${TEST_SOURCES})

if (${SHARED_LIB})
	add_library(w2c2wasi SHARED ${SOURCES})
else()
	add_library(w2c2wasi STATIC ${SOURCES})
endif()

add_executable(w2c2wasi_test ${TEST_SOURCES} ${SOURCES})

foreach(TARGET w2c2wasi w2c2wasi_test)
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

    if(HAVE_SYSUIO_H)
        target_compile_definitions(${TARGET} PUBLIC HAS_SYSUIO=1)
    endif()

    if(HAVE_SYSTIME_H)
        target_compile_definitions(${TARGET} PUBLIC HAS_SYSTIME=1)
    endif()

    if(HAVE_SYSRESOURCE_H)
        target_compile_definitions(${TARGET} PUBLIC HAS_SYSRESOURCE=1)
    endif()

    if(HAVE_STRNDUP)
        target_compile_definitions(${TARGET} PUBLIC HAS_STRNDUP=1)
    endif()

    if(HAVE_FCNTL)
        target_compile_definitions(${TARGET} PUBLIC HAS_FCNTL=1)
    endif()

    if(HAVE_LSTAT)
        target_compile_definitions(${TARGET} PUBLIC HAS_LSTAT=1)
    endif()

    if(HAVE_GETENTROPY)
        target_compile_definitions(${TARGET} PUBLIC HAS_GETENTROPY=1)
    endif()

    if(HAVE_TIMESPEC)
        target_compile_definitions(${TARGET} PUBLIC HAS_TIMESPEC=1)
    endif()

    if(MSVC)
        target_compile_definitions(${TARGET} PUBLIC _CRT_SECURE_NO_DEPRECATE)
    endif()
endforeach()

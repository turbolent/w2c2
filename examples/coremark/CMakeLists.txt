cmake_minimum_required(VERSION 2.8.12)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(coremark)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(coremark coremark.c main.c)

set(CFLAGS
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wunused-result -Wno-long-long -Wno-unused-function>
)

add_custom_command(
    OUTPUT coremark.c
    COMMAND
        ${CMAKE_CURRENT_SOURCE_DIR}/../../w2c2/build/w2c2${CMAKE_EXECUTABLE_SUFFIX}
        ${CMAKE_CURRENT_SOURCE_DIR}/coremark.wasm
        coremark.c
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/coremark.wasm
)

target_include_directories(coremark PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../w2c2
    ${CMAKE_CURRENT_BINARY_DIR}/.
)

target_compile_options(coremark PUBLIC ${CFLAGS})

find_library(WASI
    NAMES wasi
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../wasi/build
)
target_link_libraries(coremark PUBLIC ${WASI})

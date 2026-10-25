cmake_minimum_required(VERSION 2.8.12...3.5)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(rust-wasi)

execute_process(COMMAND
    ${CMAKE_CURRENT_SOURCE_DIR}/../../w2c2/build/w2c2${HOST_EXECUTABLE_SUFFIX}
    -f 100
    ${CMAKE_CURRENT_SOURCE_DIR}/target/wasm32-wasi/debug/rust-wasi.wasm
    rustwasi.c
)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

file(GLOB SOURCES main.c ${CMAKE_CURRENT_BINARY_DIR}/*.c)

add_executable(rust-wasi ${SOURCES})

set(CFLAGS
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wunused-result -Wno-long-long -Wno-unused-function>
)

target_include_directories(rust-wasi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../w2c2
    ${CMAKE_CURRENT_BINARY_DIR}/.
)

target_compile_options(rust-wasi PUBLIC ${CFLAGS})

find_library(W2C2WASI
    NAMES w2c2wasi
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../wasi/build
)
target_link_libraries(rust-wasi PUBLIC ${W2C2WASI})

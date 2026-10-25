cmake_minimum_required(VERSION 2.8.12...3.5)
project(dino)
include_directories(../..)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/dino.c
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../w2c2/w2c2 ${CMAKE_CURRENT_SOURCE_DIR}/dino.wasm ${CMAKE_CURRENT_SOURCE_DIR}/dino.c
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/dino.wasm
    VERBATIM
)

add_executable(
    dino
    MACOSX_BUNDLE
    dino.c
    AppDelegate.m
    DinoView.m
    main.m
)

set_target_properties(
    dino
    PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST
    ${CMAKE_CURRENT_LIST_DIR}/plist.in
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework AppKit")

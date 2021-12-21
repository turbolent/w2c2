cmake_minimum_required(VERSION 2.8.8)
project(dino)

include_directories(../..)

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

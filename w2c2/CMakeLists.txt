cmake_minimum_required(VERSION 2.8.12...3.5)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(w2c2)

set(CMAKE_C_STANDARD 90)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

if((NOT DWARF_FOUND) AND (NOT CMAKE_CROSSCOMPILING))
    find_package(PkgConfig)
    if(PKG_CONFIG_FOUND)
        pkg_check_modules(DWARF libdwarf)
    endif()
endif()

include(CheckIncludeFile)
check_include_file(getopt.h HAVE_GETOPT_H)
check_include_file(libgen.h HAVE_LIBGEN_H)
check_include_file(unistd.h HAVE_UNISTD_H)
check_include_file(glob.h HAVE_GLOB_H)

include(CheckSymbolExists)
check_symbol_exists(strdup string.h HAVE_STRDUP)

set(CMAKE_C_FLAGS_DEBUG "-g -O1")
set(CMAKE_C_FLAGS_RELEASE "-O3")

option(SHARED_LIB "Build as a shared library" OFF)
if(SHARED_LIB AND (WIN32 OR NOT UNIX))
    message(FATAL_ERROR "Shared w2c2 libraries are supported only on POSIX systems")
endif()

file(GLOB SOURCES *.c)
file(GLOB TEST_SOURCES test.c *_test.c)
set(CLI_SOURCES main.c compat.c file.c)
list(REMOVE_ITEM SOURCES ${TEST_SOURCES})
foreach(SOURCE ${CLI_SOURCES})
    list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE})
endforeach()

if(SHARED_LIB)
    add_library(w2c2_lib SHARED ${SOURCES})
else()
    add_library(w2c2_lib STATIC ${SOURCES})
endif()
set_target_properties(w2c2_lib PROPERTIES OUTPUT_NAME w2c2)
add_library(w2c2::w2c2_lib ALIAS w2c2_lib)

include(GNUInstallDirs)
target_include_directories(w2c2_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/w2c2>
)

if(SHARED_LIB)
    file(RELATIVE_PATH LIBRARY_FROM_BIN
        "${CMAKE_INSTALL_FULL_BINDIR}" "${CMAKE_INSTALL_FULL_LIBDIR}")
    if(APPLE)
        set_target_properties(w2c2_lib PROPERTIES MACOSX_RPATH ON)
        set(CMAKE_INSTALL_RPATH "@loader_path/${LIBRARY_FROM_BIN}")
    else()
        set(CMAKE_INSTALL_RPATH "$ORIGIN/${LIBRARY_FROM_BIN}")
    endif()
endif()

add_executable(w2c2 ${CLI_SOURCES})
target_link_libraries(w2c2 w2c2_lib)
add_executable(w2c2_test ${TEST_SOURCES} file.c)
target_link_libraries(w2c2_test w2c2_lib)

enable_testing()
add_test(NAME unit COMMAND w2c2_test)
add_executable(w2c2_embed ../examples/embed/main.c)
target_link_libraries(w2c2_embed w2c2_lib)
add_test(NAME embed COMMAND w2c2_embed)
add_subdirectory(../tests/embedding ${CMAKE_CURRENT_BINARY_DIR}/embedding)

if(DWARF_FOUND)
    set(W2C2_DWARF_DEPENDENCIES "")
    foreach(LIBRARY ${DWARF_LIBRARIES})
        if(IS_ABSOLUTE "${LIBRARY}")
            get_filename_component(NAME "${LIBRARY}" NAME_WE)
            string(REGEX REPLACE "^lib" "" NAME "${NAME}")
            set(DEPENDENCY "${LIBRARY}")
        else()
            string(REGEX REPLACE "^-l" "" NAME "${LIBRARY}")
            find_library(W2C2_${NAME}_LIBRARY NAMES ${NAME}
                HINTS ${DWARF_LIBRARY_DIRS})
            if(NOT W2C2_${NAME}_LIBRARY)
                message(FATAL_ERROR "libdwarf dependency not found: ${NAME}")
            endif()
            set(DEPENDENCY "${W2C2_${NAME}_LIBRARY}")
        endif()
        list(APPEND W2C2_DWARF_DEPENDENCIES ${NAME})
        target_link_libraries(w2c2_lib PUBLIC "$<BUILD_INTERFACE:${DEPENDENCY}>")
    endforeach()
endif()

set(W2C2_USE_THREADS_TARGET OFF)
if(Threads_FOUND AND CMAKE_USE_PTHREADS_INIT)
    if(TARGET Threads::Threads)
        set(W2C2_USE_THREADS_TARGET ON)
        target_link_libraries(w2c2_lib PUBLIC Threads::Threads)
    else()
        target_link_libraries(w2c2_lib PUBLIC ${CMAKE_THREAD_LIBS_INIT})
    endif()
endif()
if(UNIX)
    target_link_libraries(w2c2_lib PUBLIC m)
endif()

foreach(TARGET w2c2_lib w2c2 w2c2_test)
    if(MSVC)
        target_compile_options(${TARGET} PRIVATE /W4)
        target_compile_definitions(${TARGET} PRIVATE _CRT_SECURE_NO_DEPRECATE)
    else()
        target_compile_options(${TARGET} PRIVATE
            -Wall -Werror=conversion -Wextra -Wpedantic -Wunused-result
            -Wno-long-long -Wno-unused-function)
    endif()

    if(DWARF_FOUND)
        if(DWARF_OLD)
            target_compile_definitions(${TARGET} PRIVATE HAS_OLD_LIBDWARF=1)
        else()
            target_compile_definitions(${TARGET} PRIVATE HAS_LIBDWARF=1)
        endif()
        target_include_directories(${TARGET} PRIVATE ${DWARF_INCLUDE_DIRS})
    endif()
    if(Threads_FOUND AND CMAKE_USE_PTHREADS_INIT)
        target_compile_definitions(${TARGET} PRIVATE HAS_PTHREAD=1)
    endif()
    foreach(FEATURE UNISTD GETOPT LIBGEN GLOB)
        if(HAVE_${FEATURE}_H)
            target_compile_definitions(${TARGET} PRIVATE HAS_${FEATURE}=1)
        endif()
    endforeach()
    if(HAVE_STRDUP)
        target_compile_definitions(${TARGET} PRIVATE HAS_STRDUP=1)
    endif()
endforeach()

file(STRINGS public_headers.txt PUBLIC_HEADERS)
install(TARGETS w2c2 w2c2_lib EXPORT w2c2Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/w2c2)

include(CMakePackageConfigHelpers)
configure_package_config_file(w2c2Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/w2c2Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/w2c2)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/w2c2Config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/w2c2)
install(EXPORT w2c2Targets NAMESPACE w2c2::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/w2c2)

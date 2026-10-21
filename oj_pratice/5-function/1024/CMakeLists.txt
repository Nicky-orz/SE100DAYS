cmake_minimum_required(VERSION 3.28)
project(1024 LANGUAGES C)

set(SOURCE_DIR_NAME "src")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_DIR_NAME}")

set(INCLUDE_DIR_NAME "include")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR_NAME}")

if (NOT IS_DIRECTORY "${SOURCE_DIR}")
    message(FATAL_ERROR
            "Source directory '${SOURCE_DIR_NAME}' not found under ${CMAKE_CURRENT_SOURCE_DIR}")
endif ()

if (NOT IS_DIRECTORY "${INCLUDE_DIR}")
    message(FATAL_ERROR
            "Include directory '${INCLUDE_DIR_NAME}' not found under ${CMAKE_CURRENT_SOURCE_DIR}")
endif ()

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
        "${SOURCE_DIR}/*.c"
)

if (NOT PROJECT_SOURCES)
    message(FATAL_ERROR
            "No .c files found in '${SOURCE_DIR_NAME}'. Check the directory contents.")
endif ()

message(STATUS "Collected ${SOURCE_DIR_NAME} sources:")
foreach (src IN LISTS PROJECT_SOURCES)
    message(STATUS "  ${src}")
endforeach ()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${INCLUDE_DIR}")
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
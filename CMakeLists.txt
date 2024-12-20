cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico_env_mon C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_library(nyna
    src/nyna/fixed12.cpp
    src/nyna/graphics/common.cpp
)

target_include_directories(nyna PRIVATE
    "include"
)

add_subdirectory(examples)

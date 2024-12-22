cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico_env_mon C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_library(nyna "")

target_include_directories(nyna
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB CPP_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nyna/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nyna/graphics/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nyna/graphics/fonts/*.cpp
)

target_sources(nyna
    PRIVATE
        ${CPP_FILES}
)

add_subdirectory(examples)

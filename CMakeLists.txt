################################################################################
# USE THIS IF YOU DON'T FEEL LIKE MAKING COMPLICATED MAKEFILES BY HAND.
################################################################################

cmake_minimum_required(VERSION 3.16)
project(perfkit VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(perfkit INTERFACE)

target_include_directories(perfkit INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Optional: Toggle examples
option(BUILD_EXAMPLES "Build examples" ON)
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
## | EOF | ##
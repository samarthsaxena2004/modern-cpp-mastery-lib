cmake_minimum_required(VERSION 3.16)
project(ModernCppMasteryLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header-only library target
add_library(moderncppmastery INTERFACE)
target_include_directories(moderncppmastery INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Demo executable
add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE moderncppmastery)

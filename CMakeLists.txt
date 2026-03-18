cmake_minimum_required(VERSION 3.16)
project(ModernCppMasteryLib LANGUAGES CXX)

# Use C++17 (exactly what Honeywell asks for)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header-only library (INTERFACE)
add_library(moderncppmastery INTERFACE)
target_include_directories(moderncppmastery INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Demo executable
add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE moderncppmastery)

# Enable warnings + sanitizers (great for learning memory safety)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(demo PRIVATE -Wall -Wextra -Wpedantic -fsanitize=address,undefined)
    target_link_options(demo PRIVATE -fsanitize=address,undefined)
endif()

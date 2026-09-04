cmake_minimum_required(VERSION 3.12)
project(MTRX3760_LAB_2 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Include header files directory
include_directories(inc)

# CONFIGURE_DEPENDS forces CMake to re-glob when new source files are added
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Find Raylib library and link it to the executable
find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Adding the Maps to the build because im lazy
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/SimpleWalls.map DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/SimpleLine.map DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
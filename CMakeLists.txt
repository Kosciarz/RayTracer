cmake_minimum_required(VERSION 3.20)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)  # Disable raylib examples
set(RAYLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)  # For newer versions of raylib

project("RayTracer" LANGUAGES CXX VERSION 0.0.1)

add_subdirectory(external/raylib)

add_executable(${PROJECT_NAME} "src/Main.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE external/raylib/src)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)


if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
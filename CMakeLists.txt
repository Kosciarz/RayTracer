cmake_minimum_required(VERSION 3.20)

project("RayTracer" VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

message(STATUS "Output dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Library dir: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "Archive dir: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

# Export compile commands for IDEs and tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
	glfw3
	GIT_REPOSITORY https://github.com/glfw/glfw
	GIT_TAG latest
	GIT_SHALLOW ON
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm
	GIT_TAG 1.0.1 
	GIT_SHALLOW ON
)

FetchContent_Declare(
	glad
	GIT_REPOSITORY https://github.com/Dav1dde/glad
	GIT_TAG v2.0.8
	GIT_SHALLOW ON
)

find_package(OpenGL REQUIRED)

set(STB_IMAGE_DIR ${CMAKE_BINARY_DIR}/external/stb)
if(NOT EXISTS ${STB_IMAGE_DIR}/stb_image.h)
	file(
		DOWNLOAD
		https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
		${STB_IMAGE_DIR}/stb_image.h
		TLS_VERIFY ON
	)
endif()

FetchContent_Declare(
	imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui/
	GIT_TAG v1.91.9b-docking
	GIT_SHALLOW ON
)

FetchContent_MakeAvailable(glfw3 glm glad imgui)

add_subdirectory("${glad_SOURCE_DIR}/cmake" glad_cmake)
glad_add_library(glad REPRODUCIBLE EXCLUDE_FROM_ALL LOADER API gl:core=4.6)

add_subdirectory(src)
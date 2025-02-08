cmake_minimum_required(VERSION 3.20)



project("RayTracer" LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCES
    "src/Main.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
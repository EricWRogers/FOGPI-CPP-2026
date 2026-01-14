cmake_minimum_required(VERSION 3.5)
project(fogpi)

set(CMAKE_C_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}/>)

file(GLOB_RECURSE SRC_SOURCES src/*.c)
file(GLOB_RECURSE SRC_HEADERS src/*.h)

add_executable(${PROJECT_NAME} ${SRC_SOURCES} ${SRC_HEADERS})

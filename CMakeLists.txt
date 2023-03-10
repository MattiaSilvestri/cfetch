cmake_minimum_required(VERSION 3.25.2)
project(cfetch)

#Bring the headers into the project
include_directories(src)

file(GLOB SOURCES "src/*.cpp" "src/modules/*.cpp")

add_executable(cfetch ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH "../bin/")

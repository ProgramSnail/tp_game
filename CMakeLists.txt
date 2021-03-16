cmake_minimum_required(VERSION 3.10)

project(Game)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(SOURCES main.cpp)

add_executable(Game ${SOURCS})
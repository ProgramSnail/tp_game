cmake_minimum_required(VERSION 3.10)

project(Game)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(SOURCES main.cpp)

add_executable(Game ${SOURCES})
target_link_libraries(Game ${CURSES_LIBRARIES})
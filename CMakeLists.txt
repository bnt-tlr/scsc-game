cmake_minimum_required(VERSION 3.20)
project(Game VERSION 1.0 LANGUAGES CXX)

find_package(SFML REQUIRED system window graphics)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(Game ${SRC_FILES})
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SFML_INCLUDE_DIR})
target_link_libraries(Game sfml-graphics sfml-window)

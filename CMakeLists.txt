cmake_minimum_required(VERSION 3.0.0)
project(cpp_sand_game VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cpp_sand_game main.cpp)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(cpp_sand_game sfml-graphics sfml-audio)

target_link_directories(cpp_sand_game PUBLIC particles/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

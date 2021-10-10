cmake_minimum_required(VERSION 3.0.0)
project(cpp_sand_game VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE inc)



find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)



add_subdirectory(libs/PE)
target_link_libraries(${PROJECT_NAME} pe)
target_include_directories(${PROJECT_NAME} PRIVATE libs/PE/inc)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

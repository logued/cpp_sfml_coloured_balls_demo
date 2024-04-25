cmake_minimum_required(VERSION 3.28)
project(cpp_sfml_coloured_balls_demo)

set(CMAKE_CXX_STANDARD 17)


add_executable(cpp_sfml_coloured_balls_demo main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/64bit/SFML-2.6.0/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/64bit/SFML-2.6.0/include)
target_link_libraries(cpp_sfml_coloured_balls_demo sfml-system sfml-window sfml-graphics sfml-audio)
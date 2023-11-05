cmake_minimum_required(VERSION 3.26)
project(2015)

set(CMAKE_CXX_STANDARD 20)


find_package(cryptopp CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)


add_executable(day01 day01/main.cpp
)
add_executable(day02 day02/main.cpp)
add_executable(day03 day03/main.cpp)

add_executable(day04 day04/main.cpp
        day04/main.cpp)
target_link_libraries(day04 PRIVATE cryptopp::cryptopp)

add_executable(day05 day05/main.cpp)
add_executable(day06 day06/main.cpp)
add_executable(day07 day07/main.cpp
        day07/Parser.cpp
        day07/Parser.h)
add_executable(day08 day08/main.cpp)
add_executable(day09 day09/main.cpp
        day09/Cities.h)
add_executable(day10 day10/main.cpp)
add_executable(day11 day11/main.cpp
        day11/Password.cpp
        day11/Password.h)
add_executable(day12 day12/main.cpp)
add_executable(day13 day13/main.cpp
        day13/Person.h
        day13/Party.cpp
        day13/Party.h
        day13/Person.cpp)
add_executable(day14 day14/main.cpp
        day14/Reindeer.cpp
        day14/Reindeer.h)
add_executable(day15 day15/main.cpp
        day15/Recipe.cpp
        day15/Recipe.h)
add_executable(day16 day16/main.cpp
        day16/Aunt.cpp
        day16/Aunt.h)
add_executable(day17 day17/main.cpp)
add_executable(day18 day18/main.cpp
        day18/Light.cpp
        day18/Light.h
        day18/LightGrid.cpp
        day18/LightGrid.h
        day18/LightWindow.cpp
        day18/LightWindow.h)
target_link_libraries(day18
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
target_link_libraries(day18 PRIVATE SDL2::SDL2_gfx)
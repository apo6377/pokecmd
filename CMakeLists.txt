cmake_minimum_required(VERSION 3.13)
project(pokecmd)

set(CMAKE_CXX_STANDARD 17)

add_executable(pokecmd
        main.cpp pokemon.cpp pokemon.h entry.h human.cpp human.h pokeType.h)

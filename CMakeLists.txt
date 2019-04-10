cmake_minimum_required(VERSION 3.13)
project(pokecmd)

set(CMAKE_CXX_STANDARD 14)

add_executable(pokecmd
        main.cpp pokemon.cpp pokemon.h pokeType.cpp pokeType.h)

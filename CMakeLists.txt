cmake_minimum_required(VERSION 3.30)
project(Game_2048 C)

set(CMAKE_C_STANDARD 11)

add_executable(Game_2048 main.c
        calc.h
        calc.c
        game.h
        game.c
        merge.h
        merge.c
        move.h
        move.c
        tools.h
        tools.c)

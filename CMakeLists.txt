cmake_minimum_required(VERSION 3.17)
project(Checkers_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Checkers_Game main.cpp CheckersGame.cpp CheckersGame.h Cell.cpp Cell.h Board.cpp Board.h)
cmake_minimum_required(VERSION 3.17)
project(A5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A5
        a5.cpp
        abstract_player.h
        bestMove.h
        board.h
        choices.h
        cmpt_error.h
        computer_player.h
        human_player.h
        legalMove.h computer_player2.h)

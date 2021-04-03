cmake_minimum_required(VERSION 3.16)
project(duanyuRecur)

set(CMAKE_CXX_STANDARD 14)

add_executable(duanyuRecur main.cpp player/player.cpp player/player.h informOfStra/informOfStrategy.cpp informOfStra/informOfStrategy.h function4game/function4game.cpp function4game/function4game.h)
cmake_minimum_required(VERSION 4.3)
project(CP3QUIZ CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(CP3QUIZ
        src/main.cpp
        src/jogador.cpp
        src/perguntas.cpp
        src/ranking.cpp
)

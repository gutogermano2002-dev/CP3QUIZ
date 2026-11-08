cmake_minimum_required(VERSION 4.3)
project(CP3QUIZ CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(CP3QUIZ
        src/main.cpp
        src/jogador.cpp
        src/perguntas.cpp
        src/ranking.cpp
)
target_include_directories(CP3QUIZ PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
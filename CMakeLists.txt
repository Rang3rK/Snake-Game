cmake_minimum_required(VERSION 3.26)
project(Snakegame)

set(CMAKE_CXX_STANDARD 20)

add_executable(Snakegame main.cpp
        Snake.cpp
        Snake.h
        SnakeGame.cpp
        SnakeGame.h
        SnakeFunction.cpp
        SnakeFunction.h
        Fruit.cpp
        Fruit.h
        Screen.cpp
        Screen.h
        Button.h
        Button.cpp
        Font.cpp
        States.cpp
)

target_link_libraries(Snakegame sfml-graphics sfml-audio)

find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)
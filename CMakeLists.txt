cmake_minimum_required(VERSION 3.7)
project(QTree)

add_executable(QTree main.cpp Point.cpp Point.h Rectangle.cpp Rectangle.h QTree.cpp QTree.h MyRandom.cpp MyRandom.h myTypes.cpp myTypes.h Graphics.cpp Graphics.h)

target_link_libraries(QTree -lsfml-graphics -lsfml-window -lsfml-system)
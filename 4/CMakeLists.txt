cmake_minimum_required(VERSION 3.25)
project(4)

set(CMAKE_CXX_STANDARD 23)

add_executable(4 main.cpp Foo.cpp Foo.h Bar.cpp Bar.h Field.cpp Field.h Wall.cpp Wall.h Exit.cpp Exit.h Path.cpp Path.h HorizontalWall.cpp HorizontalWall.h VerticalWall.cpp VerticalWall.h IntersectWall.cpp IntersectWall.h)

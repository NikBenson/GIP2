cmake_minimum_required(VERSION 3.25)
project(3)

set(CMAKE_CXX_STANDARD 23)

add_executable(3 main.cpp Counter.cpp Counter.h CounterCatalogue.cpp CounterCatalogue.h TeamStatistics.cpp TeamStatistics.h GameResult.cpp GameResult.h League.cpp League.h)

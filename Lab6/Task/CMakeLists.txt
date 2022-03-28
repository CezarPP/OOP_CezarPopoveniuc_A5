cmake_minimum_required(VERSION 3.21)
project(Task)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task main.cpp Car.h Weather.h Dacia.cpp Dacia.h Toyota.cpp Toyota.h Mercedes.cpp Mercedes.h Ford.cpp Ford.h Mazda.cpp Mazda.h Circuit.cpp Circuit.h)

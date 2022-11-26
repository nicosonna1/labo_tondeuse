cmake_minimum_required(VERSION 3.23)
project(labo_tondeuse)

set(CMAKE_CXX_STANDARD 20)

add_executable(labo_tondeuse main.cpp tondeuse.cpp tondeuse.h annexe.cpp annexe.h)

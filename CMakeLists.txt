cmake_minimum_required(VERSION 3.13)
project(cplanner)
set(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(cplanner ./src/Terms.cpp src/Compound.cpp src/Context.cpp ./src/World.cpp
        ./src/main.cpp src/Action.cpp src/Action.h src/Planner.cpp src/Planner.h)


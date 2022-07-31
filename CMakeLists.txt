cmake_minimum_required(VERSION 3.21)
project(Checklist)

set(CMAKE_CXX_STANDARD 14)

add_executable(Checklist main.cpp Version.h ListItem.cpp ListItem.h)

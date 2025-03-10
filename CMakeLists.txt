cmake_minimum_required(VERSION 3.26)
project(Checklist)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
set(SOURCE_FILES TaskList.cpp TaskList.h Task.h
        TaskCollection.h
        TaskCollection.cpp)
add_executable(Checklist main.cpp)
find_package(Boost COMPONENTS serialization  REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_library(core ${SOURCE_FILES})
target_link_libraries(Checklist ${Boost_LIBRARIES})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(Checklist ${CURSES_LIBRARIES})










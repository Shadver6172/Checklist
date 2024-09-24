cmake_minimum_required(VERSION 3.2)
project(Checklist)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)
add_executable(Checklist main.cpp)
set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
set(SOURCE_FILES Tasks.cpp Tasks.h ListItem.h)
find_package(Boost COMPONENTS serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_library(core ${SOURCE_FILES})
target_link_libraries(Checklist ${Boost_LIBRARIES})









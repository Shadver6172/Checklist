cmake_minimum_required(VERSION 3.2)
project(Checklist)
set(CMAKE_CXX_STANDARD 17)
add_executable(Checklist main.cpp)



set(Boost_DEBUG 1)

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
find_package(Boost COMPONENTS serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(Checklist ${Boost_LIBRARIES})









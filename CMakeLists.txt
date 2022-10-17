cmake_minimum_required(VERSION 3.24.2)
project(Checklist)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_NO_SYSTEM_PATHS ON)
set(Boost_ARCHITECTURE -x64)
FIND_PACKAGE( Boost 1.70.0 COMPONENTS serialization REQUIRED )
add_executable(Checklist main.cpp Version.h ListItem.cpp ListItem.h)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Checklist ${Boost_LIBRARIES})





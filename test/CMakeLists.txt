cmake_minimum_required(VERSION 3.7)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
set(TEST_SOURCE_FILES runAllTests.cpp TaskFixture.cpp)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIR})
find_package(Boost COMPONENTS serialization REQUIRED)

add_executable(runCheckListTests ${TEST_SOURCE_FILES})

target_link_libraries(runCheckListTests gtest gtest_main core ${Boost_LIBRARIES})

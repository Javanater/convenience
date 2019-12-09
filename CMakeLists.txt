cmake_minimum_required(VERSION 3.2)

project(convenience)

find_package(Boost CONFIG REQUIRED filesystem regex chrono date_time program_options system thread)
find_package(range-v3 CONFIG REQUIRED)

add_library(convenience convenience.hpp using_convenience.hpp)

set_target_properties(convenience PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(convenience Boost::filesystem Boost::regex Boost::chrono Boost::date_time Boost::program_options Boost::thread range-v3)

target_include_directories(convenience PUBLIC ${CMAKE_CURRENT_LIST_DIR})

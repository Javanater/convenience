cmake_minimum_required(VERSION 3.2)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.205.tar.gz"
    SHA1 "eba80d3028c856c6bedb5d8d9627b1b3bba19634"
)

project(convenience)

hunter_add_package(Boost COMPONENTS filesystem regex chrono date_time)
find_package(Boost CONFIG REQUIRED filesystem regex chrono date_time)

add_library(convenience convenience.hpp using_convenience.hpp)

set_target_properties(convenience PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(convenience Boost::filesystem Boost::regex Boost::chrono Boost::date_time)

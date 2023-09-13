# CMake file for building the NRecycle lib.

cmake_minimum_required(VERSION "3.26")

project(nRecycle CXX)

# Create .a library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../../../lib/)
add_library(nrecycle STATIC ./src/main.cpp)
# Statically link with the C / C++ STD
add_link_options(-static-libstdc++ -static-libstdc)
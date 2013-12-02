cmake_minimum_required(VERSION 2.6)


#set(CMAKE_C_COMPILER "/usr/lib/clang-analyzer/scan-build/ccc-analyzer")
#set(CMAKE_CXX_COMPILER "/usr/lib/clang-analyzer/scan-build/c++-analyzer")

# Nom du projet
project(libgit++)

SET(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -pedantic -Wdocumentation" )

add_subdirectory(src)
add_subdirectory(test)


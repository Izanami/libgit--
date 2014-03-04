cmake_minimum_required(VERSION 2.6)


#set(CMAKE_C_COMPILER "/usr/lib/clang-analyzer/scan-build/ccc-analyzer")
#set(CMAKE_CXX_COMPILER "/usr/lib/clang-analyzer/scan-build/c++-analyzer")

# Nom du projet
project(libgit++)

SET(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -pedantic -Wdocumentation" )

add_subdirectory(src)

if (TEST)
    message("-- Test")
    add_subdirectory(test)
ENDIF(TEST)

find_package(Doxygen)
set(DOXYGEN_CONFIGURED_FILE Doxygen)
if(DOXYGEN_FOUND)
configure_file(${DOXYGEN_TEMPLATE_FILE}
${DOXYGEN_CONFIGURED_FILE}
@ONLY
)
add_custom_target(doc
${DOXYGEN_EXECUTABLE}
${DOXYGEN_CONFIGURED_FILE}
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

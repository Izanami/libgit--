cmake_minimum_required(VERSION 2.6)

# Name project
project(libgit++)

# Compiler option
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -pedantic -Wdocumentation" )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -pedantic" )
endif()

add_subdirectory(src)

# Enable test? Use : cmake -DTEST=1 .
if (TEST)
    message("-- Test")
    add_subdirectory(test)
ENDIF(TEST)

# Build doc
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

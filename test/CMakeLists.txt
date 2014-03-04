find_package(Boost REQUIRED COMPONENTS system filesystem)
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

add_executable(test test.cpp RepoTest.cpp CommitTest.cpp SigTest.cpp)
target_link_libraries(test git++ cppunit ${Boost_LIBRARIES})

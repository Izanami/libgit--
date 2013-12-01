add_library(git++ SHARED libgit++.cpp)
target_link_libraries(git++ git2)
INSTALL(TARGETS git++
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      )

add_library(libgit++ SHARED libgit++.cpp)
target_link_libraries(libgit++ git2)
INSTALL(TARGETS libgit++
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      )

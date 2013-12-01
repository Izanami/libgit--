add_library(git++ SHARED repo.cpp)
target_link_libraries(git++ git2)
INSTALL(TARGETS git++
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      )

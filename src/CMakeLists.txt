add_library(git++ SHARED repo.cpp commit.cpp exception.cpp)
target_link_libraries(git++ git2)
INSTALL(TARGETS git++
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      )

INSTALL(FILES repo.h commit.h exception.h
      DESTINATION include/git++
)

add_library(git++ SHARED Repository.cpp Commit.cpp Object.cpp Exception.cpp Signature.cpp)
target_link_libraries(git++ git2)
INSTALL(TARGETS git++
      RUNTIME DESTINATION bin
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      )

  INSTALL(FILES Repository.h Commit.h Object.h Exception.h Signature.h
      DESTINATION include/git++
)

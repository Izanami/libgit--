#ifndef GITPP_H

#define GITPP_H
#include <git2.h>

class Git {
  public:
    Git(const char *path);
    static void init(const char *path, const bool bare=false);

  private:
     git_repository * repo;
     static void exception(int error);
};
#endif

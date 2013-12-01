#ifndef GITPP_H

#define GITPP_H
#include <git2.h>

class Git {
  public:
    Git(const char *path);
    void exception(int error);

  private:
     git_repository * repo;
};
#endif

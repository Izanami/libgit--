#ifndef GITPP_H

#define GITPP_H
#include <git2.h>

class Git {
  public:
    Git(const char *path);
     Git(git_repository * repo);
    static Git *init(const char *path, const bool bare = false);

    // Clone
    Git *clone(const char *path);
    static void clone(const char *url, const char *path);

    // Getter
    const char *path();

  private:
     git_repository * repo;
    static void exception(int error);
};
#endif

#ifndef GITPP_H

#define GITPP_H
#include <git2.h>
namespace Git {
class repo {
  public:
    repo(const char *path);
    repo(git_repository * repo);
    static repo *init(const char *path, const bool bare = false);

    // Clone
    repo *clone(const char *path);
    static void clone(const char *url, const char *path);

    // Lookup
    void lookup();

    // Getter
    const char *path();

  private:
     git_repository * repo_c;
     static void exception(int error);
     static git_oid oid(const char *sha);
     static const char* oid(git_oid);
};
}
#endif

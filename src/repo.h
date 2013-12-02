#ifndef GITPP_H

#define GITPP_H
#include <git2.h>
namespace Git {
class Repo {
  public:
    Repo(const char *path);
    Repo(git_repository * repo);
    static Repo *init(const char *path, const bool bare = false);

    // Clone
    Repo *clone(const char *path);
    static void clone(const char *url, const char *path);

    // Lookup
    void lookup(const char *commit);

    // Getter
    const char *path();

  private:
     git_repository * repo;
     static void exception(int error);
     static git_oid oid(const char *sha);
     static const char* oid(git_oid &oid);
};
}
#endif

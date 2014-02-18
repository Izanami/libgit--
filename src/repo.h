#ifndef GIT_REPO_H

#define GIT_REPO_H
#include <git2.h>
#include <memory>
#include "commit.h"

namespace Git {
    class Repo:public std::enable_shared_from_this < Repo > {
      public:
        ~Repo();
        static std::shared_ptr < Repo > open(const std::string & path);
        static std::shared_ptr < Repo > open(git_repository * repo);
        static std::shared_ptr < Repo > init(const std::string & path,
                                             const bool bare = false);

        // Clone
         std::shared_ptr < Repo > clone(const std::string & path);
        static void clone(const std::string & url,
                          const std::string & path);

        // Getter
        const std::string path();
        git_repository *ptr();

        // Commit
         std::shared_ptr < Git::Commit > commit();
         std::shared_ptr < Git::Commit > commit(const std::string & oid);
         std::shared_ptr < Git::Commit > commit(const git_oid & oid);

      private:
         Repo(Repo & Repo);
         Repo(const std::string & path);
         Repo(git_repository * repo);
        git_repository *repo;
    };
}
#endif

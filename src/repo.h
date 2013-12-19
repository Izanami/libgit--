#ifndef GIT_REPO_H

#define GIT_REPO_H
#include <git2.h>
#include <memory>

namespace Git {
    class Repo {
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

        // Lookup
        void lookup(const std::string & commit);

        // Getter
        const std::string path();

      private:
         Repo(Repo & Repo);
         Repo(const std::string & path);
         Repo(git_repository * repo);
        git_repository *repo;
        static git_oid oid(const std::string & sha);
        static const std::string oid(git_oid & oid);
    };
}
#endif

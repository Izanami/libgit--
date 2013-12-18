#ifndef GITPP_H

#define GITPP_H
#include <git2.h>
#include <memory>

namespace Git {
    class Repo {
      public:
        Repo(const std::string &path);
         Repo(git_repository * repo);
         ~Repo();
        static std::shared_ptr <Repo> init(const std::string &path, const bool bare = false);

        // Clone
        Repo *clone(const std::string &path);
        static void clone(const std::string &url, const std::string &path);

        // Lookup
        void lookup(const std::string &commit);

        // Getter
        const std::string path();

      private:
        Repo(Repo &Repo);
         git_repository * repo;
        static void exception(int error);
        static git_oid oid(const std::string &sha);
        static const std::string oid(git_oid & oid);
    };
}
#endif

#ifndef GIT_COMMIT_H

#define GIT_COMMIT_H
#include <git2.h>
#include <memory>
#include "repo.h"

namespace Git {
    class Repo;
    class Commit {
      public:
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo);
        git_oid update();

        //const Sig sig();
        void sig(const std::string & name, const std::string & email);

        const std::shared_ptr < std::string > message();
        void message(const std::string & msg);

      private:
         Commit(std::shared_ptr < Git::Repo > repo);
         std::shared_ptr < Git::Repo > repo;
         std::shared_ptr < std::string > __message;
    };
}
#endif

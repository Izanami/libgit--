#ifndef GIT_COMMIT_H

#define GIT_COMMIT_H
#include <git2.h>
#include <memory>
#include "repo.h"
#include "object.h"

namespace Git {
    class Repo;
    class Commit:public std::enable_shared_from_this < Commit >,
        public Object {
      public:
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo);
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo,
                                                 git_oid commit_oid);
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo,
                                                 std::string commit_oid);
         std::shared_ptr < git_oid > write();

        //const Sig sig();
        void sig(const std::string & name, const std::string & email);

        const std::shared_ptr < std::string > message();
         std::shared_ptr < Commit > message(const std::string & msg);

      private:
         Commit(std::shared_ptr < Git::Repo > repo);
         Commit(std::shared_ptr < Git::Repo > repo, git_oid);
         std::shared_ptr < Git::Repo > repo;
         std::shared_ptr < std::string > __message;
    };
}
#endif

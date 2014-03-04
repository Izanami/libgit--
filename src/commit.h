#ifndef GIT_COMMIT_H

#define GIT_COMMIT_H
#include <git2.h>
#include <memory>
#include "repo.h"
#include "object.h"
#include "signature.h"

namespace Git {
    class Repo;
    class Commit:public std::enable_shared_from_this < Commit >,
        public Object {
      public:

          /// New empty commit
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo);

         /// Get commit
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo,
                                                 git_oid commit_oid);
        static std::shared_ptr < Commit > create(std::shared_ptr <
                                                 Git::Repo > repo,
                                                 std::string commit_oid);

         /// Write commit
         std::shared_ptr < git_oid > write();

         /// Get signature of commit
         std::shared_ptr < Sig > sig();

         /// Message
        const std::shared_ptr < std::string > message(); ///< Return message of commit
         std::shared_ptr < Commit > message(const std::string & msg); ///< Set message of commit

      private:
         Commit(std::shared_ptr < Git::Repo > repo);
         Commit(std::shared_ptr < Git::Repo > repo, git_oid);
         std::shared_ptr < Git::Repo > repo;
         std::shared_ptr < std::string > __message;
    };
}
#endif

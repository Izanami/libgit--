#ifndef GIT_SIG_H

#define GIT_SIG_H
#include <git2.h>
#include <memory>
#include "repo.h"
#include "object.h"

namespace Git {
    class Repo;
    class Sig:
        public std::enable_shared_from_this < Sig >,
        public Object
    {

      public:
        ~Sig();
        Sig clone();
        static std::shared_ptr < Sig > create(std::shared_ptr < Repo > repo);
        static std::shared_ptr < Sig > create(git_signature *sig);
        static std::shared_ptr < Sig > create(const std::string & name, const std::string & email);
        git_signature *ptr();

      private:
         Sig(std::shared_ptr < Repo > repo);
         Sig(git_signature *sig);
         Sig(const std::string & name, const std::string & email);
         std::shared_ptr < Git::Repo > repo;
         git_signature *sig;
    };
}
#endif

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
        static std::shared_ptr < Sig > create(std::shared_ptr < Repo > repo);
        git_signature *ptr();

      private:
         Sig(std::shared_ptr < Repo > repo);
         std::shared_ptr < Git::Repo > repo;
         git_signature *sig;
    };
}
#endif

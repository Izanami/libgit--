#ifndef GIT_COMMIT_H

#define GIT_COMMIT_H
#include <git2.h>
#include <memory>

namespace Git {
    class Commit {
      public:
        static std::shared_ptr < Commit > create();
        void update();

        //const Sig sig();
        void sig(const std::string & name, const std::string & email);

        const std::string message();
        void message(const std::string & msg);
    };
}
#endif

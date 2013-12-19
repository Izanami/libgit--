#ifndef GIT_COMMIT_H

#define GIT_COMMIT_H
#include <git2.h>
#include <memory>

namespace Git {
    class Commit {
      public:
        static std::shared_ptr < Commit > new();
    };
}
#endif

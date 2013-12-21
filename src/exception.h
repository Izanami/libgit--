#ifndef GIT_EXCEPTION_H

#include <git2.h>
#include <memory>
#define GIT_EXCEPTION_H

namespace Git {
    class Exception {
      public:
        Exception(const int error);
        const std::string message();

      private:
        const git_error *e;
    };

    void Throw(const int &error);
};

#endif

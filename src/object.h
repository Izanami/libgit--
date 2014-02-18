#ifndef GIT_OBJECT_H

#define GIT_OBJECT_H
#include <git2.h>
#include <string>
#include <memory>

namespace Git {
    git_oid oid(const std::string & sha);
    const std::string oid(git_oid & oid);

    class Object {
      public:
        std::shared_ptr < git_oid > oid();
        const std::string oid_str();
      protected:
         std::shared_ptr < git_oid > oid(git_oid oid);
         std::shared_ptr < git_oid > oid(std::string oid);
      private:
         std::shared_ptr < git_oid > __oid;
    };
}
#endif

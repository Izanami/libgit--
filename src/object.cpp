#include "object.h"
#include "exception.h"

namespace Git {

    git_oid oid(const std::string & sha) {
        git_oid oid;
         Throw(git_oid_fromstr(&oid, sha.c_str()));
         return oid;
    } const std::string oid(git_oid & oid) {
        char shortsha[10];
        git_oid_tostr(shortsha, 9, &oid);
        return std::string(shortsha);
    }

    std::shared_ptr < git_oid > Object::oid() {
        return __oid;
    }

    const std::string Object::oid_str() {
        return Git::oid(*Object::oid().get());
    }

    std::shared_ptr < git_oid > Object::oid(git_oid oid) {
        __oid = std::make_shared < git_oid > (oid);
        return __oid;
    }

    std::shared_ptr < git_oid > Object::oid(std::string oid) {
        return Object::oid(Git::oid(oid));
    }

}

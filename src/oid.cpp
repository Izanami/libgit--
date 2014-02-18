#include "oid.h"
#include "exception.h"

namespace Git {

git_oid oid(const std::string & sha) {
    git_oid oid;
    Throw(git_oid_fromstr(&oid, sha.c_str()));
    return oid;
}

const std::string oid(git_oid & oid) {
    char shortsha[10];
    git_oid_tostr(shortsha, 9, &oid);
    return std::string(shortsha);
}

}

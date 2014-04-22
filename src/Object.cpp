#include "Object.h"

namespace Git {

git_oid shaToOid(const std::string& sha)
{
    git_oid oid;
    Throw(git_oid_fromstr(&oid, sha.c_str()));
    return oid;
}
const std::string oidToSha(git_oid& oid)
{
    char shortsha[10];
    git_oid_tostr(shortsha, 9, &oid);
    return std::string(shortsha);
}

std::shared_ptr<git_oid> Object::oid()
{
    return s_oid;
}

const std::string Object::oidToString()
{
    return oidToSha(*Object::oid().get());
}

std::shared_ptr<git_oid> Object::setOid(git_oid oid)
{
    s_oid = std::make_shared<git_oid>(oid);
    return s_oid;
}

std::shared_ptr<git_oid> Object::setOid(std::string oid)
{
    return Object::setOid(Git::shaToOid(oid));
}
}

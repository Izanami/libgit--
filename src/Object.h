#ifndef Object_h

#define Object_h
#include "Exception.h"
#include <string>

namespace Git {
git_oid shaToOid(const std::string& sha);
const std::string oidToSha(git_oid&);

class Object {
public:
    std::shared_ptr<git_oid> oid();
    const std::string oidToString();

protected:
    std::shared_ptr<git_oid> setOid(git_oid);
    std::shared_ptr<git_oid> setOid(std::string);

private:
    std::shared_ptr<git_oid> s_oid;
};
}
#endif

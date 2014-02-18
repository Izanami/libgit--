#ifndef GIT_TOOL_H

#define GIT_TOOL_H
#include <git2.h>
#include <string>

namespace Git {
        git_oid oid(const std::string & sha);
        const std::string oid(git_oid & oid);
}
#endif

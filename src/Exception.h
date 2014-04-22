#ifndef Exception_h
#define Exception_h
#include <git2.h>
#include <memory>

namespace Git {
class Exception {
public:
    Exception(const int error);
    const std::string message();

private:
    const git_error* e;
};

void Throw(const int& error);
} /* Git */
#endif

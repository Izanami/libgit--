#include "exception.h"

namespace Git {
    Exception::Exception(const int error) {
        if (error < 0) {
            e = giterr_last();
            throw this;
            giterr_clear();
        }
    }

    const std::string Exception::message() {
        if (e != nullptr)
            return e->message;
        else
            return "No message error";
    }

    void Throw(const int & error) {
        std::shared_ptr < Exception > (new Exception(error));
    }
}

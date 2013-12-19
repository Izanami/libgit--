#include "commit.h"

namespace Git {
    std::shared_ptr < Commit > Commit::create() {
        return std::shared_ptr < Commit > (new Commit());
    }
}

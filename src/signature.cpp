#include "repo.h"
#include "signature.h"
#include "exception.h"
#include "object.h"

namespace Git {
    Sig::Sig(std::shared_ptr < Repo > repo) {
        this->repo = repo;
        Throw(git_signature_default(&sig, repo->ptr()));
    }

    std::shared_ptr < Sig > Sig::create(std::shared_ptr < Repo > repo) {
        return std::shared_ptr < Sig > (new Sig(repo));
    }

    git_signature *Sig::ptr() {
        return sig;
    }
}

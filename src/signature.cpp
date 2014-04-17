#include "repo.h"
#include "signature.h"
#include "exception.h"
#include "object.h"

namespace Git {
    Sig::Sig(std::shared_ptr < Repo > repo) {
        this->repo = repo;
        Throw(git_signature_default(&sig, repo->ptr()));
    }

    Sig::Sig(git_signature *sig) : sig(sig) {
    }

    Sig::~Sig() {
        git_signature_free(sig);
    }

    std::shared_ptr < Sig > Sig::create(std::shared_ptr < Repo > repo) {
        return std::shared_ptr < Sig > (new Sig(repo));
    }

    std::shared_ptr < Sig > Sig::create(git_signature *sig) {
        return std::shared_ptr < Sig > (new Sig(sig));
    }

    git_signature *Sig::ptr() {
        return sig;
    }

    Sig Sig::clone() {
        return Sig(git_signature_dup(sig));
    }
}

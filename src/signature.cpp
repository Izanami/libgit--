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

    Sig::Sig(const std::string & name, const std::string & email) {
        Throw(git_signature_now(&sig, name.c_str(), email.c_str()));
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

    std::shared_ptr < Sig > Sig::create(const std::string & name, const std::string & email) {
        return std::shared_ptr < Sig > (new Sig(name, email));
    }

    git_signature *Sig::ptr() {
        return sig;
    }

    std::shared_ptr < Sig> Sig::clone() {
        return create(git_signature_dup(sig));
    }
}

#include "Repository.h"
#include "Signature.h"
#include "Exception.h"
#include "Object.h"

namespace Git {
Signature::Signature(std::shared_ptr<Repository> repository)
    : s_repository(repository)
{
    Throw(git_signature_default(&s_signature, s_repository->ptr()));
}

Signature::Signature(git_signature* signature)
    : s_signature(signature)
{
}

Signature::Signature(const std::string& name, const std::string& email)
{
    Throw(git_signature_now(&s_signature, name.c_str(), email.c_str()));
}

Signature::~Signature()
{
    git_signature_free(s_signature);
}

std::shared_ptr<Signature> Signature::get(std::shared_ptr<Repository> repository)
{
    return std::shared_ptr<Signature>(new Signature(repository));
}

std::shared_ptr<Signature> Signature::create(git_signature* signature)
{
    return std::shared_ptr<Signature>(new Signature(signature));
}

std::shared_ptr<Signature> Signature::create(const std::string& name, const std::string& email)
{
    return std::shared_ptr<Signature>(new Signature(name, email));
}

git_signature* Signature::ptr()
{
    return s_signature;
}

std::shared_ptr<Signature> Signature::clone()
{
    git_signature* signature;
    git_signature_dup(&signature, s_signature);
    return create(signature);
}
}

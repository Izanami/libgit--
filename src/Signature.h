#ifndef Signature_h

#define Signature_h
#include "Exception.h"
#include "Object.h"
#include "Repository.h"
#include "Signature.h"

namespace Git {
class Repository;
class Signature : public std::enable_shared_from_this<Signature>,
                  public Object {

public:
    ~Signature();
    static std::shared_ptr<Signature> get(std::shared_ptr<Repository>);
    static std::shared_ptr<Signature> cast(git_signature*);
    static std::shared_ptr<Signature> create(const std::string& name, const std::string& email);
    git_signature* ptr();
    std::shared_ptr<Signature> clone();

private:
    Signature(std::shared_ptr<Repository>);
    Signature(git_signature*);
    Signature(const std::string& name, const std::string& email);
    std::shared_ptr<Git::Repository> s_repository;
    git_signature* s_signature;
};
}
#endif

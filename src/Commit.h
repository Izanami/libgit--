#ifndef Commit_h
#define Commit_h
#include "Exception.h"
#include "Repository.h"
#include "Signature.h"

namespace Git {
class Repository;
class Commit : public std::enable_shared_from_this<Commit>,
               public Object {
public:
    /* Factory */
    static std::shared_ptr<Commit> create(std::shared_ptr<Git::Repository>); ///< Empty commit
    static std::shared_ptr<Commit> get(std::shared_ptr<Git::Repository>, git_oid);
    static std::shared_ptr<Commit> get(std::shared_ptr<Git::Repository>, std::string oid);

    /* Action */
    std::shared_ptr<git_oid> write();

    /* Getter/Settier */
    std::shared_ptr<Signature> signature(); ///< Getter signature
    const std::shared_ptr<std::string> message(); ///< Getter message
    std::shared_ptr<Commit> setMessage(const std::string&); ///< Setter message

private:
    Commit(std::shared_ptr<Git::Repository> repository);
    Commit(std::shared_ptr<Git::Repository> repository, git_oid);
    std::shared_ptr<Git::Repository> s_repository;
    std::shared_ptr<std::string> m_message;
};
} /* Git */
#endif

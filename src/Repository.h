#ifndef Repository_h
#define Repository_h
#include "Commit.h"
#include "Exception.h"

/*!
 * \file src/repo.h
 * \brief Manage repository
 * \author Adrien Jeser <adrien@jeser.me>
*/

/// \brief libgit++
namespace Git {
class Commit;
/// \brief Manage repository
class Repository : public std::enable_shared_from_this<Repository> {
public:
    ~Repository();

    /// Open a repository
    static std::shared_ptr<Repository> open(const std::string& path); ///< \param path Path to repository
    static std::shared_ptr<Repository> open(git_repository*); ///< \param repo Repository pointer of libgit2

    /// Initialize a repository
    /*!
         * \param path Path to new repository
         * \param bare Bare repository ?
         */
    static std::shared_ptr<Repository> init(const std::string& path, const bool bare = false);

    /// Clone a repository
    std::shared_ptr<Repository> clone(const std::string& path);
    static void clone(const std::string& url, const std::string& path);

    // Getter
    const std::string path(); ///< Path to repository
    git_repository* ptr(); ///< Repository pointer of libgit2

    /// New commit
    std::shared_ptr<Git::Commit> createCommit();

    /// Get commit
    std::shared_ptr<Git::Commit> getCommit(const std::string& oid);
    std::shared_ptr<Git::Commit> getCommit(const git_oid&);

private:
    Repository(Repository&);
    Repository(const std::string& path);
    Repository(git_repository*);
    git_repository* s_repository;
};
}
#endif

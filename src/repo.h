#ifndef GIT_REPO_H
#define GIT_REPO_H

/*!
 * \file src/repo.h
 * \brief Manage repository
 * \author Adrien Jeser <adrien@jeser.me>
*/

#include <git2.h>
#include <memory>
#include "commit.h"

/// \brief libgit++
namespace Git {

    /// \brief Manage repository
    class Repo:public std::enable_shared_from_this < Repo > {
      public:
        ~Repo();

        /// Open a repository
        static std::shared_ptr < Repo > open(const std::string & path); ///< \param path Path to repository
        static std::shared_ptr < Repo > open(git_repository * repo);    ///< \param repo Repository pointer of libgit2

        /// Initialize a repository
        /*!
         * \param path Path to new repository
         * \param bare Bare repository ?
         */
        static std::shared_ptr < Repo > init(const std::string & path,
                                             const bool bare = false);

        /// Clone a repository
         std::shared_ptr < Repo > clone(const std::string & path);
        static void clone(const std::string & url,
                          const std::string & path);

        // Getter
        const std::string path();       ///< Path to repository
        git_repository *ptr();  ///< Repository pointer of libgit2

        /// New commit
         std::shared_ptr < Git::Commit > commit();

        /// Get commit
         std::shared_ptr < Git::Commit > commit(const std::string & oid);
         std::shared_ptr < Git::Commit > commit(const git_oid & oid);

      private:
         Repo(Repo & Repo);
         Repo(const std::string & path);
         Repo(git_repository * repo);
        git_repository *repo;
    };
}
#endif

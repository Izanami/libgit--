#include "exception.h"
#include "repo.h"
#include "oid.h"

namespace Git {
    Repo::Repo(const std::string & path) {
        git_threads_init();
        Throw(git_repository_open(&repo, path.c_str()));
    } Repo::Repo(git_repository * repo) {
        this->repo = repo;
    }

    Repo::~Repo() {
        git_repository_free(this->repo);
    }

    std::shared_ptr < Repo > Repo::open(const std::string & path) {
        return std::shared_ptr < Repo > (new Repo(path));
    }

    std::shared_ptr < Repo > Repo::open(git_repository * repo) {
        return std::shared_ptr < Repo > (new Repo(repo));
    }

    std::shared_ptr < Repo > Repo::init(const std::string & path,
                                        const bool bare) {
        git_repository *repo = nullptr;
        Throw(git_repository_init(&repo, path.c_str(), bare));
        return open(repo);
    }

    std::shared_ptr < Repo > Repo::clone(const std::string & path) {
        git_repository *repolone = nullptr;
        Throw(git_clone
              (&repolone, this->path().c_str(), path.c_str(), NULL));
        return open(repolone);
    }

    const std::string Repo::path() {
        return git_repository_path(repo);
    }

    git_repository *Repo::ptr() {
        return repo;
    }

    std::shared_ptr < Git::Commit > Repo::commit() {
        auto commit = Git::Commit::create(shared_from_this());
        return commit;
    }

    std::shared_ptr < Git::Commit > Repo::commit(const git_oid & oid) {
        auto commit = Git::Commit::create(shared_from_this(), oid);
        return commit;
    }

    std::shared_ptr < Git::Commit > Repo::commit(const std::string & oid) {
        auto commit = Git::Commit::create(shared_from_this(), oid);
        return commit;
    }

}                               // Git

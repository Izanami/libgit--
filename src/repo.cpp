#include "exception.h"
#include "repo.h"

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
        Throw(git_clone(&repolone, this->path().c_str(), path.c_str(), NULL));
        return open(repolone);
    }

    const std::string Repo::path() {
        return git_repository_path(repo);
    }

    void Repo::lookup(const std::string & commit) {
        git_commit *commit_c;
        git_oid commit_oid = oid(commit.c_str());
        Throw(git_commit_lookup(&commit_c, repo, &commit_oid));
    }

    git_oid Repo::oid(const std::string & sha) {
        git_oid oid;
        Throw(git_oid_fromstr(&oid, sha.c_str()));
        return oid;
    }
    const std::string Repo::oid(git_oid & oid) {
        char shortsha[10];
        git_oid_tostr(shortsha, 9, &oid);
        return std::string(shortsha);
    }

}                               // Git

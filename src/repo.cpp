#include "repo.h"

namespace Git {
    Repo::Repo(const char *path) {
        git_threads_init();
        int error = git_repository_open(&repo, path);
         exception(error);
    } Repo::Repo(git_repository * repo) {
        this->repo = repo;
    }

    void Repo::exception(int error) {
        if (error < 0) {
            const git_error *e = giterr_last();

            if (e != nullptr) {
                throw e->message;
            } else {
                throw "libgit++ : No message error";
            }
            giterr_clear();
        }
    }


    Repo *Repo::init(const char *path, const bool bare) {
        git_repository *repo = nullptr;
        int error = git_repository_init(&repo, path, bare);
        exception(error);
        return new Repo(repo);
    }

    Repo *Repo::clone(const char *path) {
        git_repository *repolone = nullptr;
        int error = git_clone(&repolone, this->path(), path, NULL);
        exception(error);
        return new Repo(repolone);
    }

    const char *Repo::path() {
        return git_repository_path(repo);
    }

    void Repo::lookup(const char *commit) {
        git_commit *commit_c;
        git_oid commit_oid = oid(commit);
        int error = git_commit_lookup(&commit_c, repo, &commit_oid);
        exception(error);
    }

    git_oid Repo::oid(const char *sha) {
        git_oid oid;
        int error = git_oid_fromstr(&oid, sha);
        exception(error);
        return oid;
    }
    const char *Repo::oid(git_oid & oid) {
        char *shortsha = new char[10];
        git_oid_tostr(shortsha, 9, &oid);
        return shortsha;
    }

}                               // Git

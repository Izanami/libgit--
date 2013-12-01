#include "repo.h"

namespace Git {
repo::repo(const char *path)
{
    int error = git_repository_open(&repo_c, path);
    exception(error);
}

repo::repo(git_repository * repo)
{
    this->repo_c = repo;
}

void repo::exception(int error)
{
    if (error < 0) {
        const git_error *e = giterr_last();

        if (e != nullptr) {
            throw e->message;
        } else {
            throw "libgit++ : No message error";
        }
    }
}


repo *repo::init(const char *path, const bool bare)
{
    git_repository *repo_c = nullptr;
    int error = git_repository_init(&repo_c, path, bare);
    exception(error);
    return new repo(repo_c);
}

repo *repo::clone(const char *path)
{
    git_repository *repo_clone = nullptr;
    int error = git_clone(&repo_clone, this->path(), path, NULL);
    exception(error);
    return new repo(repo_clone);
}

const char *repo::path()
{
    return git_repository_path(repo_c);
}

}

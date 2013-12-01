#include "libgit++.h"

Git::Git(const char *path)
{
    int error = git_repository_open(&repo, path);
    exception(error);
}

Git::Git(git_repository * repo)
{
    this->repo = repo;
}

void Git::exception(int error)
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


Git *Git::init(const char *path, const bool bare)
{
    git_repository *repo = nullptr;
    int error = git_repository_init(&repo, path, bare);
    exception(error);
    return new Git(repo);
}

Git *Git::clone(const char *path)
{
    git_repository *repo_clone = nullptr;
    int error = git_clone(&repo_clone, this->path(), path, NULL);
    exception(error);
    return new Git(repo_clone);
}

const char *Git::path()
{
    return git_repository_path(repo);
}

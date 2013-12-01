#include "libgit++.h"

Git::Git(const char *path)
{
    int error = git_repository_open(&repo, path);
    exception(error);
}

void Git::exception(int error)
{
    if (error < 0) {
        const git_error *e = giterr_last();

        if (e != NULL) {
            throw e->message;
        } else {
            throw "libgit++ : No message error";
        }
    }
}

#include "libgit++.h"

Git::Git(const char *path) {
    int error = git_repository_open(&repo, path);
}

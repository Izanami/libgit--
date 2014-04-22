#include "Repository.h"

namespace Git {
Repository::Repository(const std::string& path)
{
    git_threads_init();
    Throw(git_repository_open(&s_repository, path.c_str()));
}

Repository::Repository(git_repository* repository)
    : s_repository(repository)
{
}

Repository::~Repository()
{
    git_repository_free(this->s_repository);
}

std::shared_ptr<Repository> Repository::open(const std::string& path)
{
    return std::shared_ptr<Repository>(new Repository(path));
}

std::shared_ptr<Repository> Repository::open(git_repository* repository)
{
    return std::shared_ptr<Repository>(new Repository(repository));
}

std::shared_ptr<Repository> Repository::init(const std::string& path, const bool bare)
{
    git_repository* repo = nullptr;
    Throw(git_repository_init(&repo, path.c_str(), bare));
    return open(repo);
}

std::shared_ptr<Repository> Repository::clone(const std::string& path)
{
    git_repository* repolone = nullptr;
    Throw(git_clone(&repolone, this->path().c_str(), path.c_str(), NULL));
    return open(repolone);
}

const std::string Repository::path()
{
    return git_repository_path(s_repository);
}

git_repository* Repository::ptr()
{
    return s_repository;
}

std::shared_ptr<Git::Commit> Repository::createCommit()
{
    auto commit = Git::Commit::create(shared_from_this());
    return commit;
}

std::shared_ptr<Git::Commit> Repository::getCommit(const git_oid& oid)
{
    auto commit = Git::Commit::get(shared_from_this(), oid);
    return commit;
}

std::shared_ptr<Git::Commit> Repository::getCommit(const std::string& oid)
{
    auto commit = Git::Commit::get(shared_from_this(), oid);
    return commit;
}

} // Git

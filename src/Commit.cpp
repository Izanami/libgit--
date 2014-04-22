#include "Commit.h"

namespace Git {
Commit::Commit(std::shared_ptr<Git::Repository> repository)
    : s_repository(repository)
{
    m_message = std::make_shared<std::string>();
}

Commit::Commit(std::shared_ptr<Git::Repository> repository, git_oid commit_oid)
    : s_repository(repository)
{
    git_commit* commit;
    git_commit_lookup(&commit, s_repository->ptr(), &commit_oid);
    m_message->assign(git_commit_message(commit));
    git_commit_free(commit);
    setOid(commit_oid);
}

std::shared_ptr<Commit> Commit::create(std::shared_ptr<Git::Repository> repository)
{
    return std::shared_ptr<Commit>(new Commit(repository));
}

std::shared_ptr<Commit> Commit::get(std::shared_ptr<Git::Repository> repository, git_oid oid)
{
    return std::shared_ptr<Commit>(new Commit(repository, oid));
}

std::shared_ptr<Commit> Commit::get(std::shared_ptr<Git::Repository> repository, std::string oid)
{
    return std::shared_ptr<Commit>(new Commit(repository, Git::shaToOid(oid)));
}

std::shared_ptr<Commit> Commit::setMessage(const std::string& message)
{
    this->m_message->assign(message);
    return shared_from_this();
}

const std::shared_ptr<std::string> Commit::message()
{
    return this->m_message;
}

std::shared_ptr<git_oid> Commit::write()
{
    git_index* index;
    git_oid tree_id, commit_oid;
    git_tree* tree;

    Throw(git_repository_index(&index, s_repository->ptr()));
    Throw(git_index_write_tree(&tree_id, index));
    git_index_free(index);

    git_tree_lookup(&tree, s_repository->ptr(), &tree_id);
    Throw(git_commit_create_v(&commit_oid, s_repository->ptr(), "HEAD", signature()->ptr(), signature()->ptr(), NULL, message()->c_str(), tree, 0));

    return setOid(commit_oid);
}

std::shared_ptr<Signature> Commit::signature()
{
    return Signature::get(s_repository);
}
}

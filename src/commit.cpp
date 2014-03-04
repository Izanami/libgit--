#include "repo.h"
#include "commit.h"
#include "exception.h"
#include "object.h"

namespace Git {
    Commit::Commit(std::shared_ptr < Git::Repo > repo) {
        this->repo = repo;
        __message = std::make_shared < std::string > ();
    } Commit::Commit(std::shared_ptr < Git::Repo > repo,
                     git_oid commit_oid) {
        this->repo = repo;
        git_commit *commit;
        git_commit_lookup(&commit, repo->ptr(), &commit_oid);
        __message->assign(git_commit_message(commit));
        git_commit_free(commit);
        oid(commit_oid);
    }

    std::shared_ptr < Commit > Commit::create(std::shared_ptr < Git::Repo >
                                              repo) {
        return std::shared_ptr < Commit > (new Commit(repo));
    }

    std::shared_ptr < Commit > Commit::create(std::shared_ptr < Git::Repo >
                                              repo, git_oid oid) {
        return std::shared_ptr < Commit > (new Commit(repo, oid));
    }

    std::shared_ptr < Commit > Commit::create(std::shared_ptr < Git::Repo >
                                              repo, std::string oid) {
        return std::shared_ptr < Commit >
            (new Commit(repo, Git::oid(oid)));
    }

    std::shared_ptr < Commit > Commit::message(const std::string & msg) {
        this->__message->assign(msg);
        return shared_from_this();
    }

    const std::shared_ptr < std::string > Commit::message() {
        return this->__message;
    }

    std::shared_ptr < git_oid > Commit::write() {
        git_index *index;
        git_oid tree_id, commit_oid;
        git_tree *tree;

        Throw(git_repository_index(&index, repo->ptr()));
        Throw(git_index_write_tree(&tree_id, index));
        git_index_free(index);

        git_tree_lookup(&tree, repo->ptr(), &tree_id);
        Throw(git_commit_create_v
              (&commit_oid, repo->ptr(), "HEAD", sig()->ptr(), sig()->ptr(), NULL,
               message()->c_str(), tree, 0));

        return oid(commit_oid);
    }

    std::shared_ptr < Sig > Commit::sig() {
        return Sig::create(repo);
    }
}

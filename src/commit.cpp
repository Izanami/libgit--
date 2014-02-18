#include "repo.h"
#include "commit.h"
#include "exception.h"
#include "tool.h"

namespace Git {
    Commit::Commit(std::shared_ptr < Git::Repo > repo)  {
        this->repo = repo;
       __message = std::make_shared < std::string > ();
       __oid = std::make_shared < git_oid > ();
    }

    Commit::Commit(std::shared_ptr < Git::Repo > repo, git_oid oid) {
        this->repo = repo;
        git_commit *commit;
        git_commit_lookup(&commit, repo->ptr(), &oid);
        __message->assign(git_commit_message(commit));

        __oid = std::make_shared < git_oid > (oid);
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
        return std::shared_ptr < Commit > (new Commit(repo, Git::oid(oid)));
    }

    std::shared_ptr < Commit > Commit::message(const std::string & msg) {
        this->__message->assign(msg);
        return shared_from_this();
    }

    const std::shared_ptr < std::string > Commit::message() {
        return this->__message;
    }

    std::shared_ptr < git_oid > Commit::write() {
        git_signature *sig;
        git_index *index;
        git_oid tree_id, commit_id;
        git_tree *tree;

        Throw(git_signature_default(&sig, repo->ptr()));
        Throw(git_repository_index(&index, repo->ptr()));
        Throw(git_index_write_tree(&tree_id, index));
        git_index_free(index);

        git_tree_lookup(&tree, repo->ptr(), &tree_id);
        Throw(git_commit_create_v(&commit_id, repo->ptr(), "HEAD", sig, sig,
                            NULL, message()->c_str(), tree, 0));

        __oid = std::make_shared < git_oid > (commit_id);
        return __oid;
    }
}

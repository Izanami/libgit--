#include "CommitTest.h"
#include "../src/repo.h"
#include "../src/commit.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(CommitTest);

void CommitTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::Repo::init(path.string());
}

void CommitTest::tearDown()
{
    remove_all(path);
}

void CommitTest::testCreate()
{
    Git::Commit::create();
}

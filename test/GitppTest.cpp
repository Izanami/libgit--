#include "GitppTest.h"
#include "../src/repo.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GitppTest);

void GitppTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::repo::init(path.string().c_str());
}

void GitppTest::tearDown()
{
    delete repo;
    remove_all(path);
}

void GitppTest::testInit()
{
    delete Git::repo::init(path.string().c_str());
}

void GitppTest::testConstructor()
{
    delete new Git::repo(path.string().c_str());
}

void GitppTest::testClone()
{
    boost::filesystem::path tmpdir = unique_path();
    repo->clone(tmpdir.string().c_str());
    remove_all(tmpdir);
}

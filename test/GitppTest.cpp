#include "GitppTest.h"
#include "../src/repo.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GitppTest);

void GitppTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::Repo::init(path.string());
}

void GitppTest::tearDown()
{
    remove_all(path);
}

void GitppTest::testInit()
{
    Git::Repo::init(path.string());
}

void GitppTest::testConstructor()
{
    Git::Repo::open(path.string());
}

void GitppTest::testClone()
{
    boost::filesystem::path tmpdir = unique_path();
    repo->clone(tmpdir.string());
    remove_all(tmpdir);
}

void GitppTest::testLookup()
{
    repo->lookup("HEAD");
}

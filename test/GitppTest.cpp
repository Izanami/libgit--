#include "GitppTest.h"
#include "../src/libgit++.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GitppTest);

void GitppTest::setUp()
{
    path = unique_path();
    create_directories(path);
    git = Git::init(path.string().c_str());
}

void GitppTest::tearDown()
{
    delete git;
    remove_all(path);
}

void GitppTest::testInit() {
    delete Git::init(path.string().c_str());
}

void GitppTest::testConstructor()
{
    delete new Git(path.string().c_str());
}

void GitppTest::testClone() {
    boost::filesystem::path tmpdir = unique_path();
    git->clone(tmpdir.string().c_str());
    remove_all(tmpdir);
}

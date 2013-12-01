#include "GitppTest.h"
#include "../src/libgit++.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GitppTest);

void GitppTest::setUp()
{
    tmpdir = unique_path();
    create_directories(tmpdir);
    Git::init(tmpdir.string().c_str());
}

void GitppTest::tearDown()
{
    boost::filesystem::remove_all(tmpdir);
}

void GitppTest::testInit() {
    Git::init(tmpdir.string().c_str());
}

void GitppTest::testConstructor()
{
    Git *git = new Git(tmpdir.string().c_str());
    delete git;
}

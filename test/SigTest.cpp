#include "SigTest.h"
#include "../src/Repository.h"
#include "../src/Signature.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(SigTest);

void SigTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::Repository::init(path.string());
}

void SigTest::tearDown()
{
    remove_all(path);
}

void SigTest::testCreate()
{
    repo->createCommit()->signature();
    Git::Signature::create("foo baz", "example@example.org");
}


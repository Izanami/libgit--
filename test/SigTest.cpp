#include "SigTest.h"
#include "../src/repo.h"
#include "../src/signature.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(SigTest);

void SigTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::Repo::init(path.string());
}

void SigTest::tearDown()
{
    remove_all(path);
}

void SigTest::testCreate()
{
    repo->commit()->sig();
}


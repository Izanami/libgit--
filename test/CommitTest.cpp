#include "CommitTest.h"
#include "../src/Repository.h"
#include "../src/Repository.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(CommitTest);

void CommitTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::Repository::init(path.string());
}

void CommitTest::tearDown()
{
    remove_all(path);
}

void CommitTest::testCreate()
{
    repo->createCommit()->setMessage("test")->write();
}

void CommitTest::testMessage()
{
    const std::string message("my little poney");
    //CPPUNIT_ASSERT_EQUAL(message ==
                         //*repo->createCommit()->setMessage(message)->message().
                         //get(), true);
}

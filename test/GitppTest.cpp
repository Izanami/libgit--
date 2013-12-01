#include "GitppTest.h"
#include "../src/libgit++.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GitppTest);

void GitppTest::setUp()
{

}

void GitppTest::tearDown()
{

}

void GitppTest::testConstructor()
{
    Git *git = new Git("./sample");
    delete git;
}

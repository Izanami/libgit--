#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>
#include "boost/filesystem.hpp"

class GitppTest:public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(GitppTest);
    CPPUNIT_TEST(testInit);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST_SUITE_END();
    private:
    boost::filesystem::path tmpdir;
  public:
    void setUp();
    void tearDown();
    void testInit();
    void testConstructor();

};

#endif                          // GITPP_TEST

#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>
#include "boost/filesystem.hpp"
#include "../src/repo.h"

class GitppTest:public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(GitppTest);
    CPPUNIT_TEST(testInit);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testClone);
    CPPUNIT_TEST_SUITE_END();
  private:
    boost::filesystem::path path;
    Git::repo *repo;

  public:
    void setUp();
    void tearDown();
    void testInit();
    void testConstructor();
    void testClone();

};

#endif                          // GITPP_TEST

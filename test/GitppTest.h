#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>
#include "boost/filesystem.hpp"
#include "../src/libgit++.h"

class GitppTest:public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(GitppTest);
    CPPUNIT_TEST(testInit);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testClone);
    CPPUNIT_TEST_SUITE_END();
  private:
    boost::filesystem::path path;
    Git *git;

  public:
    void setUp();
    void tearDown();
    void testInit();
    void testConstructor();
    void testClone();

};

#endif                          // GITPP_TEST

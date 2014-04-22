#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>
#include "boost/filesystem.hpp"
#include "../src/Repository.h"

class RepoTest:public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(RepoTest);
    CPPUNIT_TEST(testInit);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testClone);
    CPPUNIT_TEST(testLookup);
    CPPUNIT_TEST_SUITE_END();
  private:
    boost::filesystem::path path;
    std::shared_ptr < Git::Repository > repo;

  public:
    void setUp();
    void tearDown();
    void testInit();
    void testConstructor();
    void testClone();
    void testLookup();

};

#endif                          // GITPP_TEST

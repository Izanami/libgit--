#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>
#include "boost/filesystem.hpp"
#include "../src/repo.h"

class SigTest:public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(SigTest);
    CPPUNIT_TEST(testCreate);
    CPPUNIT_TEST_SUITE_END();
  private:
    boost::filesystem::path path;
    std::shared_ptr < Git::Repo > repo;

  public:
    void setUp();
    void tearDown();
    void testInit();
    void testCreate();
};

#endif                          // GITPP_TEST

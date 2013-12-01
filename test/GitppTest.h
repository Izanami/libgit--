#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>

class GitppTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( GitppTest );
    CPPUNIT_TEST( testConstructor );
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();
        void testConstructor();
};

#endif // GITPP_TEST

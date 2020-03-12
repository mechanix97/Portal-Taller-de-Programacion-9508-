#ifndef __TEMPLATE_TEST_H__
#define __TEMPLATE_TEST_H__

#include <cxxtest/TestSuite.h>

class TemplateTest: public CxxTest::TestSuite {
public:
    void testAddition() {
        TS_ASSERT_EQUALS(5, 2 + 3);
    }
};

#endif

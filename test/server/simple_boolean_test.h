#ifndef __SIMPLE_BOOL_TEST_H__
#define __SIMPLE_BOOL_TEST_H__

#include "../../server/include/boolean_suppliers/simple_boolean.h"
#include <cxxtest/TestSuite.h>

class SimpleBoolTest: public CxxTest::TestSuite {
public:
    void testSimpleBooleanFuncionaComoUnBooleanoTrue() {
        SimpleBoolean sb(true);
        TS_ASSERT(sb.getAsBoolean());
    }

    void testSimpleBooleanFuncionaComoUnBooleanoFalse() {
        SimpleBoolean sb(false);
        TS_ASSERT(!sb.getAsBoolean());
    }
};

#endif

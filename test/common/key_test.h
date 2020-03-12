#ifndef __KEY_TEST_H__
#define __KEY_TEST_H__

#include "../../common/include/key.h"
#include <cxxtest/TestSuite.h>

class KeyTest: public CxxTest::TestSuite {
public:
    void testKeySePresionaEIndicaQueEstaPresionada() {
        Key key;
        key.press();

        TS_ASSERT_EQUALS(true, key.isBeingPressed());
    }

    void testKeySePresionaDosVecesYDebeIndicarQueEstaPresionada() {
        Key key;
        key.press();
        key.press();

        TS_ASSERT_EQUALS(true, key.isBeingPressed());
    }

    void testKeySePresionaYSueldaYDebeIndicarQueNoEstaPresionada() {
        Key key;
        key.press();
        key.release();

        TS_ASSERT_EQUALS(false, key.isBeingPressed());
    }

    void testKeySePresionaDosVecesYSueldaYDebeIndicarQueNoEstaPresionada() {
        Key key;
        key.press();
        key.press();
        key.release();

        TS_ASSERT_EQUALS(false, key.isBeingPressed());
    }
};

#endif

#ifndef __KEYPAD_TEST_H__
#define __KEYPAD_TEST_H__

#include "../../common/include/keypad.h"
#include <cxxtest/TestSuite.h>

class KeypadTest: public CxxTest::TestSuite {
public:
    void testSePresionaDerDosVecesEIndicaQueEstaPresionada() {
        Keypad keypad;
        keypad.press(KEY::RIGHT_KEY);
        keypad.press(KEY::RIGHT_KEY);

        TS_ASSERT_EQUALS(
            true,
            keypad.getKey(KEY::RIGHT_KEY)->isBeingPressed());
    }

    void testSePresionaYSueltaDebeIndicarQueNoEstaPresionada() {
        Keypad keypad;
        keypad.press(KEY::RIGHT_KEY);
        keypad.release(KEY::RIGHT_KEY);

        TS_ASSERT_EQUALS(
            false,
            keypad.getKey(KEY::RIGHT_KEY)->isBeingPressed());
    }
};

#endif

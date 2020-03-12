#ifndef __CAKE_TEST_H__
#define __CAKE_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/cake/cake.h"

class CakeTest: public CxxTest::TestSuite {
public:
    void testCakeNoTieneLeaks() {
        World world;
        world.createCake(0, 0);
    }
};

#endif

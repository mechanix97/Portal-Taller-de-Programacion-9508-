#ifndef __ROCK_TEST_H__
#define __ROCK_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/rock/rock.h"

class RockTest: public CxxTest::TestSuite {
public:
    void testCuandoSeCreaUnaRocaDebeDevolverUnPunteroNoNulo() {
        World world;
        Rock *rock = world.createRock(0, 0);
        TS_ASSERT_DIFFERS(nullptr, rock);
        world.destroyBody(rock);
    }
};

#endif

#ifndef __WORLD_TEST_H__
#define __WORLD_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/world.h"

class WorldTest: public CxxTest::TestSuite {
public:
    void testWorldNoLeakeaMemoria() {
        // test para correr con valgring
        World world;
    }

    void testSeAgregaUnBodyAWorldLuegoSeEliminaYDisminuyeLaCantidadDeBodyPresentes() {
        World world;
        world.createBullet(1, 1, DIRECTION::RIGHT_DIRECTION);
        world.getGameLoop()->step();

        TS_ASSERT_EQUALS(0, world.getBodySize());
    }

    void testNoLeakea() {
        World world;
        for (int i = 0; i < 1; i++) {
            world.createChell(-6.00 + 2.00*i, 1.00);
        }

        for (int i = 0; i < 3; i++) {
            world.createSquareMetalBlock(-6.00 + 2.00*i, -1.00);
        }
        world.createSquareMetalBlock(-6.00 + 2.00*-10, 1.00);
        world.createSquareMetalBlock(-6.00 + 2.00*10, 1.00);

        world.createLauncher(-6, 1, DIRECTION::LEFT_DIRECTION);
        world.createLauncher(0, 1, DIRECTION::RIGHT_DIRECTION);

        for (int i = 0; i < 1000; i++) {
            world.getGameLoop()->step();
        }
    }
};

#endif

#ifndef __LAUNCHER_TEST_H__
#define __LAUNCHER_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/launcher/launcher.h"
#include "../../server/include/world.h"

class LauncherTest: public CxxTest::TestSuite {
public:
    void testNoLeakeaMemoria() {
        // Para valgrind.
        World world;
        world.createLauncher(2, 2, DIRECTION::RIGHT_DIRECTION);
    }

    void testLauncherLanzaUnaBulletAlInicioYLaCantidadDeBodiesEnWorldAumenta() {
        // 20fps
        World world;
        world.createLauncher(2, 2, DIRECTION::RIGHT_DIRECTION);
        world.getGameLoop()->step();
        world.getGameLoop()->step();

        uint32_t count = world.getBodyCount();

        TS_ASSERT_EQUALS(2, count);
    }
};

#endif

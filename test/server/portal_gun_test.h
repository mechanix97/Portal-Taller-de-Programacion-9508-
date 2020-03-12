#ifndef __PORTA_GUN_TEST_H__
#define __PORTA_GUN_TEST_H__

#include <cxxtest/TestSuite.h>

class PortalGunTest: public CxxTest::TestSuite {
public:
    void testPortalGunVieneConPortalOneVacios() {
        PortalGun portal_gun(0);

        Portal *portal = portal_gun.getPortalOne();

        TS_ASSERT_EQUALS(nullptr, portal);
    }

    void testCuandoSeDisparaUnPortalHaciaUnBloqueDeMetalSeDebeAbrirUnPortal() {
        World world;
        Chell *chell = world.createChell(0, 0);
        world.createSquareMetalBlock(10, 0);

        chell->getPortalGun()->firePortalOne(10, 0);

        Portal *portal = chell->getPortalGun()->getPortalOne();
        TS_ASSERT_DIFFERS(nullptr, portal);
        world.destroyBody(chell);
    }
};

#endif

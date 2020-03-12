#ifndef __PORTAL_TEST_H__
#define __PORTAL_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/portal/portal.h"
#include "../../server/include/world.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

class PortalTest: public CxxTest::TestSuite {
public:
    void testPortalNoLeakea() {
        World world;
        Portal *portal_one = world.createPortal(1, b2Vec2(0, 0), b2Vec2(1, 0));
        portal_one++;
    }

    void testCuandoSeCreanDosPortalUnoDebenTenerDistintoBodyId() {
        World world;
        Portal *portal = world.createPortal(1, b2Vec2(0, 0), b2Vec2(1, 0));
        Portal *other_portal = world.createPortal(1, b2Vec2(0, 0), b2Vec2(1, 0));

        TS_ASSERT_DIFFERS(portal->getBodyId(), other_portal->getBodyId());
    }

    void testCuandoSeCreanDosPortalesDosDebenTenerDistintoBodyId() {
        World world;
        Portal *portal = world.createPortal(2, b2Vec2(0, 0), b2Vec2(1, 0));
        Portal *other_portal = world.createPortal(2, b2Vec2(0, 0), b2Vec2(1, 0));

        TS_ASSERT_DIFFERS(portal->getBodyId(), other_portal->getBodyId());
    }

    void testChellYLosPortalesDebenTenerDistintoBodyId() {
        World world;
        Portal *portal = world.createPortal(1,b2Vec2(0, 0), b2Vec2(1, 0));
        Chell *chell = world.createChell(0, 0);

        TS_ASSERT_DIFFERS(chell->getBodyId(), portal->getBodyId());
    }

    void testCuandoSeCreaUnNuevoPortalDebeTenerUnNuevoBodyId() {

    }
};

#endif

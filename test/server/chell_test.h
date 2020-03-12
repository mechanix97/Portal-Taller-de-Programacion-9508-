#ifndef __CHELL_TEST_H__
#define __CHELL_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/chell/chell.h"
#include "../../server/include/bodies/portal/portal.h"
#include "../../server/include/bodies/block/block.h"

class ChellTest: public CxxTest::TestSuite {
public:
    void testCuandoSeCreaChellNoDebeDevolverUnPuteroNulo() {
        World world;
        Chell *chell = world.createChell(0, 0);
        TS_ASSERT_DIFFERS(nullptr, chell);
        world.destroyBody(chell);
    }
};

#endif

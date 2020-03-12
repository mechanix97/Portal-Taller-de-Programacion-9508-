#ifndef __ACID_TEST_H__
#define __ACID_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/acid/acid.h"
#include "../../server/include/world.h"

class AcidTest: public CxxTest::TestSuite {
public:
    void testChellTocaAcidYDebeMorir() {
        // World world;
        //
        // world.createAcid(1, 1);
        // Chell *chell = world.createChell(1, 1);
        // world.getGameLoop()->step();
        //
        // Update update = chell->createUpdate(COMMAND::UPDATE_COMMAND);
        // TS_ASSERT_EQUALS(STATUS::CHELL_DIE, update.getStatus());
        // world.destroyBody(chell);
    }

};

#endif

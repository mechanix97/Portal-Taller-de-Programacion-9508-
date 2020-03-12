#ifndef __GATE_TEST_H__
#define __GATE_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/gate/gate.h"
#include "../../server/include/bodies/chell/chell.h"
#include "../../server/include/bodies/receiver/receiver.h"
#include "../../server/include/bodies/launcher/launcher.h"
#include "../../server/include/bodies/bullet/bullet.h"
#include "../../server/include/world.h"
#include "../../server/include/boolean_suppliers/boolean_block_factory.h"
#include "../../server/include/boolean_suppliers/boolean_block.h"
#include "../../common/include/types.h"

#define UNUSED_VAR(VAR) (VAR++)

class GateTest: public CxxTest::TestSuite {
public:
    void testSeCreaGateYNoLeakeaMemoria() {
        // test para correr con valgrind
        World world;
        Gate *gate = world.createGate(0, 0);
        gate++;
    }

    void testGateConUnSoloBotonCambiaEstadoAOPENINGCuandoSeActivaSuBoton() {
        //rehacer
    }

    void testCuandoReceptorEsChocadoPorUnaBalaSeActivaEntoncesLaCompuertaSeAbre() {
        // World world;
        // int d = 6;
        // world.createLauncher(0, 0, DIRECTION::RIGHT_DIRECTION);
        // Receiver *receiver = world.createReceiver(d, 0);
        // Gate *gate = world.createGate(0, 10);
        // gate->setBooleanSupplier(receiver);
        // receiver->setGate(gate);
        //
        // // deberia chocar la bala con el receptor.
        // for (int i = 0; i < 1000; i++) {
        //     world.getGameLoop()->step();
        // }
        //
        // Update update = gate->createUpdate(COMMAND::UPDATE_COMMAND);
        // TS_ASSERT_EQUALS(STATUS::GATE_OPENED, update.getStatus());
    }
};

#endif

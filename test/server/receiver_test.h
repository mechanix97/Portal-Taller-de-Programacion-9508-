#ifndef __RECEIVER_TEST_H__
#define __RECEIVER_TEST_H__

#include <cxxtest/TestSuite.h>
#include "../../server/include/bodies/receiver/receiver.h"
#include "../../server/include/bodies/launcher/launcher.h"
#include "../../server/include/bodies/bullet/bullet.h"
#include "../../server/include/world.h"

class ReceiverTest: public CxxTest::TestSuite {
public:
    void testReceiverRecienConstruidoNoEstaActivo() {
        World world;

        Receiver *receiver = world.createReceiver(1, 1);

        TS_ASSERT(!receiver->isOn());
    }

    void testBulletChocaConReceiverYDebeActivarlo() {
    //     World world;
    //     Receiver *receiver = world.createReceiver(1, 1);
    //     world.createBullet(1, 1, DIRECTION::RIGHT_DIRECTION);
    //
    //     world.step();
    //
    //     TS_ASSERT_EQUALS(true, receiver->isOn());
    }

    void testLauncherLanzaBalaDebeActivarReceptor() {
        // World world;
        // world.createLauncher(0, 0, DIRECTION::RIGHT_DIRECTION);
        // Receiver *receiver = world.createReceiver(6, 0);
        //
        // // eberia chocar la bala con el receptor.
        // for (int i = 0; i < 200; i++) {
        //     world.step();
        //     world.applyStateActions();
        //     world.deleteBodiesForDeletion();
        // }
        //
        // TS_ASSERT(receiver->isOn());
    }
};

#endif

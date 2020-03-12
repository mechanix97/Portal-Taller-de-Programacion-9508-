#ifndef __PORTAL_CHELL_H__
#define __PORTAL_CHELL_H__

#ifndef __TESTBED__
#define __TESTBED__
#endif

#include "../../../../server/include/world.h"
#include "../../../../server/include/bodies/chell/chell.h"
#include "../../../../server/include/bodies/block/block.h"
#include "../../../../server/include/bodies/button/button.h"
#include "../../../../server/include/bodies/gate/gate.h"
#include "../../../../server/include/bodies/receiver/receiver.h"
#include "../../../../server/include/serializer.h"
#include "../../../../common/include/update.h"
#include <iostream>
#include <string>

class PortalChell: public Test {
private:
    World world;
    Chell *chell;

    public:
    PortalChell():
        world(this->m_world) {
        this->m_world->SetGravity(b2Vec2(0.0, -9.8));
        this->chell = this->world.createChell(16.4309, -10);
        Serializer s;
        s.deserialize(
            &this->world,
            "../../../maps/test_bullet_00.yaml",
            "../../../config/config.yaml" );
    }

    void Step(Settings *settings) {
        Test::Step(settings);
        this->world.getGameLoop()->step();
    }

    static Test *Create() {
        return new PortalChell();
    }

    void Keyboard(int key) {
        switch (key) {
        case GLFW_KEY_A:
            std::cout << "pressed left" << std::endl;
            this->chell->pressLeft();
            break;
        case GLFW_KEY_D:
            std::cout << "pressed right" << std::endl;
            this->chell->pressRight();
            break;
        case GLFW_KEY_W:
            std::cout << "pressed up" << std::endl;
            this->chell->pressUp();
            break;
        case GLFW_KEY_E:
            std::cout << "pressed E" << std::endl;
            this->chell->pressGrab();
            break;
        }
    }

    void KeyboardUp(int key) {
        switch (key) {
        case GLFW_KEY_A:
            std::cout << "released left" << std::endl;
            this->chell->releaseLeft();
            break;
        case GLFW_KEY_D:
            std::cout << "released right" << std::endl;
            this->chell->releaseRight();
            break;
        case GLFW_KEY_W:
            std::cout << "released up" << std::endl;
            this->chell->releaseUp();
            break;
        case GLFW_KEY_E:
            std::cout << "released E" << std::endl;
            this->chell->releaseGrab();
            break;
        }
    }

    virtual void MouseDown(const b2Vec2& p) override {
        std::cout << "p : (" << p.x << ", " << p.y <<  ")" << std::endl;
        PortalGun *portal_gun = this->chell->getPortalGun();
        portal_gun->firePortalOne(p.x, p.y);
    }
};

#endif

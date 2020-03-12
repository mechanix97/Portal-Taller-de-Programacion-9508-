#include "../../../include/bodies/rock/rock.h"

#include <cstdint>
#include "../../../include/world.h"
#include "../../../include/bodies/laser/laser.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/instructions/destroy_body_instruction.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Rock::Rock(World *world, float x, float y):
    Body(world, ENTITY::ROCK),
    chell(nullptr) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.userData = (void *) this;
    bodyDef.awake = true;

    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;

    this->b2body->CreateFixture(&boxFixtureDef);
}

Rock::~Rock() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Chell *Rock::getChell() const {
    return this->chell;
}


bool Rock::isGrabbed() const {
    return this->chell != nullptr;
}

void Rock::beGrabbedBy(Chell *chell) {
    if (!this->isGrabbed()) {
        this->chell = chell;
    }
}

void Rock::tryReleaseFromChell() {
    if (this->isGrabbed()) {
        this->chell->releaseRock();
        this->chell = nullptr;
    }
}

Update Rock::createUpdate(COMMAND command) const {
    Update update(
        command,
        ENTITY::ROCK,
        this->getBodyId(),
        STATUS::NONE_STATUS,
        this->getPosX() * ZOOM_FACTOR,
        this->getPosY() * ZOOM_FACTOR,
        0);
    return update;
}

void Rock::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);

}

void Rock::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    bullet->handleBeginContactWith(this, contact);
}

void Rock::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->handleBeginContactWith(this, contact);
}

void Rock::handleBeginContactWith(Laser *laser, b2Contact *contact) {
    laser->handleBeginContactWith(this, contact);
}

void Rock::handleBeginContactWith(Portal *portal, b2Contact *contact) {
    bool change_angle = false;
    float d = std::max(WIDTH/2, HEIGHT/2);
    portal->teleportToOppositePortal(this, change_angle, d);
}

void Rock::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

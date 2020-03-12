#include "../../../include/bodies/receiver/receiver.h"
#include "../../../include/world.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../include/instructions/destroy_body_instruction.h"

Receiver::Receiver(World *world, float x, float y):
    Body(world, ENTITY::RECEIVER_BLOCK),
    is_on(false),
    gate(0) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->WIDHT/2, this->HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

Receiver::~Receiver() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Update Receiver::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->getBodyId(),
        STATUS::NONE_STATUS,
        this->getPosX() * ZOOM_FACTOR,
        this->getPosY() * ZOOM_FACTOR,
        0);
    return update;
}

bool Receiver::isOn() const {
    return is_on;
}

void Receiver::turnOn() {
    if (!this->is_on) {
        this->is_on = true;
        if (this->gate != 0) {
            this->gate->tryChangeState();
        }
    }
}

void Receiver::setGate(Gate *gate) {
    this->gate = gate;
}

bool Receiver::getAsBoolean() const {
    return this->isOn();
}

void Receiver::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Receiver::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    this->turnOn();
    this->world->addInstruction(new DestroyBodyInstruction(bullet));
}

void Receiver::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->land();
}

void Receiver::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

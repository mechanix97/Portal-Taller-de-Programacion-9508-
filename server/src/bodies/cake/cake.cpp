#include "../../../include/bodies/cake/cake.h"
#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <set>
#include "../../../include/bodies/chell/chell.h"

Cake::Cake(World *world, float x, float y):
    Body(world, ENTITY::CAKE) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;
    b2bodydef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

unsigned int Cake::chellCount() const {
    return this->chell_set.size();
}

void Cake::insertChellInSet(Chell *chell) {
    this->chell_set.insert(chell);
}


Update Cake::createUpdate(COMMAND command) const {
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

void Cake::handleBeginContactWith(Body *body, b2Contact *contact) {
    body->handleBeginContactWith(this, contact);
}

void Cake::handleEndContactWith(Body *body, b2Contact *contact) {
    body->handleEndContactWith(this, contact);
}

void Cake::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    this->insertChellInSet(chell);
    if (this->world->everybodyAteTheCake()) {
        Update update;
        update.setCommand(COMMAND::WIN_COMMAND);
        this->world->addUpdate(update);
    }
}

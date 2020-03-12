#include "../../../include/bodies/acid/acid.h"
#include "../../../include/bodies/body.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2EdgeShape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Acid::Acid(World *world,  float x, float y):
    Body(world, ENTITY::ACID) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(x, y - (1.5 * HEIGHT));
    b2bodydef.awake = false;
    b2bodydef.userData = (void *) this;
    this->b2body = this->world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->WIDTH/2, this->HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

Acid::~Acid() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Update Acid::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->getBodyId(),
        STATUS::NONE_STATUS,
        (this->b2body->GetPosition().x) * ZOOM_FACTOR,
        (this->b2body->GetPosition().y) * ZOOM_FACTOR,
        0);
    return update;
}

void Acid::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Acid::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->changeStateToDead();
}

void Acid::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

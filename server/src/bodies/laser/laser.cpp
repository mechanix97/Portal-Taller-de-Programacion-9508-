#include "../../../include/bodies/laser/laser.h"
#include <string>
#include <sstream>
#include "../../../include/world.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/instructions/destroy_body_instruction.h"
#include "../../../include/instructions/release_rock_instruction.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/exceptions.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Laser::Laser(World *world, float x, float y, ANGLE angle):
    Body(world, ENTITY::LASER),
    angle(angle) {
    if (angle != ANGLE::ANGLE_000 && angle != ANGLE_090) {
        std::stringstream ss("Error Laser: Angulo invalido");
        ss << angle;
        throw genericError(ss.str().c_str());
    }

    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.angle = DEGTORAD(angle);
    b2bodydef.userData = (void *) this;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;
    b2fixturedef.isSensor = true;

    this->b2body->CreateFixture(&b2fixturedef);
}

Update Laser::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->getPosX() * ZOOM_FACTOR,
        this->getPosY() * ZOOM_FACTOR,
        this->angle);
    return update;
}

void Laser::handleBeginContactWith(Body *body, b2Contact *contact) {
    body->handleBeginContactWith(this, contact);
}

void Laser::handleBeginContactWith(Rock *rock, b2Contact *contact) {
    if (rock->isGrabbed()) {
        Chell *chell = rock->getChell();
        this->world->addInstruction(new ReleaseRockInstruction(chell));
    }
    this->world->addUpdate(rock->createUpdate(COMMAND::DESTROY_COMMAND));
    this->world->addInstruction(new DestroyBodyInstruction(rock));
}

void Laser::handleEndContactWith(Body *body, b2Contact *contact) {
    body->handleEndContactWith(this, contact);
}

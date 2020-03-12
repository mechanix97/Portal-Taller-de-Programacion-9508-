#include "../../../include/bodies/portal/portal.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2EdgeShape.h"
#include "../../../include/world.h"
#include "../../../include/math_ext.h"
#include "../../../include/instructions/teleport_body_instruction.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/rock/rock.h"
#include <iostream>
#include <cmath>

Portal::Portal(World *world, uint8_t portal_number, b2Vec2 pos, b2Vec2 normal):
    Body(world, portal_number == NPORTAL1 ? ENTITY::PORTAL1 : ENTITY::PORTAL2),
    normal(normal),
    opposite(nullptr) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2Vec2 adj_pos = pos +  (HEIGHT/2)*normal;
    b2bodydef.position.Set(adj_pos.x, adj_pos.y);

    float new_angle = MathExt::angle(normal, b2Vec2(1, 0)) + (PI/2);
    if (normal.y < 0) {
        new_angle = 2*PI - new_angle;
    }

    b2bodydef.angle = new_angle;
    b2bodydef.fixedRotation = true;
    b2bodydef.userData = (void *) this;
    b2bodydef.active = true;
    b2bodydef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.isSensor = true;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
    this->world->addUpdate(this->createUpdate(COMMAND::CREATE_COMMAND));
}

Portal::~Portal() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

void Portal::teleportBody(Body *body, bool change_angle, float d, float alfa) const {
    b2Vec2 v = body->getLinearVelocity();
    b2Vec2 new_pos = this->getPosition() + (d + HEIGHT)*this->normal;
    b2Vec2 new_v;

    if (v.Length() == 0) {
        new_v = b2Vec2(0, 0);
    } else {
        new_v = MathExt::rotate(v.Length() * this->normal, alfa);
    }

    float new_angle;
    if (change_angle) {
        new_angle = alfa;
    } else {
        new_angle = body->getAngle();
    }

    Instruction *inst = new TeleportBodyInstruction(
        body,
        new_v,
        new_pos,
        new_angle);
    this->getWorld()->addInstruction(inst);
}


void Portal::teleportToOppositePortal(
    Body *body, bool change_angle, float d) const {
    if (this->opposite != nullptr) {
        float alfa = MathExt::angle(this->normal, -body->getLinearVelocity());
        this->opposite->teleportBody(body, change_angle, d, alfa);
    }
}


void Portal::setOppositePortal(Portal *opposite) {
    this->opposite = opposite;
}

Update Portal::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->getPosX() * ZOOM_FACTOR,
        this->getPosY() * ZOOM_FACTOR,
        (int32_t)RADTODEG(-this->getAngle()));
    return update;
}

void Portal::handleBeginContactWith(Body *body, b2Contact *contact) {
    body->handleBeginContactWith(this, contact);
}

void Portal::handleEndContactWith(Body *body, b2Contact *contact) {
    body->handleEndContactWith(this, contact);
}

void Portal::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    bullet->handleBeginContactWith(this, contact);
}

void Portal::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->handleBeginContactWith(this, contact);
}

void Portal::handleBeginContactWith(Rock *rock, b2Contact *contact) {
    rock->handleBeginContactWith(this, contact);
}

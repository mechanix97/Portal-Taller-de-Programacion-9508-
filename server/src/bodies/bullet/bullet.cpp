#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/world.h"
#include "../../../include/instructions/destroy_body_instruction.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2CircleShape.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/receiver/receiver.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/math_ext.h"
#include <cstdint>
#include <iostream>
#include <algorithm>

Bullet::Bullet(World *world, float x, float y, DIRECTION direction):
    Body(world, ENTITY::BULLET),
    direction(direction),
    life_steps(0),
    def(world->getWorldConfig().bullet_def),
    is_destroyed(false) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_dynamicBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;
    b2bodydef.awake = true;
    b2bodydef.bullet = false;
    b2bodydef.gravityScale = 0.0;
    // b2bodydef.fixedRotation = true;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2CircleShape b2circleshape;
    b2circleshape.m_radius = 0.1;
    b2circleshape.m_p.Set(0, 0);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2circleshape;
    b2fixturedef.userData = (void *) this;
    b2fixturedef.density = this->DENSITY;
    b2fixturedef.isSensor = false;
    b2fixturedef.restitution = 1.00;

    this->b2body->CreateFixture(&b2fixturedef);
    const unsigned int SPEED = this->def.speed;

    switch (direction) {
        case DIRECTION::RIGHT_DIRECTION:
            this->setLinearVelocity(SPEED*b2Vec2(1, 0));
            break;
        case DIRECTION::LEFT_DIRECTION:
            this->setLinearVelocity(SPEED*b2Vec2(-1, 0));
            break;
        case DIRECTION::UP_DIRECTION:
            this->setLinearVelocity(SPEED*b2Vec2(0, 1));
            break;
        case DIRECTION::DOWN_DIRECTION:
            this->setLinearVelocity(SPEED*b2Vec2(0, -1));
            break;
    }
}

Bullet::~Bullet() {
    if (this->b2body != nullptr) {
        world->getB2World()->DestroyBody(this->b2body);
    }
}

Update Bullet::createUpdate(COMMAND command) const {
    int32_t angle = MathExt::angle(b2Vec2(1, 0), this->getLinearVelocity());
    if (this->getLinearVelocity().y < 0) {
        angle = 2*M_PI - angle;
    }

    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        -RADTODEG(angle));
    return update;
}

void Bullet::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Bullet::handleBeginContactWith(Block *block, b2Contact *contact) {
    block->handleBeginContactWith(this, contact);
}

void Bullet::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    this->tryDestroy();
    bullet->tryDestroy();
}

void Bullet::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->handleBeginContactWith(this, contact);
}

void Bullet::handleBeginContactWith(Launcher *launcher, b2Contact *contact) {
    this->tryDestroy();
}

void Bullet::handleBeginContactWith(Receiver *receiver, b2Contact *contact) {
    receiver->turnOn();
    this->tryDestroy();
}

void Bullet::handleBeginContactWith(Rock *rock, b2Contact *contact) {
    this->tryDestroy();
}

void Bullet::handleBeginContactWith(Portal *portal, b2Contact *contact) {
    bool change_angle = true;
    float d = std::max(WIDTH/2, HEIGHT/2);
    portal->teleportToOppositePortal(this, change_angle, d);
}

void Bullet::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Bullet::applyStateAction() {
    this->life_steps++;
    if (this->life_steps > this->def.max_life_steps * FPS_FACTOR) {
        this->tryDestroy();
    }
}

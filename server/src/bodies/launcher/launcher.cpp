#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/instructions/create_bullet_instruction.h"
#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

Launcher::Launcher(
    World *world,
    float x, float y,
    DIRECTION direction):
    Body(world, ENTITY::LAUNCH_BLOCK),
    direction(direction),
    counter(200) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;
    b2bodydef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->WIDTH / 2, this->HEIGHT / 2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

Launcher::~Launcher() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Update Launcher::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        this->direction);
    return update;
}

void Launcher::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Launcher::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    bullet->handleBeginContactWith(this, contact);
}

void Launcher::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->land();
}

void Launcher::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Launcher::applyStateAction() {
    unsigned int MAX = this->world->getWorldConfig().launcher_def.steps_per_launch;
    if (this->counter >= MAX * FPS_FACTOR) {
        this->counter = 0;
        this->fireABullet();
    } else {
        this->counter += 1;
    }
}

Bullet *Launcher::fireABullet() {
    float x = this->getPosX();
    float y = this->getPosY();

    Bullet *bullet = nullptr;
    switch (this->direction) {
        case DIRECTION::RIGHT_DIRECTION:
            x += MIN_CREATE_DISTANCE;
            bullet = this->world->createBullet(x, y, DIRECTION::RIGHT_DIRECTION);
            break;
        case DIRECTION::LEFT_DIRECTION:
            x -= MIN_CREATE_DISTANCE;
            bullet = this->world->createBullet(x, y, DIRECTION::LEFT_DIRECTION);
            break;
        case DIRECTION::UP_DIRECTION:
            y += MIN_CREATE_DISTANCE;
            bullet = this->world->createBullet(x, y, DIRECTION::UP_DIRECTION);
            break;
        case DIRECTION::DOWN_DIRECTION:
            y -= MIN_CREATE_DISTANCE;
            bullet =this->world->createBullet(x, y, DIRECTION::DOWN_DIRECTION);
            break;
    }
    Update update = bullet->createUpdate(COMMAND::CREATE_COMMAND);
    this->world->addUpdate(update);
    return bullet;
}

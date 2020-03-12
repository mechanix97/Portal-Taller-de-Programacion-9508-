#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/block/shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../include/bodies/block/metal_material.h"
#include "../../../include/bodies/block/stone_material.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/world.h"

Block::Block(
    World *world,
    float x, float y, ORIENTATION orientation,
    Shape *shape, Material *material):
    Body(world, shape->createEntityWithMaterial(material)),
    orientation(orientation), shape(shape), material(material),
    def(world->getWorldConfig().block_def) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = -orientation * (3.1415/2);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;


    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape b2polygonshape = this->shape->giveShape(WIDTH, HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &b2polygonshape;
    boxFixtureDef.density = this->DENSITY;
    boxFixtureDef.userData = (void *) this;
    boxFixtureDef.friction = this->def.friction;
    boxFixtureDef.restitution = 0.00;

    b2Fixture* b2fixture = this->b2body->CreateFixture(&boxFixtureDef);
    b2fixture->SetUserData((void *)this);

    this->shape = shape;
    this->material = material;
}

Block::~Block() {
    delete shape;
    delete material;
    this->world->getB2World()->DestroyBody(this->b2body);
}

bool Block::canOpenPortalOnSurface() const {
    return this->material->canOpenPortalOnSurface();
}


Update Block::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        this->orientation);
    return update;
}

void Block::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Block::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Block::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    this->material->handleBeginContactWith(bullet, contact);
}

void Block::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->land();
}

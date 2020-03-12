#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/world.h"
#include <iostream>

Button::Button(World *world, float x, float y):
    Body(world, ENTITY::BUTTON),
    def(world->getWorldConfig().button_def) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x -Cx, y - Cy);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2Vec2 vertices[6];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(0.15, 0.12);
    vertices[2].Set(0.50, 0.25);
    vertices[3].Set(1.50, 0.25);
    vertices[4].Set(1.85, 0.12);
    vertices[5].Set(2.00, 0.00);

    b2PolygonShape b2polygonshape;
    b2polygonshape.Set(vertices, 6);

    b2FixtureDef fixtureDef;
    fixtureDef.friction = this->def.friction;
    fixtureDef.restitution = this->RESTITUTION;
    fixtureDef.shape = &b2polygonshape;
    this->b2body->CreateFixture(&fixtureDef);
    this->is_pressed = false;
}

Button::~Button() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

bool Button::isPressed() const {
    return this->is_pressed;
}

Update Button::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->getBodyId(),
        this->is_pressed ? STATUS::BUTTON_ON: STATUS::BUTTON_OFF,
        (this->b2body->GetPosition().x + Cx) * ZOOM_FACTOR,
        (this->b2body->GetPosition().y + Cy) * ZOOM_FACTOR,
        0);
    return update;
}


void Button::press() {
    if (!this->isPressed()) {
        this->is_pressed = true;
        this->notifyStatusChangeToGate();
    }
}

void Button::release() {
    if (this->isPressed()) {
        this->is_pressed = false;
        this->notifyStatusChangeToGate();
    }
}

void Button::setGate(Gate *gate) {
    this->gate = gate;
}

void Button::notifyStatusChangeToGate() {
    if (this->gate != 0) {
        gate->tryChangeState();
    }
}

bool Button::getAsBoolean() const {
    return this->isPressed();
}

void Button::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Button::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    this->press();
    chell->land();
}

void Button::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Button::handleEndContactWith(Chell *chell, b2Contact *contact) {
    this->release();
}

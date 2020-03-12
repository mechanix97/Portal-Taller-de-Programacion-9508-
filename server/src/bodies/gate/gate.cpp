#include "../../../include/bodies/gate/gate.h"

#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/boolean_suppliers/boolean_block.h"
#include <iostream>

Gate::Gate( World *world, float x, float y):
    Body(world, ENTITY::GATE),
    closed_gate_state(this),
    opening_gate_state(this),
    open_gate_state(this),
    closing_gate_state(this),
    state(&this->closed_gate_state),
    boolean_block(nullptr) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x - (MAX_WIDTH/2), y + (MAX_HEIGHT/2));
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape b2polygonshape;
    b2Vec2 vertices[4];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(MAX_WIDTH, 0.00);
    vertices[2].Set(MAX_WIDTH, -MAX_HEIGHT);
    vertices[3].Set(0.00, -MAX_HEIGHT);
    b2polygonshape.Set(vertices, 4);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &b2polygonshape;
    this->b2body->CreateFixture(&fixtureDef);

    this->heights = std::vector<float>({
        4.00, 4.00, 3.80, 3.72, 3.62, 3.56, 3.34, 3.14, 2.92, 2.70,
        2.18, 1.84, 1.48, 1.10, 0.72, 0.48, 0.36, 0.32, 0.32});
    this->it = this->heights.begin();
}

Gate::~Gate() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Update Gate::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        this->state->getStatus(),
        (this->b2body->GetPosition().x + (MAX_WIDTH/2))* ZOOM_FACTOR,
        (this->b2body->GetPosition().y - (MAX_HEIGHT/2))* ZOOM_FACTOR,
        0);
    return update;
}

void Gate::setBooleanBlock(BooleanBlock *boolean_block) {
    this->boolean_block = boolean_block;
}

BooleanBlock *Gate::getBooleanBlock() {
    return this->boolean_block;
}

void Gate::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Gate::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    b2Vec2 normal = this->getNormal(contact);

    if (normal.y < 0) {
        chell->changeStateToDead();
    } else {
        chell->land();
    }
}

void Gate::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Gate::applyStateAction() {
    this->state->applyStateAction();
}

void Gate::tryChangeState() {
    this->state->tryChangeState();
}

bool Gate::conditionIsMeet() {
    return this->boolean_block->getAsBoolean();
}

void Gate::changeStateToOpening() {
    this->state = &this->opening_gate_state;
}

void Gate::changeStateToOpen() {
    this->state = &this->open_gate_state;
}

void Gate::changeStateToClosing() {
    this->state = &this->closing_gate_state;
}

void Gate::changeStateToClosed() {
    this->state = &this->closed_gate_state;
}

void Gate::shrink() {
    b2Fixture *b2fixture = this->b2body->GetFixtureList();
    b2PolygonShape *b2polygonshape = (b2PolygonShape *) b2fixture->GetShape();

    b2Vec2 vertices[4];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(MAX_WIDTH, 0.00);
    vertices[2].Set(MAX_WIDTH, -*this->it);
    vertices[3].Set(0.00, -*this->it);

    b2polygonshape->Set(vertices, 4);
    this->it++;
}

void Gate::grow() {
    b2Fixture *b2fixture = this->b2body->GetFixtureList();
    b2PolygonShape *b2polygonshape = (b2PolygonShape *) b2fixture->GetShape();

    this->it--;

    b2Vec2 vertices[4];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(MAX_WIDTH, 0.00);
    vertices[2].Set(MAX_WIDTH, -*this->it);
    vertices[3].Set(0.00, -*this->it);

    b2polygonshape->Set(vertices, 4);
}

bool Gate::isOnMinSize() const {
    return this->it == this->heights.end();
}

bool Gate::isOnMaxSize() const {
    return this->it == this->heights.begin();
}

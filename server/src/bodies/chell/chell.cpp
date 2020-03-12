#include "../../../include/bodies/chell/chell.h"

#include <iostream>
#include <algorithm>
#include "../../../include/world.h"
#include "../../../include/ray_cast_closest_body_callback.h"
#include "../../../include/bodies/body.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/bodies/chell/chell_state.h"
#include "../../../include/bodies/chell/idle_state.h"
#include "../../../include/bodies/chell/running_state.h"
#include "../../../include/bodies/chell/jumping_state.h"
#include "../../../include/bodies/chell/fire_state.h"
#include "../../../include/bodies/chell/fire_to_idle_state.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/receiver/receiver.h"
#include "../../../../common/include/key.h"
#include "../../../../common/include/keypad.h"
#include "../../../../common/include/types.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/bodies/cake/cake.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2DistanceJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2PulleyJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2WeldJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2MouseJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2RopeJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2FrictionJoint.h"
#include "../../libs/Box2D-master/Box2D/Collision/b2Collision.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/Contacts/b2Contact.h"
#include "../../../include/instructions/grab_rock_instruction.h"
#include "../../../include/instructions/release_rock_instruction.h"
#include "../../../include/instructions/destroy_body_instruction.h"


Chell::Chell(World *world, float x, float y):
    Body(world, ENTITY::CHELL),
    is_facing_right(true),
    idle_state(this),
    running_state(this),
    jumping_state(this),
    dead_state(this),
    fire_state(this),
    fire_to_idle_state(this),
    jiging_state(this),
    falling_state(this),
    landing_state(this),
    turning_state(this),
    stopping_state(this),
    state(&this->idle_state),
    portal_gun(this),
    is_in_grabbing_mode(false),
    joint(nullptr),
    def(world->getWorldConfig().chell_def) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;
    bodyDef.fixedRotation = true;
    bodyDef.bullet = true;

    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2Vec2 vertices[6];
    vertices[0].Set(-WIDTH/2, HEIGHT/2);
    vertices[1].Set(WIDTH/2, HEIGHT/2);
    vertices[2].Set(WIDTH/2, -(3.88/8.0)*HEIGHT);
    vertices[3].Set(WIDTH/4, -HEIGHT/2);
    vertices[4].Set(-WIDTH/4, -HEIGHT/2);
    vertices[5].Set(-WIDTH/2, -(3.88/8.0)*HEIGHT);
    b2PolygonShape b2polygonshape;
    b2polygonshape.Set(vertices, 6);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &b2polygonshape;
    boxFixtureDef.density = this->DENSITY;
    boxFixtureDef.userData = (void *) this;
    boxFixtureDef.friction = this->FRICTION;
    boxFixtureDef.restitution = this->RESTITUTION;

    b2Fixture* b2fixture = this->b2body->CreateFixture(&boxFixtureDef);
    b2fixture->SetUserData((void *)this);
}

Chell::~Chell() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

void Chell::firePortalOne(float x, float y) {
    this->state->firePortalOne(x, y);
}

void Chell::firePortalTwo(float x, float y) {
    this->state->firePortalTwo(x, y);
}

bool Chell::hasReachedMaxHorizontalSpeed() const {
    float x_speed = std::abs(this->getLinearVelocity().x);
    return x_speed > this->def.max_horizontal_speed;
}


bool Chell::isGrabbingARock() const {
    return this->joint != nullptr;
}

void Chell::releaseRock() {
    if (this->isGrabbingARock()) {
        this->world->getB2World()->DestroyJoint(this->joint);
        this->joint = nullptr;
    }
}


void Chell::grabRock(Rock *rock) {
    if (!this->isGrabbingARock()) {
        b2DistanceJointDef jointdef;
        jointdef.length = 0;
        jointdef.frequencyHz = 1.0;
        jointdef.dampingRatio = 0.5;
        jointdef.Initialize(this->getB2Body(), rock->getB2Body(),
                            this->getPosition(), rock->getPosition());
        this->joint = this->world->getB2World()->CreateJoint(&jointdef);
        rock->beGrabbedBy(this);
    }
}

bool Chell::isInGrabbingMode() const {
    return this->is_in_grabbing_mode;
}

void Chell::enterGrabbingMode() {
    this->is_in_grabbing_mode = true;
}

void Chell::exitGrabbingMode() {
    this->is_in_grabbing_mode = false;
}

PortalGun *Chell::getPortalGun() {
    return &this->portal_gun;
}

bool Chell::isFacingRight() const {
    return this->is_facing_right;
}

bool Chell::isFacingLeft() const {
    return !this->isFacingRight();
}

void Chell::faceRight() {
    this->is_facing_right = true;
}

void Chell::faceLeft() {
    this->is_facing_right = false;
}

void Chell::faceOppositeDirection() {
    this->is_facing_right = !this->is_facing_right;
}

Update Chell::createUpdate(COMMAND command) const {
    Update update(
        command,
        ENTITY::CHELL,
        this->BODY_ID,
        this->state->getStatus(),
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        this->is_facing_right? 1 : 0);
    return update;
}

void Chell::jig() {
    this->state->jig();
}

void Chell::pressGrab() {
    if (this->isGrabbingARock()) {
        this->world->addInstruction(new ReleaseRockInstruction(this));
    } else {
        this->enterGrabbingMode();
    }
}

void Chell::releaseGrab() {
    if (this->isInGrabbingMode()) {
        this->exitGrabbingMode();
    }
}


void Chell::pressLeft() {
    this->keypad.press(KEY::LEFT_KEY);
    this->state->pressLeft();
}

void Chell::releaseLeft() {
    this->keypad.release(KEY::LEFT_KEY);
    this->state->releaseLeft();
}

void Chell::pressRight() {
    this->keypad.press(KEY::RIGHT_KEY);
    this->state->pressRight();
}

void Chell::releaseRight() {
    this->keypad.release(KEY::RIGHT_KEY);
    this->state->releaseRight();
}

void Chell::pressUp() {
    this->keypad.press(KEY::UP_KEY);
    this->state->pressUp();
}

void Chell::releaseUp() {
    this->keypad.release(KEY::UP_KEY);
    this->state->releaseUp();
}

void Chell::changeStateToRunning() {
    this->state = &this->running_state;
}

void Chell::changeStateToIdle() {
    this->state = &this->idle_state;
}

void Chell::changeStateToJumping() {
    this->state = &this->jumping_state;
}

void Chell::changeStateToDead() {
    this->state = &this->dead_state;
}

void Chell::changeStateToFire() {
    this->fire_state.resetStepCount();
    this->state = &this->fire_state;
}

void Chell::changeStateToFireToIdle() {
    this->state = &this->fire_to_idle_state;
}

void Chell::changeStateToJiging() {
    this->state = &this->jiging_state;
}

void Chell::changeStateToFalling() {
    this->state = &this->falling_state;
}

void Chell::changeStateToLanding() {
    this->state = &this->landing_state;
    this->state->resetStepCount();
}

void Chell::changeStateToTurning() {
    this->state = &this->turning_state;
    this->state->resetStepCount();
}

void Chell::changeStateToStopping() {
    this->state = &this->stopping_state;
    this->state->resetStepCount();
}


void Chell::land() {
    this->state->land();
}

void Chell::applyLinearImpulseToLeft() {
    float mass = this->b2body->GetMass();
    float impx = mass * this->def.horizontal_speed;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-impx, 0), true);
}

void Chell::applyLinearImpulseToRight() {
    float mass = this->b2body->GetMass();
    float impx = mass * this->def.horizontal_speed;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(impx, 0), true);
}

void Chell::applyLinearImpulseToUp() {
    float mass = this->b2body->GetMass();
    float impy = mass * this->def.jumpspeed;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(0, impy), true);
}

void Chell::stopLeftMovement() {
    b2Vec2 v = this->b2body->GetLinearVelocity();
    if (v.x < 0) {
        float mass = this->b2body->GetMass();
        float impx = mass * v.x;
        this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-impx, 0), true);
    }
}

void Chell::stopRightMovement() {
    b2Vec2 v = this->b2body->GetLinearVelocity();
    if (v.x > 0) {
        float mass = this->b2body->GetMass();
        float impx = mass * v.x;
        this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-impx, 0), true);
    }
}

Keypad *Chell::getKeypad() {
    return &this->keypad;
}

void Chell::applyStateAction() {
    this->state->applyStateAction();
}

void Chell::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Chell::handleBeginContactWith(Acid *acid, b2Contact *contact) {
    this->changeStateToDead();
}

void Chell::handleBeginContactWith(Block *block, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    this->state->handleBeginContactWith(bullet);
    bullet->tryDestroy();
}

void Chell::handleBeginContactWith(Button *button, b2Contact *contact) {
    button->press();
    this->land();
}

void Chell::handleBeginContactWith(Cake *cake, b2Contact *contact) {
    cake->handleBeginContactWith(this, contact);
}

void Chell::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Gate *gate, b2Contact *contact) {
    gate->handleBeginContactWith(this, contact);
}

void Chell::handleBeginContactWith(Launcher *launcher, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Portal *portal, b2Contact *contact) {
    bool change_angle = false;
    float d = std::max(WIDTH/2, HEIGHT/2);
    portal->teleportToOppositePortal(this, change_angle, d);
}

void Chell::handleBeginContactWith(Receiver *receiver, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Rock *rock, b2Contact *contact) {
    b2Vec2 normal = this->getNormal(contact);

    if (normal.y > 0) {
        this->changeStateToDead();
        this->world->addUpdate(this->createUpdate(COMMAND::UPDATE_COMMAND));
    } else if (this->isInGrabbingMode() && !rock->isGrabbed()) {
        this->world->addInstruction(new GrabRockInstruction(this, rock));
        this->exitGrabbingMode();
    }
    this->land();
}

void Chell::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Chell::handleEndContactWith(Button *button, b2Contact *contact) {
    button->release();
}

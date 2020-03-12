#include "../include/ray_cast_closest_body_callback.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2WorldCallbacks.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include <iostream>

RayCastClosestBodyCallback::RayCastClosestBodyCallback():
    hit(false),
    body(0) {
}


float32 RayCastClosestBodyCallback::ReportFixture(
    b2Fixture* fixture, const b2Vec2& point,
    const b2Vec2& normal, float32 fraction) {
    this->body = (Body *)fixture->GetBody()->GetUserData();

    this->hit = true;
    this->point = point;
    this->normal = normal;

    return fraction;
}

bool RayCastClosestBodyCallback::hasHit() const {
    return this->hit;
}

Body *RayCastClosestBodyCallback::getBody() const {
    return this->body;
}

b2Vec2 RayCastClosestBodyCallback::getPoint() const {
    return this->point;
}

b2Vec2 RayCastClosestBodyCallback::getNormal() const {
    return this->normal;
}

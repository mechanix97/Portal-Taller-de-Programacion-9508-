#ifndef __RAY_CAST_CLOSEST_BODY_CALLBACK_H__
#define __RAY_CAST_CLOSEST_BODY_CALLBACK_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2WorldCallbacks.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"

class Body;

class RayCastClosestBodyCallback: public b2RayCastCallback {
private:
    bool hit;
    Body *body;
    b2Vec2 point;
    b2Vec2 normal;

public:
    RayCastClosestBodyCallback();

    float32 ReportFixture(
        b2Fixture* fixture, const b2Vec2& point,
        const b2Vec2& normal, float32 fraction) override;

    /* Indica si hubo colision con algun body */
    bool hasHit() const;

    /* Devuelve el body mas cercano */
    Body *getBody() const;

    /*  Devuelve el punto en el que hubo colision */
    b2Vec2 getPoint() const;

    /* Devuelve la normal */
    b2Vec2 getNormal() const;
};

#endif

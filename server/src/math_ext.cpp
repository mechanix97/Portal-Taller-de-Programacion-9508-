#include "../include/math_ext.h"
#include <cmath>

b2Vec2 MathExt::reflect(b2Vec2 n, b2Vec2 v) {
    b2Vec2 r = v - (1/n.LengthSquared())*(2*(v*n)*n);
    return r;
}

float MathExt::angle(b2Vec2 v, b2Vec2 w) {
    return acos((v*w)/(v.Length()*w.Length()));
}

b2Vec2 MathExt::rotate(b2Vec2 v, float alfa) {
    b2Vec2 w;
    float x = v.x*cos(alfa) - v.y*sin(alfa);
    float y = v.x*sin(alfa) + v.y*cos(alfa);
    w.Set(x, y);
    return w;
}

float operator*(const b2Vec2& v, const b2Vec2& u) {
    return (v.x * u.x) + (v.y * u.y);
}

#ifndef __MATH_H__
#define __MATH_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"

/* Clase que extiende las funcionalidades de b2Math */
class MathExt {
public:
    /* n es un vector normal de una superficie.
     * v es un vector.
     * Devuelve un vector resultado de la reflexion de v respecto
     * a n */
    static b2Vec2 reflect(b2Vec2 n, b2Vec2 v);

    /* Calcula el angulo en radianes entre v y w.
     * Pre: v y w pertencen a R2 */
    static float angle(b2Vec2 v, b2Vec2 w);

    /* Rota al vector v en un angulo alfa.
     * Pre: v pertenece a R2 y alfa en radianes. */
    static b2Vec2 rotate(b2Vec2 v, float alfa);
};

/* Devuelve el producto escalar entre u y v.
 * Pre: u y v pertenecer a R2. */
float operator*(const b2Vec2& v, const b2Vec2& u);

#endif

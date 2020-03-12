#ifndef __DIAGONAL_SHAPE_H__
#define __DIAGONAL_SHAPE_H__

#include "shape.h"

class Material;

class DiagonalShape: public Shape {
private:
    float angle;

public:
    /* Genera un triangulo rectangulode catetos de longitud width y height */
    virtual b2PolygonShape giveShape(float width, float height) override;

    /* Devuelve un identificador del tipo de bloque dado un material y
     * la forma diagonal. */
    virtual ENTITY createEntityWithMaterial(Material *material) override;
};

#endif

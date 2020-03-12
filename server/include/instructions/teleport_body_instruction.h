#ifndef __TELEPORT_BODY_INSTRUCTION_H__
#define __TELEPORT_BODY_INSTRUCTION_H__

#include "instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"

class Body;

class TeleportBodyInstruction: public Instruction {
private:
    Body *body;
    b2Vec2 v;
    b2Vec2 pos;
    float angle;

public:
    /* Instancia una instruccion de teletransportacion que modifica la
     * velocidad v, posicion pos y angulo angle de body */
    TeleportBodyInstruction(Body *body, b2Vec2 v, b2Vec2 pos, float angle);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif

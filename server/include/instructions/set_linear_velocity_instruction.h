#ifndef __SET_LINEAR_VELOCITY_INSTRUCTION_H__
#define __SET_LINEAR_VELOCITY_INSTRUCTION_H__

#include "instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"

class Body;

class SetLinearVelocityInstruction: public Instruction {
private:
    Body *body;
    b2Vec2 v;

public:
    /* Instancia una instruccion que asigna una nueva velocidad
     * a body */
    SetLinearVelocityInstruction(Body *body, b2Vec2 v);

    /* Ejecuta la instruccion */
    virtual void execute() override;
};

#endif

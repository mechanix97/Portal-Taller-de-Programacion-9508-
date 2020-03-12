#ifndef __TRANSFORM_BODY_INSTRUCTION_H__
#define __TRANSFORM_BODY_INSTRUCTION_H__

#include "instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"

class Body;

class TransformBodyInstruction: public Instruction {
private:
    Body *body;
    b2Vec2 pos;
    float angle;

public:
    TransformBodyInstruction(Body *body, b2Vec2 pos, float angle);
    virtual void execute() override;
};

#endif

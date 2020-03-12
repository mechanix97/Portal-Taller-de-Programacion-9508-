#ifndef __CREATE_BULLET_INSTRUCTION_H__
#define __CREATE_BULLET_INSTRUCTION_H__

#include "instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../include/instructions/instruction.h"
#include "../.././common/include/types.h"

class Body;
class World;

class CreateBulletInstruction: public Instruction {
private:
    World *world;
    b2Vec2 pos;
    DIRECTION direction;

public:
    CreateBulletInstruction(World *world, b2Vec2 pos, DIRECTION direction);
    virtual void execute() override;
};

#endif

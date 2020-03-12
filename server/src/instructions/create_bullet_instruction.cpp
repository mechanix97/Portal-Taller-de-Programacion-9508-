#include "../../include/instructions/create_bullet_instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../include/instructions/instruction.h"
#include "../.././common/include/types.h"
#include "../../include/world.h"
#include "../../include/bodies/bullet/bullet.h"


CreateBulletInstruction::CreateBulletInstruction(
    World *world, b2Vec2 pos, DIRECTION direction):
    world(world), pos(pos), direction(direction) {
}

void CreateBulletInstruction::execute() {
    Bullet *bullet = world->createBullet(pos.x, pos.y, direction);
    Update update = bullet->createUpdate(COMMAND::CREATE_COMMAND);
    world->addUpdate(update);
}

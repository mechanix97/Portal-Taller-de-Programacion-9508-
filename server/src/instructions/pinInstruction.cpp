#include "../../include/instructions/pinInstruction.h"

PinInstruction::PinInstruction(World* world,uint32_t id,int32_t param1,int32_t param2):
world(world),id(id),param1(param1),param2(param2){
}

PinInstruction::~PinInstruction(){}

void PinInstruction::execute(){
	this->world->createNewPin(this->id,this->param1,this->param2);
}

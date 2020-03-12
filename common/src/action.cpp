#include "../include/action.h"

Action::Action() {
}

Action::Action(uint32_t id,ACTION ac,int32_t param1,int32_t param2): 
id(id),action(ac), param1(param1), param2(param2){}

Action::~Action(){}

uint32_t Action::getId()const{
	return this->id;
}

ACTION Action::getAction() const{
	return this->action;
}

int32_t Action::getParam1() const{
	return this->param1;
}

int32_t Action::getParam2() const{
	return this->param2;
}

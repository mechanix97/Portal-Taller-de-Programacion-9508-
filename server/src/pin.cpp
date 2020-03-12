#include "../include/pin.h"

Pin::Pin(uint32_t id,int32_t x,int32_t y):
id(id),x(x),y(y),cont(PIN_TIME) {
}

Pin::Pin(uint32_t pin_id, int32_t x, int32_t y, uint32_t pin_time):
	id(pin_id), x(x), y(y), cont(pin_time) {
}

Pin::~Pin(){}

uint32_t Pin::getId() const{
	return this->id;
}

bool Pin::hasUpdate(){
	if(this->cont == PIN_TIME || this->cont == 0){
		return true;
	} else {
		-- this->cont;
		return false;
	}
}

Update Pin::getUpdate(){
	if( this-> cont == PIN_TIME) {
		-- this->cont;
		return Update(COMMAND::CREATE_COMMAND,ENTITY::PIN,this->id,
			STATUS::NONE_STATUS,this->x,this->y,0);
	} //this-> cont == 0
	return Update(COMMAND::DESTROY_COMMAND,ENTITY::PIN,this->id,
		STATUS::NONE_STATUS,0,0,0);

}

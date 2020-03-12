#include "../include/update.h"

Update::Update():
	command(COMMAND::NONE_COMMAND),
	idClass(ENTITY::NONE_ENTITY),
	idObject(0),
	status(STATUS::NONE_STATUS),
	posX(0),
	posY(0),
	direction(0),
	angle(0) {
}

Update::Update(
	COMMAND command,
	ENTITY entity,
	uint32_t id,
	STATUS status,
	int32_t posx,
	int32_t posy,
	int32_t dir,
	int32_t angle):
	command(command),
	idClass(entity),
	idObject(id),
	status(status),
	posX(posx),
	posY(posy),
	direction(dir),
	angle(angle) {
}

Update::Update(
	COMMAND command,
	ENTITY entity,
	uint32_t id,
	STATUS status,
	int32_t posx,
	int32_t posy,
	int32_t dir):
	command(command),
	idClass(entity),
	idObject(id),
	status(status),
	posX(posx),
	posY(posy),
	direction(dir),
	angle(0) {
	}


Update::~Update(){}

COMMAND Update::getCommand() const{
	return this->command;
}

ENTITY Update::getIdClass() const{
	return this->idClass;
}

uint32_t Update::getIdObject() const{
	return this->idObject;
}

STATUS Update::getStatus() const{
	return this->status;
}

int32_t Update::getPosX() const{
	return this->posX;
}

int32_t Update::getPosY() const{
	return this->posY;
}

int32_t Update::getDirection() const{
	return this->direction;
}

void Update::setCommand(COMMAND command) {
	this->command = command;
}

void Update::setEntity(ENTITY entity) {
	this->idClass = entity;
}

void Update::setBodyId(uint32_t body_id) {
	this->idObject = body_id;
}

void Update::setStatus(STATUS status) {
	this->status = status;
}

void Update::setPosX(int32_t posX) {
	this->posX = posX;
}

void Update::setPosY(int32_t posY) {
	this->posY = posY;
}

void Update::setDirection(int32_t direction) {
	this->direction = direction;
}

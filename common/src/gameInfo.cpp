#include "../include/gameInfo.h"

GameInfo::GameInfo(uint32_t id,const std::string& mapName, 
		uint32_t players, uint32_t capacity):
id(id),mapName(mapName),players(players),capacity(capacity){}

GameInfo::~GameInfo(){}

uint32_t GameInfo::getId() const{
	return this->id;
}

const std::string& GameInfo::getMapName() const{
	return this->mapName;
}

uint32_t GameInfo::getPlayers() const{
	return this->players;
}

uint32_t GameInfo::getCapacity() const{
	return this->capacity;
}

void GameInfo::setPlayers(uint32_t p){
	this->players = p;
}

void GameInfo::setCapacity(uint32_t c){
	this->capacity = c;
}

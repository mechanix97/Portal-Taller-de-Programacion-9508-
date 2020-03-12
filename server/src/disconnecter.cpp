#include "../include/disconnecter.h"
#include "../include/game.h"

Disconnecter::Disconnecter(Game* game) : running(true),game(game){}

Disconnecter::~Disconnecter(){}

void Disconnecter::run(){
	uint32_t id;
	while(this->running){
		id = this->playersId.wait_and_pop();
		if(this->running){
			this->game->deletePlayer(id);	
		}
		
	}
}

void Disconnecter::stop(){
	this->running = false;
	this->playersId.push(1);
}

void Disconnecter::disconnectPlayer(uint32_t id){
	this->playersId.push(id);
}
#include "../include/broadcaster.h"

Broadcaster::Broadcaster(ProtectedQueue<Update>* source):
running(true),source(source){}

Broadcaster::~Broadcaster(){}

void Broadcaster::addPlayer(ProtectedQueue<Update>* client,uint32_t id){
	this->clients[id]=client;
}

void Broadcaster::deletePlayer(uint32_t id){
	this->clients.erase(id);
}

void Broadcaster::run(){
	Update update;
	while(this->running){
		update = this->source->wait_and_pop();
		if(this->running){
			for(auto client : this->clients){
				client.second->push(update);
			}
		}
	}
}

void Broadcaster::stop(){
	this->running = false;
	this->source->push(Update());
}
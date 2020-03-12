#include "../include/updateSender.h"

UpdateSender::UpdateSender(Protocol& p,ProtectedQueue<Update>* updates) : running(true),protocol(p),
	updates(updates){}

UpdateSender::~UpdateSender(){}

void UpdateSender::run(){
	Update update;
	while(this->running){
		update = this->updates->wait_and_pop();
		if(this->running){
			this->protocol.sendUpdate(update);
		}					
	}
}

void UpdateSender::stop(){
	this->running = false;
	this->updates->push(Update());
}

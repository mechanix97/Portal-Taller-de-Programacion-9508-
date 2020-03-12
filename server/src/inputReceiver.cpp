#include "../include/inputReceiver.h"

InputReceiver::InputReceiver(Protocol& p) :
 running(true), protocol(p),disconnecter(nullptr){

}

InputReceiver::~InputReceiver(){}

void InputReceiver::run(){
	try{
		while(this->running){
			Action action= this->protocol.receiveAction();//bloqueante
			if(action.getAction() == ACTION::QUIT){
				this->disconnecter->disconnectPlayer(action.getId());
				this->running = false;
			} else {
				this->inputPtr->push(std::move(action));
			}
		}
	}catch(const ConnectionErrorException &e){

	}
}

void InputReceiver::stop(){
	this->running = false;
}

void InputReceiver::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputPtr = ptr;
}

void InputReceiver::setDisconnecterPtr(Disconnecter* d){
	this->disconnecter = d;
}
#include "../include/serverManager.h"

ServerManager::ServerManager(const char* address,const char * port){
	Socket skt;
	skt.connect(std::string(address),std::string(port));
	Protocol prt(std::move(skt));
	this->protocol = std::move(prt);
}

ServerManager::~ServerManager(){}

void ServerManager::sendAction(const Action ac) const{
	this->protocol.sendAction(ac);
}

void ServerManager::stop(){
	this->protocol.close();
}

Update ServerManager::receiveUpdate() const{
	return this->protocol.receiveUpdate();
}

uint32_t ServerManager::receiveQuad() const{
	return this->protocol.receiveQuad();	
}

GameInfo ServerManager::receiveGameInfo() const{
	return this->protocol.receiveGameInfo();	
}

void ServerManager::joinGame(uint32_t id) const{
	this->protocol.sendByte(1);
	this->protocol.sendQuad(id);
}

void ServerManager::createGame(const std::string& map) const{
	this->protocol.sendByte(0);
	this->protocol.sendLine(map);
}

void ServerManager::sendNoneCommand() const{
	this->protocol.sendByte(2);
}

std::string ServerManager::receiveLine() const{
	return this->protocol.receiveLine();
}

uint8_t ServerManager::receiveByte() const{
	return this->protocol.receiveByte();
}
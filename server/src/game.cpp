#include "../include/game.h"
uint32_t Game::number = 0;

Game::Game(const std::string& mapName) :finished(false), 
stage(mapName, &this->inputs,&this->updates),
broadcaster(&this->updates),disconnecter(this),gameInfo(this->number,mapName,0,0) {	
	if(this->stage.validateMap()){
		this->chellsIds = this->stage.getChellsIdList();		
		this->gameInfo.setCapacity(this->chellsIds.size());
		this->stage.start();
		this->broadcaster.start();
		this->disconnecter.start();
		++this->number;		
	} else {
		this->finished = true;
	}	
}

Game::~Game(){
	for(auto player : this->players){
		delete player.second;
	}
}

bool Game::isFinished(){
	if(!this->finished){
		this->finished = !this->stage.isRunning();
	}
	return this->finished;
}

void Game::addPlayer(Player* player){
	std::list<Update> ul = this->stage.getNewPlayerUpdates();
	uint32_t id = this->chellsIds.back();
	player->sendChellIdToClient(id);
	player->sendBackground(this->stage.getBackground());
	this->chellsIds.pop_back();
	player->setInputPtr(&this->inputs);
	for(Update u: ul){
		player->pushBackUpdate(u);
	}
	this->broadcaster.addPlayer(player->getUpdatesPtr(),id);
	player->start();
	this->players[id] = player;
}

const GameInfo& Game::getGameInfo(){
	this->refreshGameInfo();
	return this->gameInfo;
}

void Game::refreshGameInfo(){
	uint32_t playersAlive = 0;
	for(auto it : this->players){
		if(this->stage.isChellAlive(it.first)){
			++playersAlive;
		}
	} 
	this->gameInfo.setPlayers(playersAlive);
	this->gameInfo.setCapacity(playersAlive + this->chellsIds.size());
}

uint32_t Game::getId() const{
	return this->gameInfo.getId();
}

void Game::stop(){
	this->stage.stop();
	this->broadcaster.stop();
	this->disconnecter.stop();
	for(auto player : this->players){
		player.second->stop();
	}
	this->stage.join();
	this->broadcaster.join();
	this->disconnecter.join();
}

void Game::deletePlayer(uint32_t id){
	Player* player = this->players[id];
	player->stop();
	delete player;
	this->players.erase(id);	
	this->broadcaster.deletePlayer(id);
	if(this->stage.isChellAlive(id)){
		this->chellsIds.push_front(id);	
	}
}

Disconnecter* Game::getDisconnecterPtr(){
	return &this->disconnecter;
}

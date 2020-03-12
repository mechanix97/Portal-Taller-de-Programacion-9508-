#include "../include/stage.h"

Stage::Stage(
	const std::string& mapName,
	ProtectedQueue<Action>* inputs,
	ProtectedQueue<Update>* updates):
	running(true),
	inputs(inputs),
	updates(updates) {
	Serializer serializer;
	serializer.deserialize(
		&this->world,
		MAP_PATH + mapName,
		"../config/config.yaml");
}

Stage::~Stage() {
}

bool Stage::validateMap() {
	return this->world.isValid();
}

void Stage::run() {
	GameLoop *game_loop = this->world.getGameLoop();

	while(!game_loop->isFinished() && this->running){
		game_loop->executeExternalInput(inputs);
		for (int i = 0; i < FPS_FACTOR; i++) {
			game_loop->step();
		}
		game_loop->fillUpdates(updates);
		usleep(50000);
	}
}

void Stage::stop(){
	this->running = false;
}

bool Stage::isRunning(){
	GameLoop *game_loop = this->world.getGameLoop();
	return !game_loop->isFinished() && this->running;
}

std::list<uint32_t> Stage::getChellsIdList() const{
	return this->world.getChellsIdList();
}

std::list<Update> Stage::getNewPlayerUpdates() const {
	return this->world.getNewPlayerUpdates();
}

bool Stage::isChellAlive(uint32_t id) const{
	return this->world.isChellAlive(id);
}

std::string Stage::getBackground() const{
	return this->world.getWorldConfig().world_def.background_path;
}

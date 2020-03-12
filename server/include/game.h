#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include <string>
#include <map>

#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../common/include/socket.h"
#include "../../common/include/gameInfo.h"
#include "../include/player.h"
#include "../include/stage.h"
#include "../include/broadcaster.h"
#include "../include/disconnecter.h"

class Game{
private:
	static uint32_t number;
	bool finished;
	Stage stage;
	std::map<uint32_t,Player*> players;
	ProtectedQueue<Action> inputs;
	ProtectedQueue<Update> updates;
	std::list<uint32_t> chellsIds;
	Broadcaster broadcaster;
	Disconnecter disconnecter;
	GameInfo gameInfo;
public:
	explicit Game(const std::string& mapName); 
	~Game();
	void addPlayer(Player* player);
	const GameInfo& getGameInfo();
	uint32_t getId() const;
	void deletePlayer(uint32_t id);
	void stop();
	Disconnecter* getDisconnecterPtr();
	void refreshGameInfo();
	bool isFinished();
};

#endif

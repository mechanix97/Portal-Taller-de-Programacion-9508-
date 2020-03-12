#ifndef _PLAYER_LOGIN_H_
#define _PLAYER_LOGIN_H_

#include <map>
#include <list>
#include <string>

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/gameInfo.h"

#include "../include/game.h"
#include "../include/player.h"
#include "../include/disconnecter.h"

class PlayerLogin : public Thread{
private: 
	bool joinable;
	std::map<uint32_t,Game*>* games;
	Socket peer;
public:
	explicit PlayerLogin(std::map<uint32_t,Game*>* games,Socket peer);
	virtual void run() override;
	bool isJoinable();	
};

#endif

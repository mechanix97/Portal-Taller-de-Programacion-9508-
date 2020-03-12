#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include <iostream>
#include <list>
#include <string>

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/action.h"
#include "../../common/include/update.h"
#include "../../common/include/gameInfo.h"

class ServerManager{
private:
	Protocol protocol;
public:
	explicit ServerManager(const char* address,const char * port);
	~ServerManager();
	void stop();
	void sendAction(const Action ac) const;
	Update receiveUpdate() const;
	uint32_t receiveQuad() const;
	GameInfo receiveGameInfo() const;
	void joinGame(uint32_t id) const;
	void createGame(const std::string& map) const;
	void sendNoneCommand() const;
	std::string receiveLine() const;
	uint8_t receiveByte() const;
};

#endif

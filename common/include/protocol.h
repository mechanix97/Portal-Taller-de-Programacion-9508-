#ifndef _COMMON_PROTOCOL_H_
#define _COMMON_PROTOCOL_H_

#include <string>
#include <cstdint>

#include "socket.h"
#include "update.h"
#include "action.h"
#include "gameInfo.h"

class Protocol{
private:
	Socket socket;
public:
	Protocol();
	explicit Protocol(Socket&& socket);
	explicit Protocol(Protocol&&);
	~Protocol();
	void close();
	bool isConnected();
	Protocol& operator=(Protocol&& other);
	void sendByte(const uint8_t byte) const;
	void sendDoble(const uint16_t byte) const;
	void sendQuad(const uint32_t byte) const;
	void sendLine(const std::string& line) const;
	uint8_t receiveByte() const;
	uint16_t receiveDoble() const;
	uint32_t receiveQuad() const;
	std::string receiveLine() const;
	void sendAction(const Action action) const;
	Action receiveAction() const;
	void sendUpdate(const Update update) const;
	Update receiveUpdate() const;
	void sendGameInfo(const GameInfo& gi) const;
	GameInfo receiveGameInfo() const;
};

#endif

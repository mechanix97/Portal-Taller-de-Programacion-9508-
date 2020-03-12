#ifndef _DISCONNECTER_H_
#define _DISCONNECTER_H_

#include <cstdint>

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"

class Game;

class Disconnecter : public Thread{
private:
	bool running;
	Game* game;
	ProtectedQueue<uint32_t> playersId;
public:
	Disconnecter(Game* game);
	~Disconnecter();
	virtual void run() override;
    void stop();
    void disconnectPlayer(uint32_t id);
};

#endif

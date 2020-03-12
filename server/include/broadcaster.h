#ifndef _BROADCASTER_H_
#define _BROADCASTER_H_

#include <map>
#include <unistd.h>
#include <cstdint>

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"

class Broadcaster : public Thread{
private:
	bool running;
	ProtectedQueue<Update>* source;
	std::map<uint32_t,ProtectedQueue<Update>*> clients;
public:
	explicit Broadcaster(ProtectedQueue<Update>* source);
	~Broadcaster();
	void addPlayer(ProtectedQueue<Update>* client,uint32_t id);
	virtual void run() override;
    void stop();	
    void deletePlayer(uint32_t id);
};

#endif

#ifndef _INPUT_RECEIVER_H_
#define _INPUT_RECEIVER_H_

#include "../../common/include/thread.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../include/disconnecter.h"

class Game;

class InputReceiver : public Thread{
private: 
	bool running;
	Protocol& protocol;
	Disconnecter* disconnecter;
	ProtectedQueue<Action>* inputPtr;
public:
	explicit InputReceiver(Protocol& p);
	~InputReceiver();
    virtual void run() override;
    void stop();	
    void setInputPtr(ProtectedQueue<Action>* ptr);
    void setDisconnecterPtr(Disconnecter* d);
};

#endif

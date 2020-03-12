#ifndef _UPDATE_SENDER_H_
#define _UPDATE_SENDER_H_

#include "../../common/include/thread.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"

class UpdateSender : public Thread{
private: 
	bool running;
	Protocol& protocol;
	ProtectedQueue<Update>* updates;
public:
	explicit UpdateSender(Protocol& p,ProtectedQueue<Update>* updates);
	~UpdateSender();
    virtual void run() override;
    void stop();
};

#endif

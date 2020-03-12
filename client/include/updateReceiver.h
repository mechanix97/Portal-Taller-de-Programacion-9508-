#ifndef _UPDATE_RECEIVER_H_
#define _UPDATE_RECEIVER_H_

#include "../include/serverManager.h"
#include "../../common/include/thread.h"
#include "../../common/include/update.h"
#include "../../common/include/protected_queue.h"

class UpdateReceiver : public Thread{
private:	
	const ServerManager& serverManager;
	ProtectedQueue<Update>& updates;
	bool running;
public:
	explicit UpdateReceiver(const ServerManager& sm,ProtectedQueue<Update>& queue);
	~UpdateReceiver();
	virtual void run() override;
	void stop();	
};

#endif

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <cstdint>
#include <unistd.h>
#include <exception>
#include <list>
#include <QApplication>

#include "../include/serverManager.h"
#include "../include/inputManager.h"
#include "../include/updateReceiver.h"
#include "../include/gameView.h"
#include "../include/soundManager.h"
#include "../include/videoRecorder.h"
#include "../include/login.h"

#include "../../common/include/port.h"
#include "../../common/include/update.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/types.h"
#include "../../common/include/gameInfo.h"

class Client{
private:
	bool running;
	ServerManager serverManager;
	ProtectedQueue<Update> updates;
	SoundManager soundManager;
	VideoRecorder videoRecorder;
	UpdateReceiver updateReceiver;

public:
	Client(const char *port);
	~Client();
	void main();
	int login();
	void game();
};

#endif

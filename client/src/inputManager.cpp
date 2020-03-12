 #include "../include/inputManager.h"

InputManager::InputManager(const ServerManager& sm,GameView& v,VideoRecorder& vr,
    PauseView* pause)
: running(true),serverManager(sm),chellId(0),gameView(v),videoRecorder(vr),
pauseView(pause){
}

InputManager::~InputManager(){}


void InputManager::stop(){
    this->running = false;
    //pusheo un evento para destrabar la cola
    SDL_Event sdlevent;
    sdlevent.type = SDL_KEYDOWN;
    sdlevent.key.keysym.sym = SDLK_0;//este evento no hace nada
    SDL_PushEvent(&sdlevent);
}

bool InputManager::isRunning() const{
	return this->running;
}

void InputManager::run(){
	this->chellId = this->gameView.getChellId();
    SDL_Event event;
    while(this->running && SDL_WaitEvent(&event)){
    	if(this->gameView.isPaused()){
    		this->pauseMode(event);
    	} else {
    		this->gameMode(event);
    	}
	    if(event.type == SDL_QUIT){
	    	this->stop();
	    }
    }
}

void InputManager::pauseMode(const SDL_Event& event){
 	switch(event.type) {
		case SDL_KEYDOWN: {
			SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
        	switch (keyEvent.keysym.sym) {
				case SDLK_ESCAPE:
    				this->pauseView->back();
        			break;
                case SDLK_o:
                    if(this->videoRecorder.isRecording()){
                        this->videoRecorder.stopRecording();
                    } else {
                        this->videoRecorder.startRecording(this->gameView.getResX(),
                            this->gameView.getResY());
                    }
                    break;
        		default:
        			break;
        	}
        break;
        }
        case SDL_MOUSEBUTTONDOWN:{
            SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) event;
            int x, y;
            SDL_GetMouseState( &x, &y );
            switch(mouseEvent.button){
                case SDL_BUTTON_LEFT:
                    this->pauseView->mouseButtonDown(x,y);
                    if(this->pauseView->stoped()){
                        this->stop();
                    }
                    break;
                }
            }
        break;
    }
}

void InputManager::gameMode(const SDL_Event& event){
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
    SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) event;
    switch(event.type) {
        case SDL_KEYDOWN: {
                switch (keyEvent.keysym.sym) {
                    case SDLK_a:
						this->sendPressAction(
							this->keypad.getKey(KEY::LEFT_KEY),
							ACTION::RUN_LEFT);
                        break;
                    case SDLK_d:
						this->sendPressAction(
							this->keypad.getKey(KEY::RIGHT_KEY),
							ACTION::RUN_RIGHT);
                        break;
                    case SDLK_w:
						this->sendPressAction(
							this->keypad.getKey(KEY::UP_KEY),
							ACTION::JUMP);
                        break;
                    case SDLK_e:
                        this->sendPressAction(
                            this->keypad.getKey(KEY::GRAB_KEY),
                            ACTION::GRAB);
                        break;
                    case SDLK_b:
                    	this->serverManager.sendAction(Action(
                            this->chellId,ACTION::JIG,0,0));
                    	break;
                    case SDLK_r:
                        this->serverManager.sendAction(Action(
                            this->chellId,ACTION::RESET_PORTALS,0,0));
                        break;

                    //locales
                    case SDLK_ESCAPE:
                        this->gameView.pause();
                        break;
                    case SDLK_o:
                        if(this->videoRecorder.isRecording()){
                            this->videoRecorder.stopRecording();
                        } else{
                            this->videoRecorder.startRecording(this->gameView.getResX(),
                                this->gameView.getResY());
                        }
                        break;
            } // Fin KEY_DOWN
            break;
        }
        case SDL_KEYUP: {
                switch (keyEvent.keysym.sym) {
                    case SDLK_a:
                    	this->sendReleaseAction(
							this->keypad.getKey(KEY::LEFT_KEY),
							ACTION::STOP_LEFT);
                        break;
                    case SDLK_d:
						this->sendReleaseAction(
							this->keypad.getKey(KEY::RIGHT_KEY),
							ACTION::STOP_RIGHT);
                        break;
                    case SDLK_w:
						this->sendReleaseAction(
							this->keypad.getKey(KEY::UP_KEY),
							ACTION::STOP_JUMP);
                        break;
                    case SDLK_s:
                        break;
                    case SDLK_e:
                        this->sendReleaseAction(
                            this->keypad.getKey(KEY::GRAB_KEY),
                            ACTION::STOP_GRAB);
                        break;

                }
            break;
        } // Fin KEY_UP
        case SDL_MOUSEWHEEL:{
            if(event.wheel.y > 0){// scroll up
                this->gameView.zoomIn();
            }
            else if(event.wheel.y < 0){// scroll down
                this->gameView.zoomOut();
            }
            break;
        }// fin MOUSEWHEEL
        case SDL_MOUSEBUTTONDOWN:{
            int x, y;
            SDL_GetMouseState( &x, &y );
            x = this->gameView.pixelToCoordX(x);
            y = this->gameView.pixelToCoordY(y);
            switch(mouseEvent.button){
                case SDL_BUTTON_LEFT:
                    this->serverManager.sendAction(Action(this->chellId,ACTION::FIRE1,x,y));
                    break;
                case SDL_BUTTON_RIGHT:
                    this->serverManager.sendAction(Action(this->chellId,ACTION::FIRE2,x,y));
                    break;
                case SDL_BUTTON_MIDDLE:
                    this->serverManager.sendAction(Action(this->chellId,ACTION::PING,x,y));
                    break;
            }
            break;
        }// fin MOUSEBUTTONDOWN
    }
}


void InputManager::sendPressAction(Key *key, ACTION action) {
	if (!key->isBeingPressed()) {
		key->press();
		this->serverManager.sendAction(Action(this->chellId, action,0,0));
	}
}

void InputManager::sendReleaseAction(Key *key, ACTION action) {
	if (key->isBeingPressed()) {
		key->release();
		this->serverManager.sendAction(Action(this->chellId, action,0,0));
	}

}

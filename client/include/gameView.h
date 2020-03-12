#ifndef _GAME_VIEW_H_
#define _GAME_VIEW_H_

#include <cstdint>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <unistd.h>
#include <exception>
#include <map>
#include <list>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/entity.h"
#include "../include/entityFactory.h"
#include "../include/serverManager.h"
#include "../include/soundManager.h"
#include "../include/chell.h"
#include "../include/block.h"
#include "../include/textureManager.h"
#include "../include/background.h"
#include "../include/pauseView.h"
#include "../include/textWidget.h"

#include "../../common/include/port.h"
#include "../../common/include/update.h"
#include "../../common/include/types.h"

class GameView{
private:
	bool finished;
	int resx;
	int resy;	
	int32_t posx = 0;
	int32_t posy = 0;
	SdlWindow window;
	TextureManager textureManager;
	SoundManager& soundManager;
	std::map<uint32_t,Entity *> entities;
	std::map<uint32_t,Chell *> chells;
	Chell* myChell;
	uint32_t myChellId;
	float scale;
	bool paused;
	bool danceMode = false;
	bool fullscreenBool = false;
	Background background;
	SDL_Cursor* cursor;
	PauseView pauseView;
	std::vector<std::pair<int,int>> resolutions;
	uint32_t resolutionsIndex;
	TextWidget* endMesage = nullptr;
	TextWidget recordingDot;
public:
	explicit GameView(uint32_t x, uint32_t y,SoundManager& sm,
		const std::string backgroundFile);
	~GameView();
	void step();
	void render(bool recording);
	void updateHandler(Update update);
	void zoomIn();
	void zoomOut();
	uint32_t getChellId() const;
	void setChellId(uint32_t id);
	void updateResolution();
	void fullscreen();
    void windowed();
    bool isPaused() const;
    void pause();
    int32_t pixelToCoordX(int32_t x) const;
    int32_t pixelToCoordY(int32_t y) const;
    SDL_Renderer* getRenderer() const;
    uint32_t getResX() const;
    uint32_t getResY() const;
    PauseView* getPausePtr();
    bool isFullscreen();
    void nextRes();
    void prevRes();
    bool isFinished() const; 
private:
	uint8_t getRand() const;
	void getResolutionsIndex();
	void showLoseMesage();
	void showWinMesage();
};

#endif

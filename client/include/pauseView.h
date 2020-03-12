#ifndef _PAUSE_VIEW_H_
#define _PAUSE_VIEW_H_

#include <string>

#include "../include/SdlWindow.h"
#include "../include/SdlTexture.h"
#include "../include/textureManager.h"
#include "../include/Area.h"
#include "../include/textWidget.h"
#include "../include/soundManager.h"

class GameView;

enum PAUSE_STATUS: uint8_t {
	INIT,
	OPTIONS,
	SCREENOPT,
	SOUNDOPT,
	CONTROLOPT
};

class PauseView{
private:
	const TextureManager& textureManager;
	GameView& gameView;
	SdlTexture* blackTexture;
	SoundManager& soundManager;
	Area blackArea;
	TextWidget twPause;
	TextWidget twResume;
	TextWidget twOptions;
	TextWidget twExit;
	TextWidget twScreenOpt;
	TextWidget twControlOpt;
	TextWidget twSoundOpt;
	TextWidget twBack1;
	TextWidget twMusicVolume1;
	TextWidget twMusicVolume2;
	TextWidget twFxVolume1;
	TextWidget twFxVolume2;
	TextWidget twBack2;
	TextWidget twFull1;
	TextWidget twFull2;
	TextWidget twRes1;
	TextWidget twRes2;
	TextWidget twBack3;
	PAUSE_STATUS status = INIT;
	uint32_t resx = 0;
	uint32_t resy = 0;
	bool stop = false;
public:
	explicit PauseView(const TextureManager& textureManager,const SdlWindow& window,
		GameView& gv,SoundManager& sm);
	~PauseView();
	void render(uint32_t resx,uint32_t resy);
	void mouseButtonDown(uint32_t x,uint32_t y);
	void back();
	bool stoped();
};

#endif

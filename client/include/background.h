#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "../include/Area.h"
#include "../include/SdlTexture.h"
#include "../include/SdlException.h"

#define DEFAULT_PATH "../resources/textures/backgrounds/"
#define DEFAULT_BG "1.jpg"

class Background{
private:
	SdlTexture* backgroundTexture = nullptr;
	int resx;
	int resy;
	uint32_t widthRendered;
	uint32_t heightRendered;
	uint8_t r = 255;
	uint8_t g = 255;
	uint8_t b = 255;
public:
	explicit Background(const SdlWindow& window,const std::string& file);
	~Background();
	void render(int x, int y,int resx, int resy,float scale);
	void setColorMod(uint8_t r,uint8_t g,uint8_t b);
	void resetColorMod();
};

#endif

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Button : public Entity{
private:
	Area frameArea;
	STATUS status;
public:
	explicit Button(const TextureManager& tm,const STATUS st,int32_t x, int32_t y,
		uint32_t width, uint32_t height);
	~Button();
	void render(int cx,int cy,int resx,int resy,float scale) override;
	void update(const Update& update) override;
};

#endif

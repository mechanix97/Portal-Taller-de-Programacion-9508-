#ifndef _ROCK_H_
#define _ROCK_H_

#include <cstdlib>

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Rock : public Entity{
	SdlTexture* texturePtr;
	Area frameArea;
public:
	explicit Rock(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height);
	~Rock();
	void render(int cx,int cy,int resx,int resy,float scale) override;
	void update(const Update& update) override;	
};

#endif

#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Block : public Entity{
private:
	Area frameArea;
	ENTITY entity;
public:
	explicit Block(const TextureManager& tm,const ENTITY e,int32_t x, int32_t y,
		uint32_t width, uint32_t height);
	~Block();
	void setDirection(uint32_t dir);
	void render(int cx,int cy,int resx,int resy,float scale) override;
};

#endif

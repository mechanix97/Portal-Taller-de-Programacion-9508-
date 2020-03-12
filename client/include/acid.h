#ifndef _ACID_H_
#define _ACID_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Acid : public Entity{
private:
	Area frameArea;
	uint32_t frame;
public:
	explicit Acid(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height);
	~Acid();
	void step() override;
	void render(int cx,int cy,int resx,int resy,float scale) override;
};

#endif

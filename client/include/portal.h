#ifndef _PORTAL_H_
#define _PORTAL_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Portal : public Entity{
private:
	Area frameArea;
public:
	explicit Portal(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height, int32_t dir,ENTITY en);
	~Portal();
	void render(int cx,int cy,int resx,int resy,float scale) override;
};

#endif

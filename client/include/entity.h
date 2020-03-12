#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../../common/include/update.h"

#include "../include/SdlTexture.h"

class TextureManager;

class Entity {
protected:
	int32_t posx;
	int32_t posy;
	uint32_t width;
	uint32_t height;
	int32_t direction; //0 izquierda 1 derecha
	SdlTexture * texturePtr = nullptr;
	const TextureManager & textureManager;
	uint8_t r = 255;
	uint8_t g = 255;
	uint8_t b = 255;
public:
	Entity(int32_t x,int32_t y,uint32_t w,uint32_t h, int32_t d,const TextureManager &tm)
		: posx(x),posy(y),width(w),height(h),direction(d),textureManager(tm){}
	virtual ~Entity(){}
	virtual void step(){}
	virtual void render(int32_t chellPosX,int32_t chellPosY,int width,int height,
		float scale){}
	virtual void update(const Update&){}
	void setColorMod(uint8_t r,uint8_t g,uint8_t b){
		this->r = r;
		this->g = g;
		this->b = b;
		if(this->texturePtr != nullptr){
			this->texturePtr->setColorMod(this->r,this->g,this->b);
		}

	}
	void resetColorMod(){
		this->r = 255;
		this->g = 255;
		this->b = 255;
		if(this->texturePtr != nullptr){
			this->texturePtr->setColorMod(this->r,this->g,this->b);
		}
	}
};


#endif

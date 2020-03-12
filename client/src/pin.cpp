#include "../include/pin.h"

Pin::Pin(const TextureManager& tm,const SoundManager& sm,int32_t x, int32_t y,
		uint32_t width, uint32_t height):
Entity(x,y,width,height,direction,tm),
frameArea(0,0,251,337)
{
	sm.playPinSound();
	this->texturePtr = this->textureManager.getPinTexturePointer();
}

Pin::~Pin(){}

void Pin::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height)*scale + (2*resy)/3;	
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
}

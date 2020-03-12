#include "../include/cake.h"

Cake::Cake(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height): 
Entity(x,y,width,height,0,tm),
frameArea(0,0,256,256)
{
	this->texturePtr = this->textureManager.getCakeTexturePointer();
}

Cake::~Cake(){}

void Cake::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
}

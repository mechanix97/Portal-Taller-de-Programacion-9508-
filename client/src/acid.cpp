#include "../include/acid.h"

Acid::Acid(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height): 
Entity(x,y,width,height,0,tm),
frameArea(0,0,300,61), frame(0)
{
	this->texturePtr = this->textureManager.getAcidTexturePointer();
}

Acid::~Acid(){}

void Acid::step(){
	++this->frame;
	if(this->frame == 8){
		this->frame = 0;
	}
	this->frameArea = Area(301*this->frame,0,299,61);
}

void Acid::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
}

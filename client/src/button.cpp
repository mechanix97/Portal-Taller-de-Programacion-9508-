#include "../include/button.h"

Button::Button(const TextureManager& tm,const STATUS st,int32_t x, int32_t y,
		uint32_t width, uint32_t height) : 
Entity(x,y,width,height,0,tm),
frameArea(0,0,173,68),status(st){	
	this->texturePtr = this->textureManager.getButtonTexturePointer(this->status);
}

Button::~Button(){}

void Button::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
}

void Button::update(const Update& update){
	this->status = update.getStatus();
	this->texturePtr = this->textureManager.getButtonTexturePointer(this->status);
}

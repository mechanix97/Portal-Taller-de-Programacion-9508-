#include "../include/portal.h"
#include <iostream>

Portal::Portal(const TextureManager& tm,int32_t x, int32_t y,
	uint32_t width, uint32_t height, int32_t dir,ENTITY en):
Entity(x,y,width,height,dir,tm),frameArea(0,0,400,500){
	this->texturePtr = this->textureManager.getPortalTexturePointer(en);
}

Portal::~Portal(){}

void Portal::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	Area renderArea(a,b,this->width*scale,this->height*scale);
	this->texturePtr->
		  renderInAngle(this->frameArea, renderArea, this->direction);
}

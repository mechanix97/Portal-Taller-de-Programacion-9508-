#include "../include/laser.h"

Laser::Laser(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height,uint32_t direction):
Entity(x,y,width,height,direction,tm),
frameArea(0,109,228,10){
	this->texturePtr = this->textureManager.getLaserTexturePointer();
}

Laser::~Laser(){}

void Laser::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	Area renderArea(a,b,this->width*scale,this->height*scale);
	this->texturePtr->renderInAngle(this->frameArea, renderArea, this->direction);
	/*
	ANGLE angle = (ANGLE) this->direction;
	switch(angle){
		case ANGLE::ANGLE_000:
			this->texturePtr->renderInAngle(this->frameArea, renderArea, 0);
			break;
		case ANGLE::ANGLE_045:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea, 45);
			break;
		case ANGLE::ANGLE_090:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,90);
			break;
		case ANGLE::ANGLE_135:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,135);
			break;
		default:
			this->texturePtr->render(this->frameArea, renderArea);
			break;
	}*/
}

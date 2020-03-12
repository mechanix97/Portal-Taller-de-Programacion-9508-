#include "../include/bullet.h"

Bullet::Bullet(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height,int32_t direction):
Entity(x,y,width,height,direction,tm),
frameArea(0,0,103,59), frame(0){
	this->texturePtr = this->textureManager.getBulletTexturePointer();
}

Bullet::~Bullet(){}

void Bullet::step(){
	++this->frame;
	if(this->frame == 3){
		this->frame = 0;
		this->frameArea = Area(0,0,103,59);
	}else if(this->frame == 2){
		this->frameArea = Area(216,0,109,59);
	} else {
		this->frameArea = Area(104,0,111,59);
	}
}

void Bullet::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	Area renderArea(a,b,this->width*scale,this->height*scale);
	this->texturePtr->renderInAngle(this->frameArea, renderArea, this->direction);
}

void Bullet::update(const Update& update){
	this->posx = update.getPosX();
	this->posy = update.getPosY();
	this->direction = update.getDirection();
}

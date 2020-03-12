#include "../include/block.h"

Block::Block(const TextureManager& tm,const ENTITY e, int32_t x, int32_t y, 
	uint32_t width, uint32_t height) 
: Entity(x,y,width,height,0,tm),frameArea(0, 0, 192, 192),entity(e){
	this->texturePtr = this->textureManager.getBlockTexturePointer(this->entity);
}

Block::~Block(){}

void Block::setDirection(uint32_t dir){
	if(this->entity == ENTITY::STONE_BLOCK ||
	this->entity == ENTITY::METAL_BLOCK){
		return;
	}
	this->direction = dir;
}

void Block::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;
	Area renderArea(a,b,this->width*scale,this->height*scale);
	switch(this->direction){
		case 0:
			this->texturePtr->render(this->frameArea, renderArea);
			break;
		case 1:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,90);	
			break;
		case 2:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,180);
			break;
		case 3:
			this->texturePtr->
				renderInAngle(this->frameArea, renderArea,270);
			break;		
		default:
			this->texturePtr->render(this->frameArea, renderArea);
			break;
	}
}

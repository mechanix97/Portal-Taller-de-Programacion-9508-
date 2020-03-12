#include "../include/background.h"
#include <iostream>

Background::Background(const SdlWindow& window,const std::string& file){
	if(file == ""){
		this->backgroundTexture = new SdlTexture(std::string(DEFAULT_PATH)+
			std::string(DEFAULT_BG), window);
	} else {
		try{
			this->backgroundTexture = new SdlTexture(std::string(DEFAULT_PATH)+
				file, window);
		}catch(const SdlException& e){
			this->backgroundTexture = new SdlTexture(std::string(DEFAULT_PATH)+
				std::string(DEFAULT_BG), window);
		}
	}
	this->backgroundTexture->getSize(&this->resx,&this->resy);
	this->widthRendered = this->resx/4;
	this->heightRendered = this->resy/4;
}

Background::~Background(){}

void Background::render(int x, int y, int rx, int ry,float scale){
	Area renderArea(0,0,rx,ry);
	int32_t a = (this->resx/2) + x/10 - this->widthRendered/(2*scale);
	int32_t b= (this->resy/2) + y/10 - this->widthRendered/(2*scale);
	if(a < 0){
		a = 0;
	}
	if(a >  this->resx - this->widthRendered/scale ){
		a = this->resx - this->widthRendered/scale;
	}
    if(b < 0){
		b = 0;
	}
	if(b >  this->resy - this->heightRendered/scale ){
		b = this->resy - this->heightRendered/scale;
	}

    Area frameArea(a,b,	this->widthRendered/scale,this->heightRendered/scale);
	this->backgroundTexture->render(frameArea,renderArea);
}

void Background::setColorMod(uint8_t r,uint8_t g,uint8_t b){
	this->r = r;
	this->g = g;
	this->b = b;
	this->backgroundTexture->setColorMod(this->r,this->g,this->b);
}
void Background::resetColorMod(){
	this->r = 255;
	this->g = 255;
	this->b = 255;
	this->backgroundTexture->setColorMod(this->r,this->g,this->b);
}

#include "../include/gate.h"

Gate::Gate(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height,STATUS status):
Entity(x,y,width,height,0,tm),
frameArea(0,0,192,384), frame(0), status(status){
	switch(this->status){
		case STATUS::GATE_OPENED:
			this->opened();
			break;
		case STATUS::GATE_CLOSED:
			this->closed();
			break;
		case STATUS::GATE_OPENING:
			this->open();
			break;
		case STATUS::GATE_CLOSING:
			this->close();
			break;
		default:
			break;
	}
	this->texturePtr = this->textureManager.getGateTexturePointer(this->status);
}

Gate::~Gate(){}

void Gate::step(){
	(this->*actionPtr)();
}

void Gate::render(int cx,int cy,int resx,int resy,float scale){
	int a = (this->posx-cx)*scale - (this->width/2)*scale + resx/2 ;
	int b = -(this->posy-cy)*scale - (this->height/2)*scale + (2*resy)/3;	
	this->texturePtr->render(this->frameArea, Area(a,b,this->width*scale,this->height*scale));
}

void Gate::update(const Update& update){
	switch(update.getStatus()){
		case STATUS::GATE_OPENED:
			this->opened();
			break;
		case STATUS::GATE_CLOSED:
			this->closed();
			break;
		case STATUS::GATE_OPENING:
			this->open();
			break;
		case STATUS::GATE_CLOSING:
			this->close();
			break;
		default:
			break;
	}
}

void Gate::opened(){
	if(this->frame != 18){
		this->open();
	} else {
		this->status = STATUS::GATE_OPENED;
		this->actionPtr = &Gate::opened;
		this->texturePtr = this->textureManager.getGateTexturePointer(this->status);
		this->frameArea = Area(0,1,192,384);
	}
}

void Gate::closed(){
	if(this->frame != 0){
		this->close();
	}else {
		this->status = STATUS::GATE_CLOSED;
		this->actionPtr = &Gate::closed;
		this->texturePtr = this->textureManager.getGateTexturePointer(this->status);
		this->frameArea =  Area(0,0,192,384);	
	}
	
}
void Gate::open(){
	if(this->frame == 18){
		this->actionPtr = &Gate::opened;
		return;
	}
	this->status = STATUS::GATE_OPENING;
	this->actionPtr = &Gate::open;
	this->texturePtr = this->textureManager.getGateTexturePointer(this->status);	
	this->frameArea =  this->textureManager.getGateFrameArea(this->frame);
	++this->frame;	
}

void Gate::close(){
	if(this->frame == 0){
		this->actionPtr = &Gate::closed;
		return;
	}
	this->status = STATUS::GATE_CLOSING;
	this->actionPtr = &Gate::close;
	this->texturePtr = this->textureManager.getGateTexturePointer(this->status);
	
	this->frameArea =  this->textureManager.getGateFrameArea(this->frame);
	--this->frame;
}

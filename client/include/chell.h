#ifndef _CHELL_H_
#define _CHELL_H_

#include <iostream>

#include "../include/textureManager.h"
#include "../include/soundManager.h"
#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Chell : public Entity{
private:
	void(Chell::* actionPtr)();
	Area frameArea;
	int frame;
	int framey;
	const SoundManager& soundManager;
	STATUS status;

public:	
	explicit Chell(const TextureManager& tm, const SoundManager& sm,
		int32_t posx,int32_t posy, uint32_t width,uint32_t height,uint32_t dir);
	~Chell();
	int32_t getPosX();
	int32_t getPosY();
	void renderCentered(int resx, int resy, float scale);	
	void step() override;
	void render(int resx,int resy,int width,int height,float scale) override;
	void update(const Update& update) override;	
	void idle();
	void idleAction();
	void jig();
	void jigAction();
	void run(int dir);
	void runAction();
	void stop(int dir);
	void stopAction();
	void turn(int dir);
	void turnAction();
	void jump();
	void jumpAction();
	void fall(int dir);
	void fallAction();
	void land();
	void landAction();
	void fire(int dir);
	void fireAction();
	void die();
	void dieAction();
	bool isDancing();
};

#endif

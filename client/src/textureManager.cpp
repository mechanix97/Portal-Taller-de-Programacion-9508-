#include "../include/textureManager.h"

TextureManager::TextureManager(){}

TextureManager::TextureManager(const SdlWindow& window):
blackTexture(BLACK_TEXTURE,window),
chellIdleTexture(CHELL_IDLE_TEXTURE,window), 
chellJigTexture(CHELL_JIG_TEXTURE,window), 
chellRunTexture(CHELL_RUNNING_TEXTURE,window), 
chellStopTexture(CHELL_STOPING_TEXTURE,window),
chellTurnTexture(CHELL_TURN_TEXTURE,window), 
chellJumpRiseTexture(CHELL_JUMP_RISE_TEXTURE,window),
chellJumpApexTexture(CHELL_JUMP_APEX_TEXTURE,window), 
chellJumpFallTexture(CHELL_JUMP_FALL_TEXTURE,window),
chellJumpLandTexture(CHELL_JUMP_LAND_TEXTURE,window), 
chellFireTexture(CHELL_FIRE_TEXTURE,window),
chellFireToIdleTexture(CHELL_FIRE_TO_IDLE_TEXTURE,window), 
chellDieTexture(CHELL_DIE_TEXTURE,window),
metalBlockTexture(METAL_BLOCK_TEXTURE,window),
metalTriagBlockTexture(METAL_TRIAG_BLOCK_TEXTURE,window),
stoneBlockTexture(STONE_BLOCK_TEXTURE,window),
launchBlockTexture(LAUNCH_BLOCK_TEXTURE,window),
receiverBlockTexture(RECEIVER_BLOCK_TEXTURE,window),
buttonOnTexture(BUTTON_ON_TEXTURE,window),
buttonOffTexture(BUTTON_OFF_TEXTURE,window),
rockTexture(ROCK_TEXTURE,window),
gateClosedTexture(GATE_CLOSED_TEXTURE,window),
gateOpenedTexture(GATE_OPENED_TEXTURE,window),
gateOpeningTexture(GATE_OPENING_TEXTURE,window),
acidTexture(ACID_TEXTURE,window),
bulletTexture(BULLET_TEXTURE,window),
laserTexture(LASER_TEXTURE,window),
pinTexture(PIN_TEXTURE,window),
cakeTexture(CAKE_TEXTURE,window),
portal1Texture(PORTAL1_TEXTURE,window),
portal2Texture(PORTAL2_TEXTURE,window)
	{}

TextureManager::~TextureManager(){}
	
SdlTexture * TextureManager::getBlackTexturePointer() const{
	return (SdlTexture*) &(this->blackTexture);
}

SdlTexture * TextureManager::getPortalTexturePointer(ENTITY en) const{
	switch(en){
		case ENTITY::PORTAL1:
			return (SdlTexture*) &(this->portal1Texture);
			break;
		case ENTITY::PORTAL2:
			return (SdlTexture*) &(this->portal2Texture);
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}

SdlTexture * TextureManager::getCakeTexturePointer() const{
	return (SdlTexture*) &(this->cakeTexture);
}

SdlTexture * TextureManager::getGateTexturePointer(STATUS st) const{
	switch(st){
		case STATUS::GATE_OPENED:
			return (SdlTexture*) &(this->gateOpenedTexture);
			break;
		case STATUS::GATE_OPENING:
			return (SdlTexture*) &(this->gateOpeningTexture);
			break;
		case STATUS::GATE_CLOSING:
			return (SdlTexture*) &(this->gateOpeningTexture);
			break;
		case STATUS::GATE_CLOSED:
			return (SdlTexture*) &(this->gateClosedTexture);
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}

SdlTexture * TextureManager::getPinTexturePointer() const{
	return (SdlTexture*) &(this->pinTexture);
}

SdlTexture * TextureManager::getLaserTexturePointer() const{
	return (SdlTexture*) &(this->laserTexture);
}

SdlTexture * TextureManager::getCrosshairTexturePointer() const{
	return (SdlTexture*) &(this->crosshairTexture);
}

Area TextureManager::getGateFrameArea(uint32_t frame) const{
	int a = frame % 10;
	int b = frame / 10;
	return Area(194*a,385*b+1,192,384);
}

SdlTexture * TextureManager::getRockTexturePointer() const{
	return (SdlTexture*) &(this->rockTexture);
}

SdlTexture * TextureManager::getBlockTexturePointer(const ENTITY e) const{
	switch(e){
		case STONE_BLOCK:
			return (SdlTexture*) &(this->stoneBlockTexture);
			break;
		case METAL_BLOCK:
			return (SdlTexture*) &(this->metalBlockTexture);
			break;
		case METAL_TRIAG_BLOCK:
			return (SdlTexture*) &(this->metalTriagBlockTexture);
			break;
		case LAUNCH_BLOCK:
			return (SdlTexture*) &(this->launchBlockTexture);
			break;
		case RECEIVER_BLOCK:
			return (SdlTexture*) &(this->receiverBlockTexture);
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}

SdlTexture * TextureManager::getButtonTexturePointer(const STATUS st) const{
	switch(st){
		case STATUS::BUTTON_ON:
			return (SdlTexture*) &(this->buttonOnTexture);
			break;
		case STATUS::BUTTON_OFF:
			return (SdlTexture*) &(this->buttonOffTexture);
			break;
		default:
			return nullptr;
			break;
	}	
	return nullptr;
}

SdlTexture * TextureManager::getAcidTexturePointer() const{
	return (SdlTexture*) &(this->acidTexture);
}

SdlTexture * TextureManager::getBulletTexturePointer() const{
	return (SdlTexture*) &(this->bulletTexture);
}

SdlTexture * TextureManager::getChellTexturePointer(const STATUS st) const{
	switch(st){
		case STATUS::CHELL_IDLE:
			return (SdlTexture*) &(this->chellIdleTexture);
			break;
		case STATUS::CHELL_RUNNING:
			return (SdlTexture*) &(this->chellRunTexture);
			break;
		case STATUS::CHELL_TURNING:
			return (SdlTexture*) &(this->chellTurnTexture);
			break;
		case STATUS::CHELL_STOPING:
			return (SdlTexture*) &(this->chellStopTexture);
			break;
		case STATUS::CHELL_JUMPING:
			return (SdlTexture*) &(this->chellJumpRiseTexture);
			break;
		case STATUS::CHELL_JUMPING_APEX:
			return (SdlTexture*) &(this->chellJumpApexTexture);
			break;
		case STATUS::CHELL_FALLING:
			return (SdlTexture*) &(this->chellJumpFallTexture);
			break;
		case STATUS::CHELL_LANDING:
			return (SdlTexture*) &(this->chellJumpLandTexture);
			break;
		case STATUS::CHELL_FIRE:	
			return (SdlTexture*) &(this->chellFireTexture);
			break;
		case STATUS::CHELL_JIGING:
			return (SdlTexture*) &(this->chellJigTexture);
			break;
		case STATUS::CHELL_FIRE_TO_IDLE:
			return (SdlTexture*) &(this->chellFireToIdleTexture);
			break;
		case STATUS::CHELL_DIE:
			return (SdlTexture*) &(this->chellDieTexture);
			break;
		default:
			return nullptr;
			break;
	}
	return nullptr;
}

Area TextureManager::getChellFrameArea(const STATUS st, int frame) const{
	int a;
	int b;
	switch(st){
		case STATUS::CHELL_IDLE:
			return Area(105*frame, 0, 104, 215);
			break;
		case STATUS::CHELL_RUNNING:
			a =	frame % 8;
			b = frame / 8;
			return Area(195*a, (205*b)+1, 194, 204);
			break;
		case STATUS::CHELL_TURNING:			
			return Area(193*frame+6, 1, 185, 200);
			break;
		case STATUS::CHELL_STOPING:
			a = frame % 10;
			b = frame / 10;
			return Area(166*a, (216*b)+1, 165, 215);
			break;
		case STATUS::CHELL_JUMPING:
			return Area(144*frame+1, 0, 143, 227);
			break;
		case STATUS::CHELL_JUMPING_APEX:
			return  Area(0, 0, 137, 207);
			break;
		case STATUS::CHELL_FALLING:
			return Area(157*frame, 0, 156, 217);
			break;
		case STATUS::CHELL_LANDING:
			return Area(231*frame+80, 2, 150, 196);
			break;
		case STATUS::CHELL_FIRE:	
			return Area(171*frame, 0, 170, 212);
			break;
		case STATUS::CHELL_JIGING:
			a = frame % 9;
			b = frame / 9;
			return Area(169*a, 244*b, 168, 243);
			break;
		case STATUS::CHELL_FIRE_TO_IDLE:
			return Area(144*frame, 0, 143, 212);
		case STATUS::CHELL_DIE:
			a = frame % 9;
			b = frame / 9;
			return Area(176*a, 262*b, 175, 261); 
		default:			
			break;
	}
	return Area(0,0,0,0);	
}


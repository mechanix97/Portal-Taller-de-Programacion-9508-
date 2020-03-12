#ifndef _ENTITY_FACTORY_H_
#define _ENTITY_FACTORY_H_

#include "../../common/include/update.h"

#include "../include/entity.h"
#include "../include/textureManager.h"
#include "../include/soundManager.h"
#include "../include/SdlWindow.h"
#include "../include/chell.h"
#include "../include/block.h"
#include "../include/button.h"
#include "../include/rock.h"
#include "../include/gate.h"
#include "../include/acid.h"
#include "../include/bullet.h"
#include "../include/laser.h"
#include "../include/pin.h"
#include "../include/cake.h"
#include "../include/portal.h"

class EntityFactory{
public:
	EntityFactory();
	~EntityFactory();
	Entity* create(const Update& up, const TextureManager& tm, const SoundManager& sm);
};

#endif

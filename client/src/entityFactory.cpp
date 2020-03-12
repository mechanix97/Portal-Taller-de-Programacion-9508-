#include "../include/entityFactory.h"

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::create(const Update& update, const TextureManager& tm, const SoundManager& sm){
	Block* ptr;
	switch(update.getIdClass()){
		case ENTITY::CHELL:
			return new Chell(tm,sm,update.getPosX(),update.getPosY(),100,200,update.getDirection());
			break;
		case ENTITY::STONE_BLOCK:
			return new Block(tm,STONE_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;
		case ENTITY::METAL_BLOCK:
			return new Block(tm,METAL_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;	
		case ENTITY::METAL_TRIAG_BLOCK:
			ptr = new Block(tm,METAL_TRIAG_BLOCK,update.getPosX(),update.getPosY(),200,200);
			ptr->setDirection(update.getDirection());
			return (Entity *) ptr;
			break;
		case ENTITY::LAUNCH_BLOCK:
			ptr = new Block(tm,LAUNCH_BLOCK,update.getPosX(),update.getPosY(),200,200);
			ptr->setDirection(update.getDirection());
			return (Entity *) ptr;
			break;
		case ENTITY::RECEIVER_BLOCK:
			return new Block(tm,RECEIVER_BLOCK,update.getPosX(),update.getPosY(),200,200);
			break;
		case ENTITY::ROCK:
			return new Rock(tm,update.getPosX(),update.getPosY(),100,100);
			break;
		case ENTITY::BUTTON:
			return new Button(tm,update.getStatus(),update.getPosX(),update.getPosY(),200,50);	
			break;
		case ENTITY::GATE:
			return new Gate(tm,update.getPosX(),update.getPosY(),200,400,update.getStatus());
			break;
		case ENTITY::ACID:
			return new Acid(tm,update.getPosX(),update.getPosY(),200,60);
			break;
		case ENTITY::BULLET:
			return new Bullet(tm,update.getPosX(),update.getPosY(),100,60,update.getDirection()); 
			break;
		case ENTITY::LASER:
			return new Laser(tm,update.getPosX(),update.getPosY(),200,10,update.getDirection()); 
			break;
		case ENTITY::PIN:
			return new Pin(tm,sm,update.getPosX(),update.getPosY(),50,50); 
			break;
		case ENTITY::CAKE:
			return new Cake(tm,update.getPosX(),update.getPosY(),100,100); 
			break;
		case ENTITY::PORTAL1:
			return new Portal(tm,update.getPosX(),update.getPosY(),220,30,update.getDirection(),
				ENTITY::PORTAL1);
			break;
		case ENTITY::PORTAL2:
			return new Portal(tm,update.getPosX(),update.getPosY(),220,30,update.getDirection(),
				ENTITY::PORTAL2);
			break;
		case ENTITY::NONE_ENTITY:
			return nullptr;
			break;
		default:			
			return nullptr;
			break;
	}
	return nullptr;
}

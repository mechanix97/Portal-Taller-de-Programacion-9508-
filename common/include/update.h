#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <cstdint>
#include "../include/types.h"

#define ZOOM_FACTOR 100

class Update{
private:
	COMMAND command;
	ENTITY idClass;
	uint32_t idObject;
	STATUS status;
	int32_t posX;
	int32_t posY;
	int32_t direction;
	int32_t angle;

public:
	Update();

	Update(
	   COMMAND command,
	   ENTITY entity,
	   uint32_t body_id,
	   STATUS status,
	   int32_t posx,
	   int32_t posy,
	   int32_t dir,
   	   int32_t angle);

	explicit Update(
		COMMAND command,
		ENTITY entity,
		uint32_t body_id,
		STATUS status,
		int32_t posx,
		int32_t posy,
		int32_t dir);

	~Update();

	COMMAND getCommand() const;
	ENTITY getIdClass() const;
	uint32_t getIdObject() const;
	STATUS getStatus() const;
	int32_t getPosX() const;
	int32_t getPosY() const;
	int32_t getDirection() const;

	void setCommand(COMMAND command);
	void setEntity(ENTITY entity);
	void setBodyId(uint32_t body_id);
	void setStatus(STATUS status);
	void setPosX(int32_t posX);
	void setPosY(int32_t posY);
	void setDirection(int32_t direction);
};

#endif

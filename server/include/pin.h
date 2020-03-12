#ifndef _PIN_H_
#define _PIN_H_

#include "../.././common/include/update.h"
#define PIN_TIME 60


class Pin {
	uint32_t id;
	int32_t x;
	int32_t y;
	uint32_t cont;

public:
	Pin(uint32_t pin_id, int32_t x, int32_t y, uint32_t pin_time);
	explicit Pin(uint32_t id,int32_t x,int32_t y);
	~Pin();
	bool hasUpdate();
	uint32_t getId() const;
	Update getUpdate();
};

#endif

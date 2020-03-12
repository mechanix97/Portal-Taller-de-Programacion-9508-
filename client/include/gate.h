#ifndef _GATE_H_
#define _GATE_H_

#include "../include/SdlTexture.h"
#include "../include/Area.h"
#include "../include/textureManager.h"
#include "../include/entity.h"
#include "../../common/include/types.h"
#include "../../common/include/update.h"

class Gate : public Entity{
private:
	Area frameArea;
	uint32_t frame;
	STATUS status;
	void(Gate::* actionPtr)();
public:
	explicit Gate(const TextureManager& tm,int32_t x, int32_t y,
		uint32_t width, uint32_t height, STATUS status);
	~Gate();
	void step() override;
	void render(int cx,int cy,int resx,int resy,float scale) override;
	void update(const Update& update) override;
	void opened();
	void closed();
	void open();
	void close();
};

#endif

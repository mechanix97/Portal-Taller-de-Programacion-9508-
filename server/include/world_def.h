#ifndef __WORLD_DEF_H__
#define __WORLD_DEF_H__

#include <string>

class WorldDef {
public:
    float gravity_x = 0;
    float gravity_y = -9.8;
    std::string background_path;
};

#endif

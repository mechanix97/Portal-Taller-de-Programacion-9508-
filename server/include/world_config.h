#ifndef __WORLD_CONFIG_H__
#define __WORLD_CONFIG_H__

#include "bodies/block/block_def.h"
#include "bodies/bullet/bullet_def.h"
#include "bodies/button/button_def.h"
#include "bodies/chell/chell_def.h"
#include "bodies/launcher/launcher_def.h"
#include "pin_def.h"
#include "stage_def.h"
#include "world_def.h"
#include "game_loop_def.h"

class WorldConfig {
public:
    BlockDef block_def;
    BulletDef bullet_def;
    ButtonDef button_def;
    ChellDef chell_def;
    LauncherDef launcher_def;
    PinDef pin_def;
    StageDef stage_def;
    WorldDef world_def;
    GameLoopDef game_loop_def;
};

#endif

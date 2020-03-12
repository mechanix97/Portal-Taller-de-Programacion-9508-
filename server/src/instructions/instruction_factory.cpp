#include "../../include/instructions/instruction_factory.h"

#include "../../include/world.h"
#include "../.././common/include/action.h"
#include "../../include/instructions/default_instruction.h"
#include "../../include/instructions/run_left_instruction.h"
#include "../../include/instructions/stop_left_instruction.h"
#include "../../include/instructions/run_right_instruction.h"
#include "../../include/instructions/stop_right_instruction.h"
#include "../../include/instructions/jump_instruction.h"
#include "../../include/instructions/fire_portal_instruction.h"
#include "../../include/instructions/pinInstruction.h"
#include "../../include/instructions/press_grab_instruction.h"
#include "../../include/instructions/stop_grab_instruction.h"
#include "../../include/instructions/jig_instruction.h"
#include "../../include/instructions/reset_portals_instruction.h"
#include "../../include/bodies/chell/chell.h"
#include "../../include/bodies/portal/portal.h"
#include <map>
#include <cstdint>
#include <iostream>

Instruction *InstructionFactory::createInstruction(
    const Action &action,
    std::map<uint32_t, Chell *> &chells,
    World* world) const {
    Instruction *instruction;
    ACTION act;
    Chell *chell;

    uint32_t chell_id = action.getId();
    if (chells.count(chell_id) == 0) {
        act = ACTION::NONE_ACTION;
        chell = nullptr;
    } else {
        act = action.getAction();
        chell = chells[chell_id];
    }

    switch (act) {
        case ACTION::RUN_LEFT:
            instruction = new RunLeftInstruction(chell);
            break;
        case ACTION::STOP_LEFT:
            instruction = new StopLeftInstruction(chell);
            break;
        case ACTION::RUN_RIGHT:
            instruction = new RunRightInstruction(chell);
            break;
        case ACTION::STOP_RIGHT:
            instruction = new StopRightInstruction(chell);
            break;
        case ACTION::JUMP:
            instruction = new JumpInstruction(chell);
            break;
        case ACTION::PING:
            instruction = new PinInstruction(world,action.getId(),action.getParam1(),action.getParam2());
            break;
        case ACTION::FIRE1:
            instruction = new FirePortalInstruction(
                chell, NPORTAL1, action.getParam1(), action.getParam2());
            break;
        case ACTION::FIRE2:
            instruction = new FirePortalInstruction(
                chell, NPORTAL2, action.getParam1(), action.getParam2());
            break;
        case ACTION::GRAB:
            instruction = new PressGrabInstruction(chell);
            break;
        case ACTION::STOP_GRAB:
            instruction = new StopGrabInstruction(chell);
            break;
        case ACTION::NONE_ACTION:
            instruction = new DefaultInstruction();
            break;
        case ACTION::JIG:
            instruction = new JigInstruction(chell);
            break;
        case ACTION::RESET_PORTALS:
            instruction = new ResetPortalsInstruction(chell);
            break;
        default:
            instruction = new DefaultInstruction();
            break;
    }
    return instruction;
}

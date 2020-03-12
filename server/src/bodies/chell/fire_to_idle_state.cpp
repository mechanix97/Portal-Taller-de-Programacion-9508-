#include "../../../include/bodies/chell/fire_to_idle_state.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

FireToIdleState::FireToIdleState(Chell *chell):
    ChellState(chell, STATUS::CHELL_FIRE_TO_IDLE) {
}

void FireToIdleState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        this->chell->changeStateToIdle();
    }
}

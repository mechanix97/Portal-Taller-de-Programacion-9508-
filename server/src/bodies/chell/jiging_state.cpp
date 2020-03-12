#include "../../../include/bodies/chell/jiging_state.h"
#include "../../../include/bodies/chell/chell.h"

JigingState::JigingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_JIGING) {
}

void JigingState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        this->resetStepCount();
        this->chell->changeStateToIdle();
    }
}

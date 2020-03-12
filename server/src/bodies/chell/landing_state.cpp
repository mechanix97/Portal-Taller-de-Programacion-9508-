#include "../../../include/bodies/chell/landing_state.h"
#include "../../../include/bodies/chell/chell.h"

LandingState::LandingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_LANDING) {
}

void LandingState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        this->chell->changeStateToIdle();
        this->resetStepCount();
    }
}

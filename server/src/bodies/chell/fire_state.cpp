#include "../../../include/bodies/chell/fire_state.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

FireState::FireState(Chell *chell):
    ChellState(chell, STATUS::CHELL_FIRE) {
}

void FireState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        this->chell->changeStateToFireToIdle();
    }
}

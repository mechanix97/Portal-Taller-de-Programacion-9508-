#include "../../../include/bodies/chell/turning_state.h"
#include "../../../include/bodies/chell/chell.h"

TurningState::TurningState(Chell *chell):
    ChellState(chell, STATUS::CHELL_TURNING) {
}

void TurningState::applyStateAction() {
    this->step_count++;
    if (this->chell->getLinearVelocity().y < this->FALLING_VELOCITY) {
        this->resetStepCount();
        this->chell->changeStateToFalling();
    } else if (this->step_count > this->MAX_STEPS) {
        this->resetStepCount();
        this->chell->changeStateToRunning();
    }
}

void TurningState::pressUp() {
    this->chell->applyLinearImpulseToUp();
    this->chell->changeStateToJumping();
}

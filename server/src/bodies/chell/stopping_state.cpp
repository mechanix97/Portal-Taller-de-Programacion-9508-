#include "../../../include/bodies/chell/stopping_state.h"
#include "../../../include/bodies/chell/chell.h"

StoppingState::StoppingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_STOPING) {
}

void StoppingState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        this->resetStepCount();
        this->chell->changeStateToIdle();
    }
}

void StoppingState::pressLeft() {
    if (this->chell->isFacingLeft()) {
        this->chell->changeStateToRunning();
    } else {
        this->chell->faceLeft();
        this->chell->changeStateToTurning();
    }
}

void StoppingState::pressRight() {
    if (this->chell->isFacingRight()) {
        this->chell->changeStateToRunning();
    } else {
        this->chell->faceRight();
        this->chell->changeStateToTurning();
    }
}

void StoppingState::pressUp() {
    this->chell->applyLinearImpulseToUp();
    this->chell->changeStateToJumping();
}

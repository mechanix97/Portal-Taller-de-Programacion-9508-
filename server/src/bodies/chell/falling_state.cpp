#include "../../../include/bodies/chell/falling_state.h"
#include "../../../include/bodies/chell/chell.h"

FallingState::FallingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_FALLING) {
}

void FallingState::land() {
    this->chell->changeStateToLanding();
}

void FallingState::pressLeft() {
    this->chell->faceLeft();
    this->chell->applyLinearImpulseToLeft();
}

void FallingState::releaseLeft() {
    this->chell->stopLeftMovement();
}

void FallingState::pressRight() {
    this->chell->faceRight();
    this->chell->applyLinearImpulseToRight();
}

void FallingState::releaseRight() {
    this->chell->stopRightMovement();
}

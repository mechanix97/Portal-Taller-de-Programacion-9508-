#include "../../../include/bodies/chell/jumping_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

JumpingState::JumpingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_JUMPING) {
}

void JumpingState::pressLeft() {
    this->chell->faceLeft();
    this->chell->applyLinearImpulseToLeft();
}

void JumpingState::releaseLeft() {
    this->chell->stopLeftMovement();
}

void JumpingState::pressRight() {
    this->chell->faceRight();
    this->chell->applyLinearImpulseToRight();
}

void JumpingState::releaseRight() {
    this->chell->stopRightMovement();
}

void JumpingState::land() {
    this->chell->changeStateToIdle();
}

void JumpingState::applyStateAction(){
    if (this->chell->getLinearVelocity().y < 0) {
        this->chell->changeStateToFalling();
    } else if (!this->chell->hasReachedMaxHorizontalSpeed()) {
        if (this->chell->getKeypad()->isBeingPressed(KEY::RIGHT_KEY)) {
            this->chell->applyLinearImpulseToRight();
        } else if (this->chell->getKeypad()->isBeingPressed(KEY::LEFT_KEY)){
            this->chell->applyLinearImpulseToLeft();
        }
    }
}

#include "../../../include/bodies/chell/chell_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/instructions/desactivate_body_instruction.h"


ChellState::ChellState(Chell *chell, STATUS status):
    chell(chell),
    status(status),
    step_count(0) {
}

void ChellState::resetStepCount() {
    this->step_count = 0;
}

void ChellState::handleBeginContactWith(Bullet *bullet) {
    this->chell->putToSleep();
    this->chell->changeStateToDead();
    World *world = this->chell->getWorld();
    world->addUpdate(this->chell->createUpdate(COMMAND::UPDATE_COMMAND));
    world->addInstruction(new DesactivateBodyInstruction(this->chell));
}


STATUS ChellState::getStatus() const {
    return this->status;
}

void ChellState::pressLeft() {

}

void ChellState::releaseLeft() {

}

void ChellState::pressRight() {

}

void ChellState::releaseRight() {

}

void ChellState::pressUp() {

}

void ChellState::releaseUp() {
}

void ChellState::land(){
}

void ChellState::firePortalOne(float x, float y) {
    this->chell->getPortalGun()->firePortalOne(x, y);
    this->chell->changeStateToFire();
}

void ChellState::firePortalTwo(float x, float y) {
    this->chell->getPortalGun()->firePortalTwo(x, y);
    this->chell->changeStateToFire();
}

void ChellState::jig() {
    this->chell->changeStateToJiging();
}

void ChellState::applyStateAction() {
}

void ChellState::startTimer() {
    this->timer.start();
}

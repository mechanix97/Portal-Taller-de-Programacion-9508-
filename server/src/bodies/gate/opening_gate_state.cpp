#include "../../../include/bodies/gate/opening_gate_state.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/gate/gate_state.h"

#include <iostream>

OpeningGateState::OpeningGateState(Gate *gate):
    GateState(gate, STATUS::GATE_OPENING) {
}

void OpeningGateState::tryChangeState() {
    if (!this->gate->conditionIsMeet()) {
        this->gate->wakeUp();
        this->gate->changeStateToClosing();
    }
}

void OpeningGateState::applyStateAction() {
    if (this->gate->isOnMinSize()) {
        this->gate->changeStateToOpen();
    } else {
        this->gate->shrink();
    }
}

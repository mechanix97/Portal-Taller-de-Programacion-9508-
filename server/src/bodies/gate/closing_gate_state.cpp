#include "../../../include/bodies/gate/closed_gate_state.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/gate/gate_state.h"

ClosingGateState::ClosingGateState(Gate *gate):
    GateState(gate, STATUS::GATE_CLOSING) {
}

void ClosingGateState::tryChangeState() {
    if (this->gate->conditionIsMeet()) {
        this->gate->wakeUp();
        this->gate->changeStateToOpening();
    }
}

void ClosingGateState::applyStateAction() {
    if (this->gate->isOnMaxSize()) {
        this->gate->changeStateToClosed();
    } else {
        this->gate->grow();
    }
}

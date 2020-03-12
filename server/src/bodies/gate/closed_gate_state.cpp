#include "../../../include/bodies/gate/closed_gate_state.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/gate/gate_state.h"

ClosedGateState::ClosedGateState(Gate *gate):
    GateState(gate, STATUS::GATE_CLOSED) {
}

STATUS ClosedGateState::getStatus() {
    this->gate->putToSleep();
    return STATUS::GATE_CLOSED;
}


void ClosedGateState::tryChangeState() {
    if (this->gate->conditionIsMeet()) {
        this->gate->wakeUp();
        this->gate->changeStateToOpening();
    }
}

void ClosedGateState::applyStateAction() {
}

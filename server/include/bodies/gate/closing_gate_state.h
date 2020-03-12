#ifndef __CLOSING_GATE_STATE_H__
#define __CLOSING_GATE_STATE_H__

#include "gate_state.h"

class Gate;

class ClosingGateState: public GateState {
public:
    ClosingGateState(Gate *gate);
    virtual void tryChangeState();
    virtual void applyStateAction() override;
};

#endif

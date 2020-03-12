#ifndef __OPENING_GATE_STATE_H__
#define __OPENING_GATE_STATE_H__

#include "gate_state.h"

class Gate;

class OpeningGateState: public GateState {
public:
    OpeningGateState(Gate *gate);
    virtual void tryChangeState();
    virtual void applyStateAction() override;
};

#endif

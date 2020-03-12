#ifndef __OPEN_GATE_STATE_H__
#define __OPEN_GATE_STATE_H__

#include "gate_state.h"

class Gate;

class OpenGateState: public GateState {
public:
    OpenGateState(Gate *gate);
    virtual STATUS getStatus() override;
    virtual void tryChangeState();
    virtual void applyStateAction() override;
};

#endif

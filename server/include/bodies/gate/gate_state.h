#ifndef __GATE_STATE_H__
#define __GATE_STATE_H__

#include "../../../../common/include/types.h"

class Gate;

class GateState {
protected:
    Gate *gate;
    const STATUS status;

public:
    GateState(Gate *gate, STATUS status);
    virtual ~GateState();
    virtual STATUS getStatus();
    virtual void applyStateAction();
    virtual void tryChangeState() = 0;
};

#endif

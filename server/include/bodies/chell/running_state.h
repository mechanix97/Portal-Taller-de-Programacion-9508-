#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "chell_state.h"

class Chell;

class RunningState: public ChellState {
private:
    const float FALLING_VELOCITY = -0.2;

public:
    RunningState(Chell *chell);
    virtual void pressLeft() override;
    virtual void releaseLeft() override;
    virtual void pressRight() override;
    virtual void releaseRight() override;
    virtual void pressUp() override;
    virtual void applyStateAction() override;
};

#endif

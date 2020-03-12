#ifndef __FALLING_STATE_H__
#define __FALLING_STATE_H__

#include "chell_state.h"

class Chell;

class FallingState: public ChellState {
public:
    FallingState(Chell *chell);
    virtual void land() override;
    virtual void pressLeft() override;
    virtual void releaseLeft() override;
    virtual void pressRight() override;
    virtual void releaseRight() override;
};

#endif

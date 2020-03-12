#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "chell_state.h"

class Chell;

class IdleState: public ChellState {
public:
    IdleState(Chell *chell);
    virtual void pressLeft() override;
    virtual void releaseLeft() override;
    virtual void pressRight() override;
    virtual void releaseRight() override;
    virtual void pressUp() override;
    virtual void applyStateAction() override;
};

#endif

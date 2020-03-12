#ifndef __FIRE_TO_IDLE_STATE_H__
#define __FIRE_TO_IDLE_STATE_H__

#include "chell_state.h"

class Chell;

class FireToIdleState: public ChellState {
private:
    unsigned int MAX_STEPS = 10;
public:
    FireToIdleState(Chell *chell);
    virtual void applyStateAction();
};

#endif

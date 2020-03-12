#ifndef __FIRE_STATE_H__
#define __FIRE_STATE_H__

#include "chell_state.h"

class Chell;

class FireState: public ChellState {
private:
    unsigned int MAX_STEPS = 10;

public:
    FireState(Chell *chell);
    virtual void applyStateAction();
};

#endif

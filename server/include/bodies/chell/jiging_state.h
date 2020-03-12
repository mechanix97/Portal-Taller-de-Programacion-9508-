#ifndef __JIGING_STATE_H__
#define __JIGING_STATE_H__

#include "chell_state.h"

class Chell;

class JigingState: public ChellState {
private:
    const unsigned int MAX_STEPS = 72 * FPS_FACTOR;

public:
    JigingState(Chell *chell);
    virtual void applyStateAction();
};


#endif

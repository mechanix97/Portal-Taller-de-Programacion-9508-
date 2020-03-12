#ifndef __LANDING_STATE_H__
#define __LANDING_STATE_H__

#include "chell_state.h"

class Chell;

class LandingState: public ChellState {
private:
    unsigned int MAX_STEPS = 2 * FPS_FACTOR;

public:
    LandingState(Chell *chell);
    virtual void applyStateAction() override;
};


#endif

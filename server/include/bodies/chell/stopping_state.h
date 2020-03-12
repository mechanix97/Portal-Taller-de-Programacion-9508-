#ifndef __STOPPING_STATE_H__
#define __STOPPING_STATE_H__

#include "chell_state.h"

class Chell;

class StoppingState: public ChellState {
private:
    const unsigned int MAX_STEPS = 12 * FPS_FACTOR;

public:
    StoppingState(Chell *chell);
    virtual void applyStateAction() override;
    virtual void pressLeft() override;
    virtual void pressRight() override;
    virtual void pressUp() override;



};

#endif

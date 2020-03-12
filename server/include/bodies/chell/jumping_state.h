#ifndef __JUMPING_STATE_H__
#define __JUMPING_STATE_H__

#include "chell_state.h"

class Chell;

class JumpingState: public ChellState {
public:
    JumpingState(Chell *chell);
    virtual void pressLeft() override;
    virtual void releaseLeft() override;
    virtual void pressRight() override;
    virtual void releaseRight() override;
    virtual void land() override;
    virtual void applyStateAction() override;
};

#endif

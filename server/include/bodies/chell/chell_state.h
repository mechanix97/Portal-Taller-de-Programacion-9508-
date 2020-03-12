#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

#include "../../../../common/include/timer.h"
#include "../../../../common/include/types.h"

class Chell;
class Bullet;

class ChellState {
protected:
    Chell *chell;
    STATUS status;
    unsigned int step_count;
    Timer timer;

public:
    /* Instancia un estado para chell */
    ChellState(Chell *chell, STATUS status);

    /* Reinicia el contador de steps */
    virtual void resetStepCount();

    /* Maneja el contacto con una bala */
    virtual void handleBeginContactWith(Bullet *bullet);

    /* Devuelve el estado */
    STATUS getStatus() const;

    /* Realiza una accion basada en la tecla izquierda */
    virtual void pressLeft();

    /* Realiza una accion basada en la tecla derecha */
    virtual void releaseLeft();

    /* Realiza una accion basada en la tecla derecha */
    virtual void pressRight();

    /* Realiza una accion tras soltar la tecla derecha */
    virtual void releaseRight();

    /* Realiza una accion tras presional la tecla de arriba */
    virtual void pressUp();

    /* Realiza una accion tras solatar la tecla de arriba */
    virtual void releaseUp();

    /* Aterriza a chell */
    virtual void land();

    /* Dispara el primer portal */
    virtual void firePortalOne(float x, float y);

    /* Dispara el segundo portal */
    virtual void firePortalTwo(float x, float y);

    /* Baila */
    virtual void jig();

    /* Aplica una accion sobre chell */
    virtual void applyStateAction();

    /* Inicia el contador del cronometro */
    void startTimer();
};

#endif

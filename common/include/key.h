#ifndef __KEY_H__
#define __KEY_H__

#include "timer.h"

class Key {
private:
    bool pressed;
    Timer timer;

public:
    /* Instancia una tecla */
    Key();

    /* Presiona una tecla */
    void press();

    /* Suelta una tecla */
    void release();

    /* Devuelve el tiempo que lleva presionada la tecla en milisegundos. */
    double elapsedTimeBeingPressed();

    /* Indica si esta siendo presionado */
    bool isBeingPressed();
};

#endif

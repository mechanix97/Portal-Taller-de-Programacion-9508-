#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>

class Timer {
private:
    bool started;
    std::chrono::time_point<std::chrono::high_resolution_clock> begin;

public:
    /* Instancia un timer sin iniciar */
    Timer();

    /* Inicia el cronometro */
    void start();

    /* Devuelve el tiempo pasado desde el inicio en milisegundos.
     * Pre: Se tuvo que haber iniciado el timer, en caso contrario
     *      devuelve -1. */
    double elapsedTimeInMiliSeconds();

    /* Detiene el timer */
    void stop();
};

#endif

#include "../include/timer.h"

Timer::Timer():
    started(false) {
}

void Timer::start() {
    if (!this->started) {
        this->begin = std::chrono::high_resolution_clock::now();
    }
}

double Timer::elapsedTimeInMiliSeconds() {
    if (this->started) {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> miliseconds = end - this->begin;
        return miliseconds.count();
    } else {
        return -1;
    }
}

void Timer::stop() {
    this->started = false;
}

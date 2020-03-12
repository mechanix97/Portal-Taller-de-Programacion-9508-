#include "../../common/include/key.h"

Key::Key():
    pressed(false) {
}


void Key::press() {
    if (!this->pressed) {
        this->pressed = true;
        this->timer.start();
    }
}

void Key::release() {
    this->pressed = false;
}

double Key::elapsedTimeBeingPressed() {
    return this->timer.elapsedTimeInMiliSeconds();
}

bool Key::isBeingPressed() {
    return this->pressed;
}

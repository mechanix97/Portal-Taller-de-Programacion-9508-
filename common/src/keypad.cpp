#include "../../common/include/keypad.h"
#include "../../common/include/key.h"

Keypad::Keypad() {
    keys[KEY::LEFT_KEY] = Key();
    keys[KEY::RIGHT_KEY] = Key();
    keys[KEY::UP_KEY] = Key();
    keys[KEY::DOWN_KEY] = Key();
    keys[KEY::FIRE_KEY] = Key();
    keys[KEY::GRAB_KEY] = Key();
}

void Keypad::press(KEY k) {
    this->keys[k].press();
}

void Keypad::release(KEY k) {
    this->keys[k].release();
}

double Keypad::elapsedTimeBeingPressed(KEY k) {
    return this->keys[k].elapsedTimeBeingPressed();
}

bool Keypad::isBeingPressed(KEY k) {
    return this->keys[k].isBeingPressed();
}

Key *Keypad::getKey(KEY k) {
    return &this->keys[k];
}

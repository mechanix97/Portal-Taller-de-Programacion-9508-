#include "../../include/boolean_suppliers/simple_boolean.h"

SimpleBoolean::SimpleBoolean(bool value):
    value(value) {
}

bool SimpleBoolean::getAsBoolean() const {
    return this->value;
}

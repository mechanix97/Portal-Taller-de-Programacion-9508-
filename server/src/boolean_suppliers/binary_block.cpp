#include "../../include/boolean_suppliers/binary_block.h"

BinaryBlock::BinaryBlock(const BinaryOperator *boolean_operator):
    boolean_operator(boolean_operator) {
}

BinaryBlock::~BinaryBlock() {
}

bool BinaryBlock::getAsBoolean() const {
    bool acum = this->booleans.at(0)->getAsBoolean();

    for (unsigned int i = 1; i < this->booleans.size(); i++) {
        bool a_boolean = this->booleans.at(i)->getAsBoolean();
        acum = this->boolean_operator->evaluate(acum, a_boolean);
    }

    return acum;
}

void BinaryBlock::add(BooleanSupplier *boolean) {
    this->booleans.push_back(boolean);
}

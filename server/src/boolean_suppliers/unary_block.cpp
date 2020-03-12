#include "../../include/boolean_suppliers/unary_block.h"

UnaryBlock::UnaryBlock(UnaryOperator *unary_operator):
    unary_operator(unary_operator) {
}

void UnaryBlock::add(BooleanSupplier *boolean) {
    this->boolean = boolean;
}

bool UnaryBlock::getAsBoolean() const {
    bool b = this->boolean->getAsBoolean();
    return this->unary_operator->evaluate(b);
}

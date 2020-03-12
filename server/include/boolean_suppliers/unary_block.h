#ifndef __UNARY_BLOCK_H__
#define __UNARY_BLOCK_H__

#include "boolean_block.h"
#include "unary_operator.h"


class UnaryBlock: public BooleanBlock {
private:
    UnaryOperator *unary_operator;
    BooleanSupplier *boolean;

public:
    UnaryBlock(UnaryOperator *unary_operator);
    virtual void add(BooleanSupplier *boolean);
    virtual bool getAsBoolean() const;
};

#endif

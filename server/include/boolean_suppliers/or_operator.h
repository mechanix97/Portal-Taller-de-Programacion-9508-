#ifndef __OR_OPERATOR_H__
#define __OR_OPERATOR_H__

#include "../../include/boolean_suppliers/binary_operator.h"

class OrOperator: public BinaryOperator {
public:
    virtual bool evaluate(bool b1, bool b2) const;
};

#endif

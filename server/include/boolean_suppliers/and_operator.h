#ifndef __AND_OPERATOR_H__
#define __AND_OPERATOR_H__

#include "../../include/boolean_suppliers/binary_operator.h"

class AndOperator: public BinaryOperator {
public:
    virtual bool evaluate(bool b1, bool b2) const;
};

#endif

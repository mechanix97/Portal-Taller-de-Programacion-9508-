#ifndef __SAME_OPERATOR_H__
#define __SAME_OPERATOR_H__

#include "unary_operator.h"

class SameOperator: public UnaryOperator {
public:
    virtual bool evaluate(bool boolean) const;
};

#endif

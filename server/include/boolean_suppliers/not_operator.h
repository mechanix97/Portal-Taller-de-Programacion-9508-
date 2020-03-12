#ifndef __NOT_OPERATOR_H__
#define __NOT_OPERATOR_H__

#include "unary_operator.h"

class NotOperator: public UnaryOperator {
public:
    virtual bool evaluate(bool boolean) const;
};

#endif

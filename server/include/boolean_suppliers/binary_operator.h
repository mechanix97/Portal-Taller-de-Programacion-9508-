#ifndef __BINARY_OPERATOR_H__
#define __BINARY_OPERATOR_H__

class BinaryOperator {
public:
    virtual ~BinaryOperator();
    virtual bool evaluate(bool b1, bool b2) const = 0;
};

#endif

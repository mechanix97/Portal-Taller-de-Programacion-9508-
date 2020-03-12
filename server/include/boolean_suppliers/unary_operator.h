#ifndef __UNARY_OPERATOR_H__
#define __UNARY_OPERATOR_H__

class UnaryOperator {
public:
    ~UnaryOperator();
    virtual bool evaluate(bool boolean) const = 0;
};

#endif

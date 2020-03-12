#ifndef __BOOLEAN_OPERATOR_H__
#define __BOOLEAN_OPERATOR_H__

class BooleanOperator {
public:
    virtual ~BooleanOperator();
    virtual bool evualuate(bool b1, bool b2) const = 0;
};

#endif

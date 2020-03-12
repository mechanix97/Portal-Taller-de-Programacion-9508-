#ifndef __SIMPLE_BOOLEAN_H__
#define __SIMPLE_BOOLEAN_H__

#include "boolean_supplier.h"

class SimpleBoolean: public BooleanSupplier {
private:
    bool value;

public:
    SimpleBoolean(bool value);
    virtual bool getAsBoolean() const;
};

#endif

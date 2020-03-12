#ifndef __GATEABLE_H__
#define __GATEABLE_H__

#include "../../boolean_suppliers/boolean_supplier.h"

class Gate;

class Gateable: public BooleanSupplier {
public:
    virtual void setGate(Gate *gate) = 0;
};

#endif

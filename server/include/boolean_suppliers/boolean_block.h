#ifndef __BOOLEAN_BLOCK_H__
#define __BOOLEAN_BLOCK_H__

#include "boolean_supplier.h"

class BooleanBlock: public BooleanSupplier {
public:
    virtual void add(BooleanSupplier *boolean) = 0;
};

#endif

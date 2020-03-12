#ifndef __BOOLEAN_SUPPLIER_H__
#define __BOOLEAN_SUPPLIER_H__

class BooleanSupplier {
public:
    virtual ~BooleanSupplier();
    virtual bool getAsBoolean() const = 0;    
};

#endif

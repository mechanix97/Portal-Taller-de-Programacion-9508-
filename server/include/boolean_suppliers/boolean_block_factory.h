#ifndef __BOOLEAN_BLOCK_FACTORY_H__
#define __BOOLEAN_BLOCK_FACTORY_H__

#include "boolean_block.h"
#include "binary_block.h"
#include "unary_block.h"
#include "and_operator.h"
#include "or_operator.h"
#include "same_operator.h"
#include "not_operator.h"
#include <vector>

/* Clase encargada de la creacion de bloques booleanos.
 * Es la misma clase la que se encarga de la liberacion de memoria
 * de los bloques pedidos */
class BooleanBlockFactory {
private:
    std::vector<BooleanBlock *> blocks;

    // Operadores binarios
    AndOperator and_operator;
    OrOperator or_operator;

    // Operadores unarios
    SameOperator same_operator;
    NotOperator not_operator;

public:
    ~BooleanBlockFactory();
    BooleanBlock *createAndBlock();
    BooleanBlock *createOrBlock();
    BooleanBlock *createNotBlock();
    BooleanBlock *createSameBlock();
};

#endif

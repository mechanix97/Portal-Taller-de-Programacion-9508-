#ifndef __BINARY_BLOCK_TEST_H__
#define __BINARY_BLOCK_TEST_H__

#include "../../server/include/boolean_suppliers/simple_boolean.h"
#include "../../server/include/boolean_suppliers/binary_block.h"
#include "../../server/include/boolean_suppliers/and_operator.h"
#include "../../server/include/boolean_suppliers/or_operator.h"
#include "../../server/include/boolean_suppliers/unary_block.h"
#include "../../server/include/boolean_suppliers/not_operator.h"
#include <cxxtest/TestSuite.h>

class BinaryBlockTest: public CxxTest::TestSuite {
public:
    void testBinaryBlockAplicaANDSobreSusElementosYDevuelveTrue() {
        SimpleBoolean sb1(true);
        SimpleBoolean sb2(true);
        SimpleBoolean sb3(true);
        AndOperator and_operator;
        BinaryBlock bb(&and_operator);
        bb.add(&sb1);
        bb.add(&sb2);
        bb.add(&sb3);

        bool r = bb.getAsBoolean();

        TS_ASSERT(r);
    }

    void testBinaryBlockAplicaORSobreTresFalsesYDaFalse() {
        SimpleBoolean sb1(false);
        SimpleBoolean sb2(false);
        SimpleBoolean sb3(false);
        OrOperator or_operator;
        BinaryBlock bb(&or_operator);
        bb.add(&sb1);
        bb.add(&sb2);
        bb.add(&sb3);

        bool r = bb.getAsBoolean();

        TS_ASSERT_EQUALS(false, r);
    }

    void testBinaryBlockAplicaANDSobreNotTrueFalseYDevuelveFalse() {
        SimpleBoolean sb1(true);
        SimpleBoolean sb2(false);

        // Meto a sb1 sobre un not-block para negarlo.
        NotOperator not_op;
        UnaryBlock unary_block(&not_op);
        unary_block.add(&sb1);

        // Agrego sb2 y not-block al bloque AND
        AndOperator and_operator;
        BinaryBlock bb(&and_operator);
        bb.add(&sb2);
        bb.add(&unary_block);

        bool r = bb.getAsBoolean();

        TS_ASSERT_EQUALS(false, r);
    }
};

#endif

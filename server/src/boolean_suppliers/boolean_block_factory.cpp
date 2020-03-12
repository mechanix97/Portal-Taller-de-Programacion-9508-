#include "../../include/boolean_suppliers/boolean_block_factory.h"
#include "../../include/boolean_suppliers/boolean_block.h"

BooleanBlockFactory::~BooleanBlockFactory() {
    for (BooleanBlock *block: this->blocks) {
        delete block;
    }
}

BooleanBlock *BooleanBlockFactory::createAndBlock() {
    BooleanBlock *block = new BinaryBlock(&this->and_operator);
    this->blocks.push_back(block);
    return block;
}

BooleanBlock *BooleanBlockFactory::createOrBlock() {
    BooleanBlock *block = new BinaryBlock(&this->or_operator);
    this->blocks.push_back(block);
    return block;
}

BooleanBlock *BooleanBlockFactory::createNotBlock() {
    BooleanBlock *block = new UnaryBlock(&this->not_operator);
    this->blocks.push_back(block);
    return block;
}

BooleanBlock *BooleanBlockFactory::createSameBlock() {
    BooleanBlock *block = new UnaryBlock(&this->same_operator);
    this->blocks.push_back(block);
    return block;
}

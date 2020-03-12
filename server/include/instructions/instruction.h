#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

class Instruction {
public:
    virtual ~Instruction();
    virtual void execute() = 0;
};

#endif

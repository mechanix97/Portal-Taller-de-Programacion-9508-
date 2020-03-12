#ifndef __ACTION_H__
#define __ACTION_H__

#include <cstdint>

enum ACTION: uint8_t {
    NONE_ACTION,
    QUIT,
    JUMP,
    STOP_JUMP,
    RUN_LEFT,
    RUN_RIGHT,
    STOP_LEFT,
    STOP_RIGHT,
    GRAB,
    STOP_GRAB,
    JIG,
    FIRE1,
    FIRE2,
    PING,
    RESET_PORTALS
};

class Action{
private:
    uint32_t id;
	ACTION action;
	int32_t param1;
    int32_t param2;
public:
    Action();
	explicit Action(uint32_t id,ACTION ac,int32_t param1,int32_t param2);
	~Action();
    uint32_t getId() const;
	ACTION getAction() const;
	int32_t getParam1() const;
    int32_t getParam2() const;
};

#endif

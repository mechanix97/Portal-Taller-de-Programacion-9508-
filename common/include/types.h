#ifndef _TYPES_H_
#define _TYPES_H_

#include <cstdint>
#include <cmath>

#define PI (4*atan(1))
#define DEGTORAD(alfa) (alfa*(PI/180.0))
#define RADTODEG(alfa) (alfa*(180.0/PI))
#define FPS_FACTOR 6

enum ENTITY: uint8_t {
	NONE_ENTITY 			= 0x00,
	CHELL 					= 0x01,
	STONE_BLOCK				= 0x02,
	METAL_BLOCK				= 0x03,
	METAL_TRIAG_BLOCK		= 0x04,
	LAUNCH_BLOCK			= 0x05,
	RECEIVER_BLOCK			= 0x06,
	ROCK					= 0x07,
	BUTTON					= 0x08,
	GATE					= 0x09,
	ACID					= 0x0A,
	BULLET					= 0x0B,
	LASER					= 0x0C,
	PIN						= 0x0D,
	CAKE					= 0x0E,
	PORTAL1					= 0x0F,
	PORTAL2					= 0x10
};

enum COMMAND : uint8_t{
	NONE_COMMAND			= 0x00,
	CREATE_COMMAND			= 0x01,
	UPDATE_COMMAND			= 0x02,
	DESTROY_COMMAND			= 0x03,
	WIN_COMMAND				= 0x04,
	LOSE_COMMAND			= 0x05,
};

enum STATUS: uint8_t {
	NONE_STATUS 			= 0x00,
	CHELL_IDLE              = 0x01,
	CHELL_RUNNING           = 0x02,
	CHELL_TURNING           = 0x03,
	CHELL_STOPING           = 0x04,
	CHELL_JUMPING           = 0x05,
	CHELL_JUMPING_APEX      = 0x06,
	CHELL_FALLING           = 0x07,
	CHELL_LANDING           = 0x08,
	CHELL_FIRE              = 0x09,
	CHELL_FIRE_TO_IDLE		= 0x0A,
	CHELL_JIGING            = 0x0B,
	CHELL_DIE               = 0x0C,
	BUTTON_ON               = 0x0D,
	BUTTON_OFF              = 0x0E,
	GATE_OPENED             = 0x0F,
	GATE_CLOSED				= 0x10,
	GATE_OPENING			= 0x11,
	GATE_CLOSING            = 0x12,
};

enum DIRECTION: uint8_t {
	RIGHT_DIRECTION			= 0x00,
	DOWN_DIRECTION  		= 0x01,
	LEFT_DIRECTION  		= 0x02,
	UP_DIRECTION    		= 0x03
};

enum ORIENTATION: uint8_t {
	ORIENTATION_0 = 0x00,
	ORIENTATION_1 = 0x01,
	ORIENTATION_2 = 0x02,
	ORIENTATION_3 = 0x03
};

enum ANGLE: uint16_t {
	ANGLE_000 = 0x000,
	ANGLE_045 = 0x02D,
	ANGLE_090 = 0x05A,
	ANGLE_135 = 0x087,
	ANGLE_180 = 0x0B4,
	ANGLE_225 = 0x0E1,
	ANGLE_270 = 0x10E,
	ANGLE_315 = 0x13B,
};

#endif

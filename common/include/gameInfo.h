#ifndef _GAME_INFO_H_
#define _GAME_INFO_H_

#include <string>
#include <cstdint>

class GameInfo{
	uint32_t id;
	std::string mapName;
	uint32_t players;
	uint32_t capacity;
public:
	explicit GameInfo(uint32_t id,const std::string& mapName, 
		uint32_t players, uint32_t capacity);
	~GameInfo();
	uint32_t getId() const;
	const std::string& getMapName() const;
	uint32_t getPlayers() const;
	uint32_t getCapacity() const;
	void setPlayers(uint32_t p);
	void setCapacity(uint32_t c);
};

#endif

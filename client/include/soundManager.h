#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

#include <SDL_mixer.h>

#include "../include/SdlException.h"

#define MUSIC_ROUTE "../resources/sounds/music.mp3"
#define JUMP_SOUND_ROUTE "../resources/sounds/jump.mp3"
#define FIRE_SOUND_ROUTE "../resources/sounds/fire.mp3"
#define DEATH_SOUND_ROUTE "../resources/sounds/death.mp3"
#define PIN_SOUND_ROUTE "../resources/sounds/pin.mp3"


class SoundManager{
private:
	Mix_Music* music = nullptr;
	Mix_Chunk* jumpSound = nullptr;
	Mix_Chunk* fireSound = nullptr;
	Mix_Chunk* deathSound = nullptr;
	Mix_Chunk* pinSound = nullptr;
public:
	SoundManager();
	~SoundManager();
	void playMusic() const;
	int getMusicVolume() const;
	void setMusicVolume(int volume);
	void resumeMusic() const;
	void pauseMusic() const;
	bool isMusicPaused() const;	
	void playJumpSound() const;
	void playFireSound() const;
	void playDeathSound() const;
	void playPinSound() const;
	void turnMusicDown();
	void turnMusicUp();
	int getFxVolume() const;
	void turnFxDown();
	void turnFxUp();
};

#endif

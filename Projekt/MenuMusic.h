#pragma once
#include "Headers.h"

class MenuMusic {
public:
	MenuMusic();
	~MenuMusic();

	void start();
	void stop();
	void setVolume(float volume);
	void reset();

private:
	sf::Music music;
	bool isPlaying;
};
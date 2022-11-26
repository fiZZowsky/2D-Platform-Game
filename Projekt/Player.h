#pragma once

#include "Headers.h";
#include "Settings.h"

class Player {
public:
	Player();
	~Player();

	bool jumping;
	int JumpTimer;

	sf::Sprite player;
	sf::Texture t;
	sf::Texture big;
	sf::Texture fire;
	sf::Texture dead;

	bool mariodie = 0; int   countmario, DeathSound = false;
	bool big_mario;

	sf::SoundBuffer Jump;
	sf::SoundBuffer PowerUp;
	sf::Sound sound;
	sf::Music MarioDeath;

	bool LookingLeft = false, LookingRight = false;
	bool SightR = false, SightL = false;

	bool marioburn;
	float speed;
	float gravity;
	sf::Vector2f velocity;

	void setPlayer();
	sf::Vector2f getPosition();
	void reset();
	void updateTexture(int number);
	void checkCollision();
};
#include "Player.h"

Player::Player() {
	Jump.loadFromFile("Audio/jump-small.wav");
	PowerUp.loadFromFile("Audio/powerup.wav");
	MarioDeath.openFromFile("Audio/mariodie.wav");
	t.loadFromFile("Images/mini.png");
	big.loadFromFile("Images/mshmini.png");
	fire.loadFromFile("Images/MarioOnFire.png");
	marioburn = false;
	jumping = false;
	big_mario = false;
	speed = 3.0;
	gravity = 0.6;
}

Player::~Player() {}

void Player::setPlayer() {
	player.setTexture(t);
	player.setPosition(50, 120);
	player.setTextureRect(sf::IntRect(0 * 32, 0 * 32, 32, 32));
	player.setScale(0.5, 0.5);
	jumping = true;
}

sf::Vector2f Player::getPosition() {
	return player.getPosition();
}

void Player::reset() {
	player.setOrigin(0, 0);
	player.setScale(0.5, 0.5);
}

void Player::updateTexture(int number) {
	if (!mariodie) {
		if (big_mario)
			player.setTexture(big);
		if (marioburn)
			player.setTexture(fire);

		if (!big_mario && !marioburn)
			player.setTextureRect(sf::IntRect(number * 32, 0 * 32, 32, 32));
		else
			player.setTextureRect(sf::IntRect(number * 32, 0 * 64, 32, 64));

		if (jumping) {
			if (big_mario || marioburn)
				player.setTextureRect(sf::IntRect(32 * 5, 0, 32, 64));
			else
				player.setTextureRect(sf::IntRect(32 * 5, 0, 32, 32));
		}
		else if (velocity.x != 0)
		{
			if (big_mario || marioburn)
				player.setTextureRect(sf::IntRect(32 * number, 0, 32, 64));
			else
				player.setTextureRect(sf::IntRect(32 * number, 0, 32, 32));
		}
		else {
			if (big_mario || marioburn) {
				player.setTextureRect(sf::IntRect(32 * 0, 0, 32, 64));
			}
			else
				player.setTextureRect(sf::IntRect(32 * 0, 0, 32, 32));
		}
	}
	else {
		player.setTexture(dead);
		player.setTextureRect(sf::IntRect(number * 32, 0, 32, 32));
	}
}

void Player::checkCollision() {
	if (player.getPosition().x < 0.f)
		player.setPosition(0.f, player.getPosition().y);
}
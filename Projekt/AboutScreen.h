#pragma once

#include "Headers.h"
#include "Settings.h"
#include "ScreenManager.h"

class AboutScreen : public ScreenManager {
public:
	AboutScreen();
	~AboutScreen();

	void set() override;
	void draw(sf::RenderWindow& window) override;

	void updateMousePosition(sf::Vector2i mousePosition);
	bool isMouseOverBackButton() const;
	bool isMouseOver1Button() const;
	bool isMouseOver2Button() const;
	bool isMouseOver3Button() const;
	bool isMouseOver4Button() const;
	void setSpeechBubble(int number);
	//void reset();
	//void characterBlinking();

	sf::Text aboutText;
private:
	sf::RectangleShape buttonBack;
	std::vector<sf::Texture> images;
	std::vector<sf::Vector2f> imagesPos;
	std::vector<const char*> options;
	std::vector<sf::Text> texts;

	sf::CircleShape circle1;
	sf::CircleShape circle2;
	sf::CircleShape circle3;
	sf::CircleShape circle4;

	sf::Texture background;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text buttonText;
	sf::Sprite character;
	sf::Texture characterTexture;
	sf::Texture mushroomTexture;
	sf::Texture fireFlower;
	sf::Texture goomba;
	sf::Texture coin;
	sf::ConvexShape shape;
	sf::RectangleShape textField;
	sf::Vector2f textPosition;

};
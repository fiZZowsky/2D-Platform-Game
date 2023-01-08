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
	void setSpeechBubble();
	//void characterBlinking();

	sf::RectangleShape buttonBack;
private:
	std::vector<sf::CircleShape> circles;
	std::vector<sf::Vector2f> circlesPos;
	std::vector<sf::Texture> images;
	std::vector<sf::Vector2f> imagesPos;

	sf::Texture background;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text buttonText;
	sf::Text aboutText;
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
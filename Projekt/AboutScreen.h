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
};
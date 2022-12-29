#pragma once

#include "Headers.h"
#include "Settings.h"
#include "ScreenManager.h"

class AboutScreen : public ScreenManager {
public:
	void set();
	void draw(sf::RenderWindow& window);

	void updateMousePosition(sf::Vector2i mousePosition);
	bool isMouseOverBackButton() const;

	sf::RectangleShape buttonBack;
private:
	sf::Texture background;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text buttonText;
};
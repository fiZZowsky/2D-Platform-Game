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
	sf::Texture background;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text buttonText;
};
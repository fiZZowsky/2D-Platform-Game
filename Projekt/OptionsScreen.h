#pragma once
#include "ScreenManager.h"
#include "Settings.h"

class OptionsScreen : public ScreenManager {
public:
	OptionsScreen();
	~OptionsScreen();

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
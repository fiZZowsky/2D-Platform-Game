#pragma once

#include "Headers.h"
#include "Settings.h"
#include "ScreenManager.h"

class EndGameScreen : public ScreenManager {
public:
	EndGameScreen();
	~EndGameScreen();

	void set() override;
	void draw(sf::RenderWindow& window) override;
	void updateScore();
	void updateMousePosition(sf::Vector2i mousePosition);
	bool isMouseOverBackButton() const;

private:
	std::vector<const char*> gravesideOptions;
	std::vector<sf::Vector2f> textsCoords;
	std::vector<sf::Text> gravesideTexts;

	sf::Texture background;
	sf::Sprite sprite;

	sf::RectangleShape buttonBack;
	sf::Font font;
	sf::Font gravesideFont;
	sf::Text buttonText;

	int score;
};
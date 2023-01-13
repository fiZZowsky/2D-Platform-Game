#pragma once
#include "ScreenManager.h"
#include "Settings.h"

class WinGameScreen : public ScreenManager {
public:
	WinGameScreen();
	~WinGameScreen();

	void set() override;
	void draw(sf::RenderWindow& window) override;

	void updateMousePosition(sf::Vector2i mousePosition);
	bool isMouseOverBackButton() const;

	void updateScore();

	sf::RectangleShape buttonBack;

private:
	sf::Texture background;
	sf::Sprite sprite;
	sf::Font font;
	sf::Font buttonFont;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> textsCoords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;
	sf::Text hightScoreText;
	sf::Text scoreText;
	sf::Text buttonText;

	int highscore;
	int score;
};
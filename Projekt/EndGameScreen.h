#pragma once
#include "ScreenManager.h"
#include "Settings.h"

using namespace std;

class EndGameScreen : public ScreenManager {
public:
	EndGameScreen();
	~EndGameScreen();

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

	std::vector<const char*> options;
	std::vector<sf::Vector2f> textsCoords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;
	sf::Text hightScoreText;
	sf::Text scoreText;

	int highscore;
	int score;
};
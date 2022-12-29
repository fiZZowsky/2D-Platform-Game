#pragma once

#include "Headers.h"
#include "Settings.h"
#include "ScreenManager.h"

class Menu : public ScreenManager {
public:
	void set();
	void draw(sf::RenderWindow& window);

	void updateMousePosition(sf::Vector2i mousePosition);
	bool isMouseOverPlay() const;
	bool isMouseOverOptions() const;
	bool isMouseOverAbout() const;
	bool isMouseOverExit() const;

	std::vector<sf::RectangleShape> rectangle;

private:
	std::vector<const char*> options;
	std::vector<sf::Vector2f> textsCoords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

	std::vector<sf::Vector2f> rectanglesCoords;
	sf::Vector2f rectsSize;
	sf::Texture background;
	sf::Sprite sprite;

	sf::Font m_font;
};
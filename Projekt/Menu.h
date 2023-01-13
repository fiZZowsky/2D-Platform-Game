#pragma once

#include "Headers.h"
#include "Settings.h"
#include "ScreenManager.h"

class Menu : public ScreenManager {
public:
	Menu();
	~Menu();

	void set() override;
	void draw(sf::RenderWindow& window) override;

	void updateMousePosition(sf::Vector2i mousePosition);
	bool isMouseOverPlay() const;
	bool isMouseOverAbout() const;
	bool isMouseOverExit() const;
	bool isMouseOverMute() const;
	void setMuteButton(bool isMusicMuted);

	std::vector<sf::RectangleShape> rectangle;

private:
	//Przyciski glowne
	std::vector<const char*> options;
	std::vector<sf::Vector2f> textsCoords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;
	std::vector<sf::Vector2f> rectanglesCoords;
	sf::Vector2f rectsSize;

	//T³o
	sf::Texture backgroundtexture;
	sf::Sprite backgroundSprite;

	sf::Font m_font;

	//Przycisk mute i unmute
	sf::Texture muteTexture;
	sf::Texture unmuteTexture;
};
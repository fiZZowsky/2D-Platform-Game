#pragma once
#include "Headers.h"
#include "Settings.h"
#include "Menu.h"
#include "Map.h"
#include "AboutScreen.h"
#include "ScreenManager.h"
#include "EndGameScreen.h"
#include "WinGameScreen.h"
#include "MenuMusic.h"

using namespace std;
using namespace sf;

class Engine {
public:
	Engine();
	~Engine();

	void run();
private:
	ScreenManager* currentScreen;
	Menu menu;
	Map map;
	EndGameScreen endGame;
	WinGameScreen winGame;
    AboutScreen about;
	MenuMusic m_music;

	int counter;
	bool isMusicMuted;

	//Przycisk do wy³¹czania/w³¹czania muzyki w menu 
	sf::RectangleShape muteButton;
	sf::Text muteButtonText;
	sf::Texture muteButtonTexture;
	sf::Texture unmuteButtonTexture;
	sf::Sprite muteButtonSprite;
};
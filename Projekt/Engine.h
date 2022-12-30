#pragma once
#include "Headers.h"
#include "Settings.h"
#include "Menu.h"
#include "Map.h"
#include "OptionsScreen.h"
#include "AboutScreen.h"
#include "ScreenManager.h"
#include "EndGameScreen.h"

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
	OptionsScreen options;
    AboutScreen about;
};
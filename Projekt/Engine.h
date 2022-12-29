#pragma once
#include "Headers.h"
#include "Settings.h"
#include "Menu.h"
//#include "GameScreen.h"
#include "OptionsScreen.h"
#include "AboutScreen.h"
#include "ScreenManager.h"

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
	//GameScreen game;
	OptionsScreen options;
    AboutScreen about;
};
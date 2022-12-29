#pragma once
#include "Headers.h"
#include "Settings.h"
#include "Menu.h"
#include "Map.h"
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
    AboutScreen about;
	Map map;
};
#pragma once
#include "Headers.h"
#include "Settings.h"
#include "Map.h"

using namespace std;
using namespace sf;

class Engine {
public:
	Engine();
	~Engine();

	void run();
private:
	Color backgroundColor;

	Map map;
	void setCoins();
};
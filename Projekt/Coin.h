#pragma once
#include "Headers.h"

using namespace std;
using namespace sf;

class Coin {
public:
	Coin();

	void set();
	int bonus();

private:
	Texture BCoin;
	Texture cointx;
	Sprite BonusCoin[13];

	int ind;
};
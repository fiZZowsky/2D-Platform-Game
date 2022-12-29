#include "Headers.h"

class ScreenManager {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void set() = 0;
};
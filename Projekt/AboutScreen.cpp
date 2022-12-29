#include "AboutScreen.h"

void AboutScreen::set() {
	//Ustawienie t³a menu
	background.loadFromFile("Images/menuBackground.png");
	sprite.setTexture(background);

	//Ustawienie przycisku powrotu do menu
	buttonBack.setPosition(sf::Vector2f(1760, 990));
	buttonBack.setSize(sf::Vector2f(124, ABOUT_BUTTON_TEXT_SIZE + 10));
	buttonBack.setOutlineThickness(3);
	buttonBack.setOutlineColor(sf::Color(0, 0, 0));
	buttonBack.setFillColor(sf::Color::Transparent);
}

void AboutScreen::updateMousePosition(sf::Vector2i mousePosition) {
	buttonBack.setOutlineColor(buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)) ? sf::Color(0, 255, 0) : sf::Color(0, 0, 0));
}

bool AboutScreen::isMouseOverBackButton() const {
	return buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void AboutScreen::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(sprite);
	window.draw(buttonBack);
}

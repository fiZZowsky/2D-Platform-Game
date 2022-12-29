#include "AboutScreen.h"

AboutScreen::AboutScreen() {
	background.loadFromFile("Images/menuBackground.png");
	font.loadFromFile("font/arial.ttf");
}

AboutScreen::~AboutScreen() { }

void AboutScreen::set() {
	//Ustawienie t³a menu
	sprite.setTexture(background);

	//Ustawienie przycisku powrotu do menu
	buttonBack.setPosition(sf::Vector2f(1760, 990));
	buttonBack.setSize(sf::Vector2f(124, ABOUT_BUTTON_TEXT_SIZE + 10));
	buttonBack.setOutlineThickness(3);
	buttonBack.setOutlineColor(sf::Color(0, 0, 0));
	buttonBack.setFillColor(sf::Color::Transparent);

	//Ustawienie napisu na przycisku
	buttonText.setFont(font);
	buttonText.setString("Back");
	buttonText.setCharacterSize(ABOUT_BUTTON_TEXT_SIZE);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setPosition(sf::Vector2f(1770, 990));
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
	window.draw(buttonText);
}

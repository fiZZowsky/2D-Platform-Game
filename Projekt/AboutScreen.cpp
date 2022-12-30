#include "AboutScreen.h"

AboutScreen::AboutScreen() {
	background.loadFromFile("Images/optionsBackground.png");
	font.loadFromFile("font/PublicPixel.ttf");
}

AboutScreen::~AboutScreen() { }

void AboutScreen::set() {
	//Ustawienie t³a menu
	sprite.setTexture(background);

	//Ustawienie przycisku powrotu do menu
	buttonBack.setPosition(sf::Vector2f(1760, 990));
	buttonBack.setSize(sf::Vector2f(160, ABOUT_BUTTON_TEXT_SIZE + 10));
	buttonBack.setFillColor(sf::Color::Transparent);

	//Ustawienie napisu na przycisku
	buttonText.setFont(font);
	buttonText.setString("Back");
	buttonText.setCharacterSize(ABOUT_BUTTON_TEXT_SIZE);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setPosition(sf::Vector2f(1770, 990));
	buttonText.setOutlineThickness(2);
	buttonText.setOutlineColor(sf::Color::Black);
}

void AboutScreen::updateMousePosition(sf::Vector2i mousePosition) {
	if (buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		buttonText.setFillColor(sf::Color(0, 0, 0));
	}
	else {
		buttonText.setFillColor(sf::Color(255, 255, 255));
	}
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

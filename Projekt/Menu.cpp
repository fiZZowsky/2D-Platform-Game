#include "Menu.h"

void Menu::set() {
	//Ustawienie t³a menu
	background.loadFromFile("Images/menuBackground.png");
	sprite.setTexture(background);

	// Ustawienie czcionki tekstu
	m_font.loadFromFile("font/arial.ttf");

	// Ustawienie tekstow dla poszczegolnych opcji
	options = { "Mario The Game", "Play", "Options", "About", "Quit" };
	texts.resize(MENU_TEXTS_NUMBER);
	textsCoords = { {700,40},{50,400},{50,480},{50,560},{50,640} };
	sizes = { MENU_BUTTONS_TEXT_SIZE * 3,MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE };

	// Ustawienie prostokatow dla poszczegolnych opcji
	rectangle.resize(MENU_BUTTONS_NUMBER);
	rectanglesCoords = { {40,400}, {40,480}, {40,560}, {40,640} };
	rectsSize = { 202,MENU_BUTTONS_TEXT_SIZE + 10 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(m_font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Black);
		texts[i].setPosition(textsCoords[i]);
	}

	for (int i = 0; i < rectangle.size(); ++i) {
		rectangle[i].setSize(rectsSize);
		rectangle[i].setOutlineThickness(3);
		rectangle[i].setOutlineColor(sf::Color(0, 0, 0));
		rectangle[i].setPosition(rectanglesCoords[i]);
		rectangle[i].setFillColor(sf::Color::Transparent);
	}
}

void Menu::updateMousePosition(sf::Vector2i mousePosition)
{
	// Aktualizacja stanu prostok¹tów dla opcji (podœwietlenie lub brak podœwietlenia)
	for (int i = 0; i < rectangle.size(); ++i) {
		rectangle[i].setOutlineColor(rectangle[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)) ? sf::Color(0, 255, 0) : sf::Color(0, 0, 0));
	}
}

bool Menu::isMouseOverPlay() const
{
	return rectangle[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool Menu::isMouseOverOptions() const
{
	return rectangle[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool Menu::isMouseOverAbout() const
{
	return rectangle[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool Menu::isMouseOverExit() const
{
	return rectangle[3].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void Menu::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(sprite);

	for (auto t : texts) {
		window.draw(t);
	}

	for (auto r : rectangle) {
		window.draw(r);
	}
}
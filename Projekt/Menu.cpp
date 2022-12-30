#include "Menu.h"

Menu::Menu() {
	background.loadFromFile("Images/menuBackground.png");
	m_font.loadFromFile("font/PublicPixel.ttf");
}

Menu::~Menu() { }

void Menu::set() {
	//Ustawienie t³a menu
	sprite.setTexture(background);

	// Ustawienie tekstow dla poszczegolnych opcji
	options = { "Play", "Options", "About", "Quit", "Alpha v0.0.7" };
	texts.resize(MENU_TEXTS_NUMBER);
	textsCoords = { {865,390},{800,520},{840,650},{865,780}, {1660,1040} };
	sizes = { MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE, MENU_BUTTONS_TEXT_SIZE - 30 };

	// Ustawienie prostokatow dla poszczegolnych opcji
	rectangle.resize(MENU_BUTTONS_NUMBER);
	rectanglesCoords = { {650,380}, {650,510}, {650,640}, {650,770} };
	rectsSize = { 629,82 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(m_font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setPosition(textsCoords[i]);
		texts[i].setOutlineThickness(2);
		texts[i].setOutlineColor(sf::Color::Black);
	}

	for (int i = 0; i < rectangle.size(); ++i) {
		rectangle[i].setSize(rectsSize);
		rectangle[i].setOutlineThickness(3);
		rectangle[i].setOutlineColor(sf::Color(1, 122, 255));
		rectangle[i].setPosition(rectanglesCoords[i]);
		rectangle[i].setFillColor(sf::Color(1,122,255));
	}
}

void Menu::updateMousePosition(sf::Vector2i mousePosition) {
	// Aktualizacja stanu prostok¹tów dla opcji (podœwietlenie lub brak podœwietlenia)
	for (int i = 0; i < rectangle.size(); ++i) {
		if (rectangle[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
			rectangle[i].setOutlineColor(sf::Color(0, 0, 0));
			texts[i].setFillColor(sf::Color(0, 0, 0));
		}
		else {
			rectangle[i].setOutlineColor(sf::Color(1, 122, 255));
			texts[i].setFillColor(sf::Color(255, 255, 255));
		}
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

	for (auto r : rectangle) {
		window.draw(r);
	}

	for (auto t : texts) {
		window.draw(t);
	}
}
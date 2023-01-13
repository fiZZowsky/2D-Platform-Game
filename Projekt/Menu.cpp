#include "Menu.h"

Menu::Menu() {
	//Wczytanie tekstur
	backgroundtexture.loadFromFile("Images/menuBackground.png");
	muteTexture.loadFromFile("Images/mute.png");
	unmuteTexture.loadFromFile("Images/unmute.png");

	//Wczytanie czcionki dla tekstu
	m_font.loadFromFile("font/PublicPixel.ttf");

	texts.resize(MENU_TEXTS_NUMBER);
	rectangle.resize(MENU_BUTTONS_NUMBER);

	//Ustawienie pocz¹tkowej tekstury dla przycisku mute
	rectangle[3].setTexture(&muteTexture);
}

Menu::~Menu() { }

void Menu::set() {
	//Ustawienie t³a menu
	backgroundSprite.setTexture(backgroundtexture);

	// Ustawienie tekstow dla poszczegolnych opcji
	options = { "Play", "About", "Quit", "Alpha v0.0.7" };
	
	textsCoords = { {865,390},{840,520},{865,650}, {1660,1040} };
	sizes = { MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE,MENU_BUTTONS_TEXT_SIZE, MENU_BUTTONS_TEXT_SIZE - 30 };

	// Ustawienie prostokatow dla poszczegolnych opcji
	rectanglesCoords = { {650,380}, {650,510}, {650,640}, {1810, 40} };
	rectsSize = { 629,82 };

	//Ustawienie napisów na przyciskach
	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(m_font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setPosition(textsCoords[i]);
		texts[i].setOutlineThickness(2);
		texts[i].setOutlineColor(sf::Color::Black);
	}

	//Ustawienie prostok¹tów jako przycisków
	for (int i = 0; i < rectangle.size() - 1; ++i) {
		rectangle[i].setSize(rectsSize);
		rectangle[i].setOutlineThickness(3);
		rectangle[i].setOutlineColor(sf::Color(1, 122, 255));
		rectangle[i].setPosition(rectanglesCoords[i]);
		rectangle[i].setFillColor(sf::Color(1,122,255));
	}
	
	//Ustawienie prostok¹tu dla przycisku mute i unmute
	rectangle[3].setSize(sf::Vector2f(70, 70));
	rectangle[3].setPosition(rectanglesCoords[3]);
}

void Menu::updateMousePosition(sf::Vector2i mousePosition) {
	// Aktualizacja stanu prostok¹tów dla opcji (podœwietlenie lub brak podœwietlenia)
	for (int i = 0; i < rectangle.size() - 1; ++i) {
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

//Czy kursor znajduje siê nad przyciskiem play
bool Menu::isMouseOverPlay() const
{
	return rectangle[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

//Czy kursor znajduje siê nad przyciskiem about
bool Menu::isMouseOverAbout() const
{
	return rectangle[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

//Czy kursor znajduje siê nad przyciskiem exit
bool Menu::isMouseOverExit() const
{
	return rectangle[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

//Czy kursor znajduje siê nad przyciskiem mute/unmute
bool Menu::isMouseOverMute() const
{
	return rectangle[3].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void Menu::setMuteButton(bool isMusicMuted) {
	if (isMusicMuted == true) {
		rectangle[3].setTexture(&unmuteTexture);
	}
	else {
		rectangle[3].setTexture(&muteTexture);
	}
}

//Rysowanie zawartoœci ekranu menu g³ównego
void Menu::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(backgroundSprite);

	for (auto r : rectangle) {
		window.draw(r);
	}

	for (auto t : texts) {
		window.draw(t);
	}
}
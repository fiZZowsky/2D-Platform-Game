#include "AboutScreen.h"

AboutScreen::AboutScreen() {
	background.loadFromFile("Images/optionsBackground.png");
	font.loadFromFile("font/PublicPixel.ttf");
	characterTexture.loadFromFile("Images/characterAbout.png");
	mushroomTexture.loadFromFile("Images/mushroom.png");
	fireFlower.loadFromFile("Images/FireFlower.png");
	goomba.loadFromFile("Images/gomba.png");
	coin.loadFromFile("Images/10.png");
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

	//Ustawienie postaci
	character.setTexture(characterTexture);
	character.setTextureRect(sf::IntRect(0, 0, 50, 66));
	character.setScale(2.0f, 2.0f);
	character.setPosition(300, 800);

	//Ustawienie dymku z tekstem
	shape.setPointCount(7);
	shape.setPoint(0, sf::Vector2f(420, 800));
	shape.setPoint(1, sf::Vector2f(430, 780));
	shape.setPoint(2, sf::Vector2f(400, 780));
	shape.setPoint(3, sf::Vector2f(400, 580));
	shape.setPoint(4, sf::Vector2f(720, 580));
	shape.setPoint(5, sf::Vector2f(720, 780));
	shape.setPoint(6, sf::Vector2f(480, 780));
	shape.setFillColor(sf::Color::White);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);
	aboutText.setFont(font);
	aboutText.setCharacterSize(14);
	aboutText.setFillColor(sf::Color::Black);
	aboutText.setPosition(sf::Vector2f(410, 590));

	//Ustawienie kó³ek z obrazkami

	circle1.setPosition(sf::Vector2f(1700, 250));
	circle2.setPosition(sf::Vector2f(1750, 400));
	circle3.setPosition(sf::Vector2f(1750, 550));
	circle4.setPosition(sf::Vector2f(1700, 700));
	circle1.setRadius(CIRCLES_SIZE);
	circle2.setRadius(CIRCLES_SIZE);
	circle3.setRadius(CIRCLES_SIZE);
	circle4.setRadius(CIRCLES_SIZE);
	circle1.setOutlineColor(sf::Color::Black);
	circle2.setOutlineColor(sf::Color::Black);
	circle3.setOutlineColor(sf::Color::Black);
	circle4.setOutlineColor(sf::Color::Black);
	circle1.setOutlineThickness(2);
	circle2.setOutlineThickness(2);
	circle3.setOutlineThickness(2);
	circle4.setOutlineThickness(2);
	circle1.setTexture(&mushroomTexture);
	circle2.setTexture(&fireFlower);
	circle3.setTexture(&goomba);
	circle4.setTexture(&coin);

	options = { "After collecting it, I\nwill grow taller and\nhave more strength. We\ncan even break rocks!",
		"After collecting it, I\nget the ability to\nshoot fire!", "Watch out for him! It\ncan hurt me.",
		"A little gold never\nhurt anyone. :)" };

	texts.resize(4);
	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setString(options[i]);
	}
}

void AboutScreen::updateMousePosition(sf::Vector2i mousePosition) {
	if (buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		buttonText.setFillColor(sf::Color(0, 0, 0));
	}
	else {
		buttonText.setFillColor(sf::Color(255, 255, 255));
	}

	if (circle1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		circle1.setOutlineColor(sf::Color(0, 0, 0));
	}
	else {
		circle1.setOutlineColor(sf::Color(1, 122, 255));
	}
	if (circle2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		circle2.setOutlineColor(sf::Color(0, 0, 0));
	}
	else {
		circle2.setOutlineColor(sf::Color(1, 122, 255));
	}
	if (circle3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		circle3.setOutlineColor(sf::Color(0, 0, 0));
	}
	else {
		circle3.setOutlineColor(sf::Color(1, 122, 255));
	}
	if (circle4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		circle4.setOutlineColor(sf::Color(0, 0, 0));
	}
	else {
		circle4.setOutlineColor(sf::Color(1, 122, 255));
	}
}

bool AboutScreen::isMouseOverBackButton() const {
	return buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver1Button() const {
	return circle1.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver2Button() const {
	return circle2.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver3Button() const {
	return circle3.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver4Button() const {
	return circle4.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void AboutScreen::setSpeechBubble(int number){

	aboutText.setString(texts[number].getString());
}


void AboutScreen::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(sprite);
	window.draw(buttonBack);
	window.draw(buttonText);
	window.draw(character);
	window.draw(shape);
	window.draw(circle1);
	window.draw(circle2);
	window.draw(circle3);
	window.draw(circle4);
	window.draw(aboutText);
}

void AboutScreen::reset() {
	aboutText.setString("Choose one of the\noptions!");
}
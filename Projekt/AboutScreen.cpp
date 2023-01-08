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
	aboutText.setString("Wybierz jedn¹ z opcji po prawej!");
	textField.setPosition(sf::Vector2f(410, 590));
	textField.setSize(sf::Vector2f(300, 180));
	textPosition.x = textField.getPosition().x;
	textPosition.y = textField.getPosition().y;

	//Ustawienie kó³ek z obrazkami
	circles.resize(4);
	circlesPos = { {1700,250}, {1750,400}, {1750,550}, {1700,700} };
	for (std::size_t i{}; i < circles.size(); i++) {
		circles[i].setRadius(CIRCLES_SIZE);
		circles[i].setOutlineColor(sf::Color::Black);
		circles[i].setOutlineThickness(2);
		circles[i].setPosition(circlesPos[i]);
	}
	circles[0].setTexture(&mushroomTexture);
	circles[1].setTexture(&fireFlower);
	circles[2].setTexture(&goomba);
	circles[3].setTexture(&coin);
}

void AboutScreen::updateMousePosition(sf::Vector2i mousePosition) {
	if (buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		buttonText.setFillColor(sf::Color(0, 0, 0));
	}
	else {
		buttonText.setFillColor(sf::Color(255, 255, 255));
	}

	for (int i = 0; i < circles.size(); ++i) {
		if (circles[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
			circles[i].setOutlineColor(sf::Color(0, 0, 0));
		}
		else {
			circles[i].setOutlineColor(sf::Color(1, 122, 255));
		}
	}
}

bool AboutScreen::isMouseOverBackButton() const {
	return buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver1Button() const {
	return circles[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver2Button() const {
	return circles[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver3Button() const {
	return circles[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

bool AboutScreen::isMouseOver4Button() const {
	return circles[3].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void AboutScreen::setSpeechBubble(){
	if (isMouseOver1Button() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		aboutText.setString("Po jego zebraniu urosnê i bedê mia³ wiêcej si³y. Mo¿emy wtedy niszczyæ nawet ska³y!");
	} else if (isMouseOver2Button() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		aboutText.setString("Po jego zebraniu otrzymujê umiejêtnoœæ strzelania ogniem!");
	} else if (isMouseOver3Button() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		aboutText.setString("Uwa¿aj na niego! Mo¿e mnie zraniæ.");
	} else if (isMouseOver4Button() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		aboutText.setString("Trochê z³ota nikomu nie zaszkodzi. :)");
	}

	// Iteracja po ka¿dym s³owie tekstu
	std::string str = aboutText.getString();
	std::size_t lastSpace = 0;
	for (std::size_t i = 0; i < str.size(); ++i) {
		// Znalezienie koñca s³owa
		if (str[i] == ' ')
			lastSpace = i;
		// Ustawienie tekstu na pozycji w prostok¹cie
		aboutText.setString(str.substr(0, i + 1));
		aboutText.setPosition(textPosition);

		// Sprawdzenie, czy tekst wychodzi poza obszar prostok¹ta
		sf::FloatRect textBounds = aboutText.getLocalBounds();
		if (textBounds.left + textBounds.width > textField.getSize().x) {
			// Powrót do ostatniego wyst¹pienia spacji i wyœwietlenie tekstu w nowej linii
			aboutText.setString(str.substr(lastSpace + 1, i - lastSpace));
			textPosition.x = textField.getPosition().x;
			textPosition.y += textBounds.height;
			aboutText.setPosition(textPosition);
		}
	}
}

//void AboutScreen::characterBlinking() {
//	int i = 0;
//	while (i < 2) {
//		character.setTextureRect(sf::IntRect(i * 50, i * 50, 50, 66));
//		i++;
//		std::this_thread::sleep_for(std::chrono::seconds(2));
//		if (i == 2)
//			i = 0;
//	}
//}


void AboutScreen::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(sprite);
	window.draw(buttonBack);
	window.draw(buttonText);
	window.draw(character);
	window.draw(shape);
	window.draw(textField);
	window.draw(aboutText);
	for (auto c : circles) {
		window.draw(c);
	}
	setSpeechBubble();
}

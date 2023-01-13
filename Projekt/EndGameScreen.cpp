#include "EndGameScreen.h"

EndGameScreen::EndGameScreen() {
	background.loadFromFile("Images/loseBackground.png");
	font.loadFromFile("font/PublicPixel.ttf");
	gravesideFont.loadFromFile("font/Nova.ttf");
}

EndGameScreen::~EndGameScreen() {}

void EndGameScreen::set() {
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
	buttonText.setPosition(sf::Vector2f(1780, 990));
	buttonText.setOutlineThickness(2);
	buttonText.setOutlineColor(sf::Color::Black);

	//Ustawienie napisow na grobie
	gravesideOptions = { "RIP", "MARIO" };
	gravesideTexts.resize(4);
	textsCoords = { {1580, 680}, {1550,740},  {1610, 800}, {1510, 860} };
	
	for (std::size_t i{}; i < gravesideTexts.size(); ++i) {
		gravesideTexts[i].setFont(gravesideFont);
		
		gravesideTexts[i].setFillColor(sf::Color(69, 59, 60));
		gravesideTexts[i].setCharacterSize(40);
		gravesideTexts[i].setPosition(textsCoords[i]);
	}

	gravesideTexts[0].setString(gravesideOptions[0]);
	gravesideTexts[1].setString(gravesideOptions[1]);
	gravesideTexts[3].setString(__DATE__);
}

void EndGameScreen::updateScore() {

	std::ifstream readFile;
	readFile.open("data.txt");
	if (readFile.is_open()) {
		readFile >> score;
	}

	readFile.close();

	std::string str1 = std::to_string(score);
	gravesideTexts[2].setString(str1);
}

void EndGameScreen::updateMousePosition(sf::Vector2i mousePosition) {
	if (buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		buttonText.setFillColor(sf::Color(0, 0, 0));
	}
	else {
		buttonText.setFillColor(sf::Color(255, 255, 255));
	}
}

bool EndGameScreen::isMouseOverBackButton() const {
	return buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void EndGameScreen::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(sprite);
	window.draw(buttonBack);
	window.draw(buttonText);

	updateScore();

	for(auto g : gravesideTexts)
	window.draw(g);
}
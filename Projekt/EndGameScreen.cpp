#include "EndGameScreen.h"

EndGameScreen::EndGameScreen() {
    background.loadFromFile("Images/winBackground.jpg");
    font.loadFromFile("font/Arial.ttf");
    buttonFont.loadFromFile("font/PublicPixel.ttf");
}

EndGameScreen::~EndGameScreen() { }

void EndGameScreen::set() {
    
    sprite.setTexture(background);
    // Ustawienie tekstow dla poszczegolnych opcji
    options = { "Congratulations", "Your high score: ", "Your current score: "};
    texts.resize(END_GAME_TEXTS_NUMBER);
    textsCoords = { {650,120},{100,270},{100,230},{1720,990} };
    sizes = { END_GAME_BUTTONS_TEXT_SIZE * 2,END_GAME_BUTTONS_TEXT_SIZE,END_GAME_BUTTONS_TEXT_SIZE,END_GAME_BUTTONS_TEXT_SIZE };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setPosition(textsCoords[i]);
        texts[i].setOutlineThickness(2);
        texts[i].setOutlineColor(sf::Color::Black);
    }

    scoreText.setFont(font);
    scoreText.setFillColor(sf::Color::White); 
    scoreText.setCharacterSize(END_GAME_BUTTONS_TEXT_SIZE);
    scoreText.setPosition(sf::Vector2f(500, 230));

    hightScoreText.setFont(font);
    hightScoreText.setFillColor(sf::Color::White);
    hightScoreText.setCharacterSize(END_GAME_BUTTONS_TEXT_SIZE);
    hightScoreText.setPosition(sf::Vector2f(500, 270));

    //Ustawienie przycisku powrotu do menu
    buttonBack.setPosition(sf::Vector2f(1720, 990));
    buttonBack.setSize(sf::Vector2f(160, END_GAME_BUTTONS_TEXT_SIZE + 10));
    buttonBack.setFillColor(sf::Color::Transparent);

    buttonText.setFont(buttonFont);
    buttonText.setString("Menu");
    buttonText.setCharacterSize(END_GAME_BUTTONS_TEXT_SIZE);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(sf::Vector2f(1730, 990));
    buttonText.setOutlineThickness(2);
    buttonText.setOutlineColor(sf::Color::Black);
}

void EndGameScreen::draw(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	window.draw(sprite);
    
    for (auto t : texts) {
        window.draw(t);
    }
    window.draw(buttonBack);
    window.draw(buttonText);
    updateScore();
    window.draw(scoreText);
    window.draw(hightScoreText);
}

void EndGameScreen::updateScore() {

    std::ifstream readFile;
    readFile.open("data.txt");
    if (readFile.is_open()) {
        readFile >> score >> highscore;
    }

    readFile.close();

    std::string str1 = std::to_string(score);
    scoreText.setString(str1);
    std::string str2 = std::to_string(highscore);
    hightScoreText.setString(str2);
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
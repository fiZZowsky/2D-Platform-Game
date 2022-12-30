#include "Engine.h"

Engine::Engine() { }

Engine::~Engine() { }

void Engine::run(){
    sf::RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platform Game", sf::Style::Fullscreen);
    
    currentScreen = &menu;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) {
            window.setFramerateLimit(60);
            if (event.type == sf::Event::Closed) {
                exit(0);
            }
            // Obs³uga klikniêæ myszk¹
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (currentScreen == &menu) {
                    // Sprawdzenie, czy kursor myszki jest nad opcj¹ "play" i czy wcisnieto lewy przycisk myszy
                    if ((menu.isMouseOverPlay()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikniêciu na opcjê "play"
                        currentScreen = &map;
                    }
                    // Analogicznie dla pozosta³ych opcji i czy wcisnieto lewy przycisk myszy
                    else if ((menu.isMouseOverOptions()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikniêciu na opcjê "options" i czy wcisnieto lewy przycisk myszy
                        currentScreen = &options;
                    }
                    else if ((menu.isMouseOverAbout()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikniêciu na opcjê "about" i czy wcisnieto lewy przycisk myszy
                        currentScreen = &about;
                    }
                    else if ((menu.isMouseOverExit()) && (event.mouseButton.button == sf::Mouse::Left))
                    {
                        // Kod do wykonania po klikniêciu na opcjê "exit" i czy wcisnieto lewy przycisk myszy
                        window.close();
                    }
                }
                if (currentScreen == &map && map.getGameOverState() == true) {
                    currentScreen = &endGame;
                }
                if (currentScreen == &endGame) {
                    if ((endGame.isMouseOverBackButton()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        currentScreen = &menu;
                    }
                }
                if (currentScreen == &options) {
                    if ((options.isMouseOverBackButton()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        currentScreen = &menu;
                    }
                }
                if (currentScreen == &about) {
                    if ((about.isMouseOverBackButton()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        currentScreen = &menu;
                    }
                }
            }
        }

        currentScreen->set();
        window.clear();

        menu.updateMousePosition(sf::Mouse::getPosition(window));
        endGame.updateMousePosition(sf::Mouse::getPosition(window));
        options.updateMousePosition(sf::Mouse::getPosition(window));
        about.updateMousePosition(sf::Mouse::getPosition(window));

        currentScreen->draw(window);
        window.display();
    }
}
#include "Engine.h"

Engine::Engine() { }

Engine::~Engine() { }

void Engine::run(){
    sf::RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platform Game", sf::Style::Fullscreen);
    
    int i = 0;
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
                        if (counter > 0) {
                            counter = 0;
                            map.reset();
                        }
                        // Kod do wykonania po klikniêciu na opcjê "play"
                        currentScreen = &map;
                        counter++;
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
                // Kod do wykonania po ukoñczeniu gry
                if (currentScreen == &map && map.getGameOverState() == true && i % 2 == 0) {
                    currentScreen = &endGame;
                    i += 1;
                }

                if (currentScreen == &map && map.getGameOverState() == true && i % 2 == 1) {
                    currentScreen = &map;
                    i += 1;
                    map.reset();
                }
                // Kod do wykonania po klikniêciu na opcjê "menu" i czy wcisnieto lewy przycisk myszy
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
                    if ((about.isMouseOver1Button()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        about.setSpeechBubble(0);
                    }
                    if ((about.isMouseOver2Button()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        about.setSpeechBubble(1);
                    }
                    else if ((about.isMouseOver3Button()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        about.setSpeechBubble(2);
                    }
                    else if ((about.isMouseOver4Button()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        about.setSpeechBubble(3);
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
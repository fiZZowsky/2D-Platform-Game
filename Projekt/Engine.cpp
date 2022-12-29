#include "Engine.h"

Engine::Engine(){
}

Engine::~Engine(){
}

void Engine::run(){
    sf::RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platform Game", sf::Style::Fullscreen);
    
    currentScreen = &menu;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) {
            window.setFramerateLimit(60);
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)) {
                exit(0);
            }
            // Obs³uga klikniêæ myszk¹
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (currentScreen == &menu) {
                    // Sprawdzenie, czy kursor myszki jest nad opcj¹ "play" i czy wcisnieto lewy przycisk myszy
                    if ((menu.isMouseOverPlay()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikniêciu na opcjê "play"
                        map.setMap(window, event);
                    }
                    // Analogicznie dla pozosta³ych opcji i czy wcisnieto lewy przycisk myszy
                    else if ((menu.isMouseOverOptions()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikniêciu na opcjê "options" i czy wcisnieto lewy przycisk myszy
                    }
                    else if ((menu.isMouseOverAbout()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikniêciu na opcjê "about" i czy wcisnieto lewy przycisk myszy
                        currentScreen = &about;
                        if ((about.isMouseOverBackButton()) && (event.mouseButton.button == sf::Mouse::Left)) {
                            currentScreen = &menu;
                        }
                    }
                    else if ((menu.isMouseOverExit()) && (event.mouseButton.button == sf::Mouse::Left))
                    {
                        // Kod do wykonania po klikniêciu na opcjê "exit" i czy wcisnieto lewy przycisk myszy
                        window.close();
                    }
                }
            }
        }

        currentScreen->set();
        window.clear();
        currentScreen->draw(window);
        window.display();
    }
}

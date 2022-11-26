#include "Engine.h"

Engine::Engine(){
	backgroundColor = sf::Color(0, 219, 255);
}

Engine::~Engine(){
}

void Engine::run(){
	sf::RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platform Game");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)) {
                exit(0);
            }

            window.setFramerateLimit(60);
            map.setMap(window, event); 
        }

        window.clear(backgroundColor);
        window.display();
    }
}

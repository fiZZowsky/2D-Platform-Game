#include "Engine.h"

Engine::Engine() { 
    isMusicMuted = false;
}

Engine::~Engine() { }

void Engine::run() {
    sf::RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platform Game", sf::Style::Fullscreen);
    int changeScreen = 0;
    currentScreen = &menu;
    //Uruchomienie muzyki
    m_music.start();


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) {
            window.setFramerateLimit(60);
            if (event.type == sf::Event::Closed) {
                exit(0);
            }
            // Obs?uga klikni?? myszk?
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (currentScreen == &menu) {
                    // Sprawdzenie, czy kursor myszki jest nad opcj? "play" i czy wcisnieto lewy przycisk myszy
                    if ((menu.isMouseOverPlay()) && (event.mouseButton.button == sf::Mouse::Left)) {

                        if (counter > 0) {
                            counter = 0;
                            map.reset();
                        }
                        // Kod do wykonania po klikni?ciu na opcj? "play"
                        currentScreen = &map;
                        counter++;
                    }
                    else if ((menu.isMouseOverAbout()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        // Kod do wykonania po klikni?ciu na opcj? "about" i czy wcisnieto lewy przycisk myszy
                        currentScreen = &about;
                    }
                    else if ((menu.isMouseOverExit()) && (event.mouseButton.button == sf::Mouse::Left))
                    {
                        // Kod do wykonania po klikni?ciu na opcj? "exit" i czy wcisnieto lewy przycisk myszy
                        window.close();
                    }
                    else if ((menu.isMouseOverMute()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        if (isMusicMuted == false) {
                            isMusicMuted = true;
                            m_music.setVolume(0);
                            menu.setMuteButton(isMusicMuted);
                        }
                        else {
                            isMusicMuted = false;
                            m_music.setVolume(100);
                            menu.setMuteButton(isMusicMuted);
                        }
                        
                    }
                }
                //Zatrzymanie odtwarazania muzyki z menu
                if (currentScreen == &map) {
                    m_music.stop();
                }
                // Kod do wykonania po przegranej grze
                if (currentScreen == &map && map.getGameOverState() == true && changeScreen % 2 == 0) {
                    currentScreen = &endGame;
                    changeScreen = 2;
                }

                //Kod do wykonania resetu mapy
                if (currentScreen == &map && map.getGameOverState() == true && changeScreen % 2 == 1) {
                    currentScreen = &endGame;
                    changeScreen = 2;
                    map.reset();
                }

                //Kod do wykonania po wygranej grze
                if (currentScreen == &map && map.Win == true && changeScreen % 2 == 0) {
                    currentScreen = &winGame;
                    changeScreen = 1;
                }

                //Kod do wykonania resetu mapy
                if (currentScreen == &map && map.Win == true && changeScreen % 2 == 1) {
                    currentScreen = &winGame;
                    changeScreen = 1;
                    map.reset();
                }

                //Kod do wykonania po klikni?ciu na opcj? "menu" i czy wci?ni?to lewy przycisk myszy
                if (currentScreen == &winGame) {
                    if ((winGame.isMouseOverBackButton()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        currentScreen = &menu;
                        //Uruchomienie od nowa muzyki z menu
                        m_music.reset();
                    }
                }

                // Kod do wykonania po klikni?ciu na opcj? "menu" i czy wcisnieto lewy przycisk myszy
                if (currentScreen == &endGame) {
                    if ((endGame.isMouseOverBackButton()) && (event.mouseButton.button == sf::Mouse::Left)) {
                        currentScreen = &menu;
                        //Uruchomienie od nowa muzyki z menu
                        m_music.reset();
                    }
                }
                if (currentScreen == &about) {
                    about.reset();
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
        winGame.updateMousePosition(sf::Mouse::getPosition(window));
        endGame.updateMousePosition(sf::Mouse::getPosition(window));
        about.updateMousePosition(sf::Mouse::getPosition(window));

        currentScreen->draw(window);
        window.display();
    }
}
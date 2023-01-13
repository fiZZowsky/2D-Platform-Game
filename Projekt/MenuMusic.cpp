#include "MenuMusic.h"

MenuMusic::MenuMusic() {
	music.openFromFile("Audio/menu_music.ogg");
	isPlaying = false;
	music.setLoop(true);
}

MenuMusic::~MenuMusic() { }

void MenuMusic::start() {
	isPlaying = true;
	music.play();
}

void MenuMusic::stop() {
	isPlaying = false;
	music.stop();
}

void MenuMusic::setVolume(float volume) {
	music.setVolume(volume);
}

void MenuMusic::reset() {
	//Ustawienie pozycji odtwarzania pisenki na pocz¹tek
	music.setPlayingOffset(sf::seconds(0));
	start();
}

#include "Map.h"

void Map::setGoomba() {
    
}

void Map::goombaDie(int i) {
    goomba[i].setTextureRect(IntRect(2 * 16, 0, 16, 16));
    dieenemy[i] = true;
}

void Map::setGoombaPos() {
    for (short i = 0; i < 6; i++) {
        PosEX[i] = goomba[i].getPosition().x;
        PosEY[i] = goomba[i].getPosition().y;
    }
}
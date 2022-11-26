#include "Map.h"

void Map::setCoins(coins) {
    for (size_t i = 0; i < coins.size(); i++)
    {
        coins[i].setScale(0.5, 0.5);
        coins[i].setTexture(cointx);
        if (i == 0) coins[i].setPosition(260, 128);
        if (i == 1) coins[i].setPosition(480, 192);
        if (i == 2) coins[i].setPosition(630, 192);
        if (i == 3) coins[i].setPosition(790, 192);
        if (i == 4) coins[i].setPosition(1240, 192);
        if (i == 5) coins[i].setPosition(1270, 192);
        if (i == 6) coins[i].setPosition(1500, 192);
        if (i == 7) coins[i].setPosition(2490, 192);
        if (i == 8) coins[i].setPosition(2570, 192);
        if (i == 9) coins[i].setPosition(2240, 192);
        if (i == 10) coins[i].setPosition(1270, 64);
        if (i == 11) coins[i].setPosition(1330, 64);
        if (i == 12) coins[i].setPosition(1465, 64);
        if (i == 13) coins[i].setPosition(1970, 64);
        if (i == 14) coins[i].setPosition(2072, 64);
        if (i == 15) coins[i].setPosition(2500, 128);
        if (i == 16) coins[i].setPosition(970, 192);
        if (i == 17) coins[i].setPosition(1593, 126);
        if (i == 18) coins[i].setPosition(2840, 192);
        if (i == 19) coins[i].setPosition(132 * 16, 192);

        coins[i].setTextureRect(IntRect(31, 0, 31, 31));
    }
}

void Map::coinsBonus() {
    BonusCoin[ind].setTexture(BCoin);
}

void Map::drawCoins(RenderWindow& window) {
    for (short i = 0; i < coins.size(); i++) {
        window.draw(coins[i]);
    }
}
#include "Map.h"

Map::Map(){
    //load textures
    mush.loadFromFile("Images/mushroom.png");
    BCoin.loadFromFile("Images/10.png");
    f.loadFromFile("Images/FireFlower.png");
    fi.loadFromFile("Images/Fire.png");
    cointx.loadFromFile("Images/coins.png");

    naarr.setTexture(fi);
    naarr.setPosition(-50, -50);

    //load audio
    CoinSoundEffect.loadFromFile("Audio/coin.wav");
    Break.loadFromFile("Audio/breakblock.wav");
    Firee.openFromFile("Audio/fireball.wav");
    Winner.openFromFile("Audio/stage_clear.wav");

    //load fonts
    font.loadFromFile("font/CollegiateBlackFLF.ttf");

    Win = false;
    firem = false;
    firepos = false;
    mushspawn = false;
    flowerspawn = false;

    ind = 0;
    ann = 0;
    c = 0;
    score = 0;
    AnimationX = 0;
    FireTime = 0;

    MAP.resize(3200);
    coins.resize(20);
}

int level1[] =
{
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,16,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,1,1,1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,5,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,22,24,23,22,24,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,22,24,23,22,24,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,25,26,26,26,26,26,25,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,1,5,1,1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,5,-1,-1,-1,-1,-1,5,-1,-1,-1,5,-1,-1,-1,5,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,-1,-1,-1,4,4,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,23,27,23,27,23,27,23,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,-1,-1,-1,4,4,4,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,4,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,-1,-1,-1,4,4,4,4,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,4,4,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,-1,-1,-1,-1
  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  ,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1,-1,-1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
  ,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1,-1,-1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
};
int level1C[16][200] =
{
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,1,1,1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,5,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,24,23,22,24,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,24,23,22,24,-1,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,26,26,26,26,26,25,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,1,5,1,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,5,-1,-1,-1,-1,-1,5,-1,-1,-1,5,-1,-1,-1,5,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,5,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,-1,-1,-1,4,4,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,27,23,27,23,27,23,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,-1,-1,-1,4,4,4,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,-1,4,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,-1,-1,-1,-1
  ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,-1,-1,-1,4,4,4,4,-1,-1,-1,-1,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,19,4,4,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,-1,-1,-1,-1
  ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  ,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1,-1,-1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
  ,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1,-1,-1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
};

RectangleShape Left(Vector2f(1, 16)), Right(Vector2f(1, 16)), Top(Vector2f(12, 1)), Down(Vector2f(12, 1));

void Map::set() {
    LoadTiles();
    drawLevel(level1);

    for (size_t i = 0; i < coins.size(); i++)
    {
        coins[i].setScale(0.5, 0.5);
        coins[i].setTexture(cointx);
        if (i == 0) coins[i].setPosition(255, 128);
        if (i == 1) coins[i].setPosition(475, 192);
        if (i == 2) coins[i].setPosition(625, 192);
        if (i == 3) coins[i].setPosition(785, 192);
        if (i == 4) coins[i].setPosition(1235, 192);
        if (i == 5) coins[i].setPosition(1265, 192);
        if (i == 6) coins[i].setPosition(1495, 192);
        if (i == 7) coins[i].setPosition(2485, 192);
        if (i == 8) coins[i].setPosition(2565, 192);
        if (i == 9) coins[i].setPosition(2235, 192);
        if (i == 10) coins[i].setPosition(1265, 64);
        if (i == 11) coins[i].setPosition(1325, 64);
        if (i == 12) coins[i].setPosition(1460, 64);
        if (i == 13) coins[i].setPosition(1965, 64);
        if (i == 14) coins[i].setPosition(2067, 64);
        if (i == 15) coins[i].setPosition(2495, 128);
        if (i == 16) coins[i].setPosition(965, 192);
        if (i == 17) coins[i].setPosition(1588, 126);
        if (i == 18) coins[i].setPosition(2835, 192);
        if (i == 19) coins[i].setPosition(2108, 192);

        coins[i].setTextureRect(IntRect(31, 0, 31, 31));
    }

    // score text //
    text.setFont(font);
    text.setString("score : " + std::to_string(score));
    text.setPosition(5, -1);
    text.setCharacterSize(12);

    ///////     gomba    /////////
    for (size_t i = 0; i < 6; i++)
    {
        EnemySpeed[i].x = 1.f;
    }

    g.loadFromFile("Images/Goomba.png");

    for (size_t i = 0; i < 6; i++)
    {
        goomba[i].setTexture(g);
        if (i == 0) goomba[i].setPosition(28 * 16, 192);
        if (i == 1) goomba[i].setPosition(38 * 16, 192);
        if (i == 2) goomba[i].setPosition(49 * 16, 192);
        if (i == 3) goomba[i].setPosition(132 * 16, 192);
        if (i == 4) goomba[i].setPosition(140 * 16, 192);
        if (i == 5) goomba[i].setPosition(163 * 16, 192);
        goomba[i].setTextureRect(IntRect(0 * 16, 0, 16, 16));
    }

    for (size_t i = 0; i < 6; i++) {
        dieenemy[i] = false;
    }

    for (size_t i = 0; i < 6; i++) {
        counter[i] = 0;
    }
    player.setPlayer();
};

void Map::draw(RenderWindow& window) {
    window.clear(BACKGROUND_COLOR);
    setMap(window);
}

void Map::setMap(RenderWindow& window) {
    //////camera////////
    View camera(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 256.0f));
    if (player.getPosition().x <= 255) {
        camera.setCenter(255.f, 128.f);
    }
    else {
        camera.setCenter(player.getPosition());
    }
    
    while (window.isOpen()) {
        if (player.getPosition().x >= 182 * 16) {
            Win = true;
            Winner.play();
        }
        player.velocity.x = 0;

        if (Keyboard::isKeyPressed(Keyboard::A)) {
            player.velocity.x = -1;
            player.LookingRight = false;
            player.LookingLeft = true;

            player.updateTexture(AnimationX);

            if (frame_speed.getElapsedTime().asSeconds() > 0.09)
            {
                AnimationX++;
                frame_speed.restart();
            }
            player.player.setOrigin(player.player.getLocalBounds().width, 0);
            player.player.setScale(-0.5, 0.5);

        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            player.velocity.x = 1;
            player.LookingRight = true;
            player.LookingLeft = false;

            player.updateTexture(AnimationX);

            if (frame_speed.getElapsedTime().asSeconds() > 0.09)
            {

                AnimationX++;
                frame_speed.restart();

            }
            player.reset();
        }
        if (Keyboard::isKeyPressed(Keyboard::W) && player.jumping == false) {

            player.velocity.y = -10.7;
            sound.setBuffer(player.Jump);
            sound.play();
        }
        player.jumping = true;

        bool Stuck = 0;

        if (player.getPosition().y < 5)
            player.velocity.y = 0;
        for (int i = 0; i < 3200; i++)
        {
            if (Down.getGlobalBounds().intersects(MAP[i].getGlobalBounds()) && player.velocity.y >= 0 && (level1[i] != -1 && !(level1[i] >= 12 && level1[i] <= 17) && level1[i] != 29)) {
                player.velocity.y = 0;
                player.jumping = false;
            }
            else if (Top.getGlobalBounds().intersects(MAP[i].getGlobalBounds()) && player.velocity.y < 0 && (level1[i] != -1 && !(level1[i] >= 12 && level1[i] <= 17) && level1[i] != 29)) {
                player.velocity.y = 0;

                if (level1[i] == 5) {
                    if (i == 1812) {
                        if (!mushspawn) {
                            mushroom.setPosition(193, 132);
                            mushroom.setScale(0.8, 0.8);
                            mushroom.setTexture(mush);
                            mushspawn = true;
                        }
                    }
                    else if (i == 1910) {
                        if (!flowerspawn) {
                            flower.setPosition(1760, 132);
                            flower.setScale(0.8, 0.8);
                            flower.setTexture(f);
                            flowerspawn = true;
                        }
                    }
                    else {
                        BonusCoin[ind].setTexture(BCoin);
                        BonusCoin[ind].setPosition(MAP[i].getPosition().x, MAP[i].getPosition().y - MAP[i].getSize().y - 2);
                        ind++;
                    }
                    MAP[i].setTexture(&Tiles[8]);
                    level1[i] = 8;
                }
                if (level1[i] == 1 && (player.big_mario || player.marioburn)) {
                    MAP[i].setTexture(&Tiles[30]);
                    level1[i] = -1;
                    sound.setBuffer(Break);
                    sound.play();
                }
            }

            if (Right.getGlobalBounds().intersects(MAP[i].getGlobalBounds()) && player.velocity.x > 0 && (level1[i] != -1 && !(level1[i] >= 12 && level1[i] <= 17) && level1[i] != 29)) {
                player.velocity.x = 0;
            }
            if (Left.getGlobalBounds().intersects(MAP[i].getGlobalBounds()) && player.velocity.x < 0 && (level1[i] != -1 && !(level1[i] >= 12 && level1[i] <= 17) && level1[i] != 29)) {
                player.velocity.x = 0;
            }
            if (Left.getGlobalBounds().intersects(MAP[i].getGlobalBounds()) && (level1[i] != -1 && !(level1[i] >= 12 && level1[i] <= 17) && level1[i] != 29))
            {
                Stuck = 1;
            }
            if (Right.getGlobalBounds().intersects(MAP[i].getGlobalBounds()) && (level1[i] != -1 && !(level1[i] >= 12 && level1[i] <= 17) && level1[i] != 29))
            {
                if (Stuck == 1 && player.velocity.y == 0) { player.player.move(0, -2);  Stuck = 0; }
            }
        }
        if (player.velocity.y < 3.3 && player.jumping)
            player.velocity.y += player.gravity;

        setGoombaPos();

        //Camera 
        if (camera.getCenter().x >= 260) {
            if (player.velocity.x < 0) {
                if (player.getPosition().x >= 250 && player.getPosition().x <= 2950) {
                    camera.move(player.velocity.x * player.speed, 0.f);
                    text.move(player.velocity.x * player.speed, 0);
                }
            }
        }
        if (camera.getCenter().x <= 2940) {
            if (player.velocity.x > 0) {
                if (player.getPosition().x >= 250 && player.getPosition().x <= 2950) {
                    camera.move(player.velocity.x * player.speed, 0.f);
                    text.move(player.velocity.x * player.speed, 0);
                }
            }
        }

        ////////////////
        for (size_t i = 0; i < 6; i++) {

            if (!dieenemy[i]) {
                goomba[i].move(EnemySpeed[i].x, EnemySpeed[i].y);
                if (!ECBottom[i]) EnemySpeed[i].y += player.gravity;
            }
            if (frame_speed.getElapsedTime().asSeconds() > 0.2 && !dieenemy[i])
            {
                frame_speed.restart();

                if (GoombaAnimator == 0)
                {
                    GoombaAnimator++;
                }
                else
                    GoombaAnimator--;
            }
            if (!dieenemy[i]) goomba[i].setTextureRect(IntRect(GoombaAnimator * 16, 0, 16, 16));
        }

        for (size_t i = 0; i < 6; i++)
        {
            EnemyMoveLeft[i] = 0;
            EnemyMoveRight[i] = 0;
        }

        for (size_t i = 0; i < 6; i++)
        {
            int ExLeft = ((goomba[i].getPosition().x) + 16) / 16, ExRight = ((goomba[i].getPosition().x)) / 16, EyGround = ((goomba[i].getPosition().y)) / 16, EyTop = ((goomba[i].getPosition().y)) / 16, EyBot = ((goomba[i].getPosition().y) + 9) / 16, Ex = ((goomba[i].getPosition().x)) / 16;
            if ((level1C[EyGround + 1][ExLeft] >= 0 || level1C[EyGround + 1][ExRight] >= 0)) { //Ground Standing
                goomba[i].setPosition(PosEX[i], PosEY[i]);
                EnemySpeed[i].y = 0;
                goomba[i].move(EnemySpeed[i].x, EnemySpeed[i].y);
                ECBottom[i] = true;
            }
            else ECBottom[i] = false;

            if ((level1C[EyGround][ExLeft] >= 0 || level1C[EyGround][ExRight] >= 0)) {//Colliding from below a tile
                goomba[i].setPosition(PosEX[i], PosEY[i]);
                EnemySpeed[i].y = 0;
                goomba[i].move(EnemySpeed[i].x, EnemySpeed[i].y);

                ECTop[i] = true;
            }
            else ECTop[i] = false;
            if (level1C[EyTop][Ex + 1] >= 0) {

                EnemyMoveRight[i] = true;
            }
            if (level1C[EyTop][Ex] >= 0) {
                EnemyMoveLeft[i] = true;
            }
            if (EnemyMoveRight[i])
            {
                EnemyMoveRight[i] = 0;
                EnemySpeed[i].x = -1 * EnemySpeed[i].x;
            }
            if (EnemyMoveLeft[i])
            {
                EnemyMoveLeft[i] = 0;

                EnemySpeed[i].x = -1 * EnemySpeed[i].x;
            }
        }
        //Collision screen
        player.checkCollision();
        for (int i = 0; i < ind; i++) {

            if (player.player.getGlobalBounds().intersects(BonusCoin[i].getGlobalBounds())) {
                score += 3;

                BonusCoin[i].setPosition(-1000, -1000);
                sound.setBuffer(CoinSoundEffect);
                sound.play();
            }
        }

        for (size_t i = 0; i < 6; i++) {

            if (goomba[i].getPosition().y > 14 * 16) {
                goombafall[i] = 1;
                dieenemy[i] = 1;
            }

            if ((player.player.getGlobalBounds().intersects(goomba[i].getGlobalBounds()) && player.velocity.y != 0 && !player.mariodie) || goombafall[i])
            {
                goombaDie(i);
            }
            if (dieenemy[i] && counter[i] < 16)
            {
                if (!goombafall[i] && !(naarr.getGlobalBounds().intersects(goomba[i].getGlobalBounds()))) {
                    player.player.move(0, -7);
                }
                counter[i]++;
                EnemySpeed[i].x = 0;
                window.draw(goomba[i]);
            }
        }

        for (size_t i = 0; i < 6; i++) {

            if (dieenemy[i] && !ScoreEnemy[i]) { score++; ScoreEnemy[i] = 1; }
        }


        for (size_t i = 0; i < 6; i++)
        {

            if (player.player.getGlobalBounds().intersects(goomba[i].getGlobalBounds()) && player.velocity.y == 0 && !dieenemy[i] || player.getPosition().y > 13 * 16)
            {
                if (player.big_mario || player.marioburn) {

                    if (player.getPosition().y > 13 * 16)
                        player.player.setPosition(1098.64, 192);
                    else
                    {
                        if (EnemySpeed[i].x > 0)
                        {
                            player.player.move(5, 0);
                            EnemySpeed[i].x = -1 * EnemySpeed[i].x;
                        }
                        else
                        {
                            player.player.move(-5, 0);
                            EnemySpeed[i].x = -1 * EnemySpeed[i].x;
                        }
                    }

                    player.mariodie = false;
                    player.big_mario = false;
                    player.marioburn = false;
                    player.player.setTexture(player.t);
                    player.player.setTextureRect(IntRect(0, 0, player.t.getSize().x / 7, player.t.getSize().y));
                }

                else {
                    player.player.setTextureRect(IntRect(32 * 6, 0, 32, 32));
                    player.mariodie = true;
                }

            }
            /*if (player.mariodie && player.countmario < 500)
            {
                player.countmario++;
                window.draw(player.player);
            }*/
        }

        if (player.mariodie) {

            if (!player.DeathSound) {
                player.MarioDeath.play();
                player.DeathSound = true;
            }
            player.updateTexture(AnimationX);
            player.player.move(0, -10);
        }


        for (size_t i = 0; i < coins.size(); i++) {
            if (player.player.getGlobalBounds().intersects(coins[i].getGlobalBounds())) {
                sound.setBuffer(CoinSoundEffect);
                sound.play();
                coins[i].setScale(0, 0);
                score++;
            }
        }


        for (size_t i = 0; i < coins.size(); i++) {

            if (animation.getElapsedTime().asSeconds() > 0.05) {
                c++;
                animation.restart();
            }
            coins[i].setTextureRect(IntRect(c * 31, 0, 31, 31));
        }

        c = c % 7;

        /////   big mario     //////

        if (player.player.getGlobalBounds().intersects(mushroom.getGlobalBounds()))
        {
            sound.setBuffer(player.PowerUp);
            sound.play();
            player.big_mario = true;
            mushroom.setScale(0, 0);
            firem = false;
            naarr.setPosition(-5, -5);
        }

        if (player.big_mario) {
            player.updateTexture(AnimationX);
        }
        else window.draw(mushroom);


        /// super mario ////

        if (player.player.getGlobalBounds().intersects(flower.getGlobalBounds())) {
            sound.setBuffer(player.PowerUp);
            sound.play();
            player.marioburn = true;
            flower.setScale(0, 0);
        }

        if (player.marioburn) {
            player.updateTexture(AnimationX);
        }
        else
            window.draw(flower);

        ////   fire   ////
        if (Mouse::isButtonPressed(sf::Mouse::Left) && player.marioburn)
        {
            firem = true;
        }

        if (firem)
        {
            if (!firepos) {
                naarr.setPosition(player.getPosition().x, player.getPosition().y + 8); firepos = true;
                Firee.play();
            }
            naarr.setTextureRect(IntRect(4 * 16, 0, 16, 16));
            naarr.setScale(1, 1);

            if (player.LookingRight && !player.SightR && !player.SightL) {
                player.SightR = true;
            }
            if (player.SightR)
                naarr.move(ann, 0);
            if (player.LookingLeft && !player.SightL && !player.SightR) {
                player.SightL = true;
            }
            if (player.SightL)
                naarr.move(-ann, 0);
            if (ann < 6) ann++;
            FireTime++;
        }

        for (size_t i = 0; i < 6; i++) {
            if (naarr.getGlobalBounds().intersects(goomba[i].getGlobalBounds()) || FireTime >= 100)
            {
                if (naarr.getGlobalBounds().intersects(goomba[i].getGlobalBounds())) dieenemy[i] = true;
                firem = false;
                firepos = false;
                player.SightL = false;
                player.SightR = false;
                ann = 0;
                FireTime = 0;
            }
        }
        text.setString("score: " + std::to_string(score));  //Displays Score

        player.player.move(player.velocity.x * player.speed, player.velocity.y);

        if (player.big_mario || player.marioburn) {
            Left.setScale(1, 2);
            Right.setScale(1, 2);
            Down.setPosition(player.getPosition().x + 3, player.getPosition().y + 32);
        }
        else {
            Left.setScale(1, 1);
            Right.setScale(1, 1);
            Down.setPosition(player.getPosition().x + 3, player.getPosition().y + 16);
        }
        Left.setPosition(player.getPosition().x, player.getPosition().y - 1);
        Right.setPosition(player.getPosition().x + 16, player.getPosition().y - 1);
        Top.setPosition(player.getPosition().x + 3, player.getPosition().y);

        //Handlying animations 
        if (player.jumping) {
            player.updateTexture(AnimationX);
        }
        else if (player.velocity.x != 0)
        {
            AnimationX %= 4;
            player.updateTexture(AnimationX);
        }
        else {
            player.updateTexture(AnimationX);
        }

        ///////////////
        if (Win == true || player.mariodie == 1)
        {
            std::ifstream readFile;
            readFile.open("data.txt");
            if (readFile.is_open()) {
                readFile >> _score >> _highscore;
            }
            readFile.close();

            if (score > _highscore) {
                _highscore = score;
            }
            std::ofstream writeFile("data.txt");
            if (writeFile.is_open()) {
                writeFile << score << " " << _highscore;
            }
            writeFile.close();

            break;
        }
        
        text.setString("score: " + std::to_string(score));  //Displays Score

        window.setView(camera);
        // draw the map
        window.clear();
        for (int i = 0; i < 3200; i++) {
            window.draw(MAP[i]);
        }

        for (int i = 0; i < ind; i++) {

            window.draw(BonusCoin[i]);
        }
        window.draw(player.player);

        // draw goomba
        for (size_t i = 0; i < 6; i++) {
            if (counter[i] < 16) {
                window.draw(goomba[i]);
            }
        }
        // draw coins
        for (short i = 0; i < coins.size(); i++) {
            window.draw(coins[i]);
        }
        // draw text
        window.draw(text);
        window.draw(mushroom);
        window.draw(flower);
        if (firem && player.marioburn) {
            window.draw(naarr);
        }
        window.display();
    }
    setGameOverState(true);
    window.setView(window.getDefaultView());
}

void Map::LoadTiles() {

    Tiles[0].loadFromFile("Images/Ground.png");
    Tiles[1].loadFromFile("Images/Breakable.png");
    Tiles[2].loadFromFile("Images/3.png");
    Tiles[3].loadFromFile("Images/4.png");
    Tiles[4].loadFromFile("Images/5.png");
    Tiles[5].loadFromFile("Images/quest.png");
    Tiles[6].loadFromFile("Images/7.png");
    Tiles[7].loadFromFile("Images/8.png");
    Tiles[8].loadFromFile("Images/9.png");
    Tiles[9].loadFromFile("Images/10.png");
    Tiles[10].loadFromFile("Images/11.png");
    Tiles[11].loadFromFile("Images/12.png");
    Tiles[12].loadFromFile("Images/13.png");
    Tiles[13].loadFromFile("Images/14.png");
    Tiles[14].loadFromFile("Images/15.png");
    Tiles[15].loadFromFile("Images/16.png");
    Tiles[16].loadFromFile("Images/17.png");
    Tiles[17].loadFromFile("Images/18.png");
    Tiles[18].loadFromFile("Images/19.png");
    Tiles[19].loadFromFile("Images/20.png");
    Tiles[20].loadFromFile("Images/21.png");
    Tiles[21].loadFromFile("Images/22.png");
    Tiles[22].loadFromFile("Images/23.png");
    Tiles[23].loadFromFile("Images/24.png");
    Tiles[24].loadFromFile("Images/25.png");
    Tiles[25].loadFromFile("Images/26.png");
    Tiles[26].loadFromFile("Images/27.png");
    Tiles[27].loadFromFile("Images/28.png");
    Tiles[28].loadFromFile("Images/29.png");
    Tiles[29].loadFromFile("Images/30.png");
    Tiles[30].loadFromFile("Images/sky.png");
}

void Map::drawLevel(int arr[]) {
    for (int i = 0; i < 3200; i++) {

        MAP[i].setSize(Vector2f(16, 16));
        if (arr[i] != -1)
            MAP[i].setTexture(&Tiles[arr[i]]);
        else MAP[i].setFillColor(sf::Color(148, 148, 255));

        MAP[i].setPosition((i % 200) * 16, (i / 200) * 16);
    }
}

void Map::setGameOverState(bool state) {
    gameOver = state;
}

bool Map::getGameOverState() {
    return gameOver;
}

int Map::getScore()
{
    return score;
}

void Map::reset() {
    //load textures
    mush.loadFromFile("Images/mushroom.png");
    BCoin.loadFromFile("Images/10.png");
    f.loadFromFile("Images/FireFlower.png");
    fi.loadFromFile("Images/Fire.png");
    cointx.loadFromFile("Images/coins.png");

    naarr.setTexture(fi);
    naarr.setPosition(-50, -50);

    //load audio
    CoinSoundEffect.loadFromFile("Audio/coin.wav");
    Break.loadFromFile("Audio/breakblock.wav");
    Firee.openFromFile("Audio/fireball.wav");
    Winner.openFromFile("Audio/stage_clear.wav");

    //load fonts
    font.loadFromFile("font/CollegiateBlackFLF.ttf");

    Win = false;
    firem = false;
    firepos = false;
    mushspawn = false;
    flowerspawn = false;

    ind = 0;
    ann = 0;
    c = 0;
    score = 0;
    AnimationX = 0;
    FireTime = 0;

    // Default nothing map
    MAP.resize(3200);
    coins.resize(20);

    for (int i = 0; i < 3200; i++) {
        level1[i] = -1;
    }

    // Load map from file
    std::ifstream inFile("level.txt");
    std::string line;
    int count = 0;
    
    while (!inFile.eof())
    {
        std::getline(inFile, line, ',');

        std::stringstream ss(line);
        int value;

        ss >> value;
        level1[count] = value;
        count++;
    }

    inFile.close();
    
    player.mariodie = false;
    player.big_mario = false;
    player.marioburn = false;
    set();
};
#pragma once

#include "Headers.h"
#include "Settings.h"
#include "Player.h"
#include "ScreenManager.h"

using namespace std;
using namespace sf;

class Map : public ScreenManager {
public:
	Map();

    void set() override;
    void draw(sf::RenderWindow& window) override;
	void setMap(RenderWindow& window);
	void drawLevel(int arr[]);
    void LoadTiles();
    void setGameOverState(bool state);
    bool getGameOverState();
    int getScore();
    void reset();

private:
    vector <RectangleShape> MAP;
    vector <Sprite> coins;

    //Sounds
    SoundBuffer CoinSoundEffect;
    SoundBuffer Break;
    Sound sound;
    Music Firee;
    Music Winner;

    //Texts
    Text text;
    Text endText;

    //Fonts
    Font font;

    //Textures
    Texture Tiles[200];     //map
    Texture mush;
    Texture BCoin;
    Texture f;              //flower
    Texture fi;             //fire
    Texture cointx;         //coin
    Texture g;              //Goomba

    //Sprites
    Sprite mushroom;
    Sprite BonusCoin[13];
    Sprite flower;
    Sprite naarr;           //Fire
    Sprite goomba[6];

    //bool
    bool firem;
    bool Win;
    bool mushspawn;
    bool flowerspawn;
    bool dieenemy[6];
    bool ECBottom[6], ECTop[6], goombafall[6];
    bool ScoreEnemy[6];
    bool firepos;
    bool EnemyMoveRight[6], EnemyMoveLeft[6];
    bool gameOver;

    int counter[6];
    int AnimationX;
    int ind;
    int FireTime;
    int ann;
    int c;
    int score;
    float PosEX[6], PosEY[6];
    short GoombaAnimator;

    int _score;
    int _highscore;
    
    //functions
    View camera;
    Clock frame_speed;
    Clock animation;
    Vector2f EnemySpeed[6];

    //objects
    Player player;

    //methods
    void setGoomba();
    void goombaDie(int i);
    void setGoombaPos();
};
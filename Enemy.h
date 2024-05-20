#pragma once
#include <SFML/Graphics.hpp>
#include "Bomb.h"


using namespace sf;

class Enemy {
public:
    Sprite EnemySprite;
    Bomb* projectile;
    Texture bombTex;
    bool isAlive = true;
    Clock clock; // Add a clock member variable
    int ScoreOnDeath; // A data member to keep track of the score that the player gets when they destroy the invader.
        
    virtual float getTimeDelay() { return 0.0f; }

    virtual void attack(Player* p) = 0;

    void resetBombTimer() {
        clock.restart();
    }

    Time getTimeSinceLastBomb() const {
        return clock.getElapsedTime();
    }
};
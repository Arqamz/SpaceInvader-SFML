#pragma once
#include <SFML/Graphics.hpp>
#include "vectorCoordinates.h"
#include "player.h"

using namespace sf;

class Bomb {
public:
    Texture tex1;
    Sprite Bsprite;
    float speed;

    Bomb(std::string tex_path, float bombSpeed) : speed(bombSpeed) // Random Meteor
    {
        tex1.loadFromFile(tex_path);
        Bsprite.setTexture(tex1);
        VectorCoordinate pos;
        pos.x = rand() % (800 - int(Bsprite.getGlobalBounds().width));
        pos.y = -Bsprite.getGlobalBounds().height;
        Bsprite.setPosition(pos.x, pos.y);
    }    

    Bomb(std::string tex_path, float bombSpeed, float X, float Y) : speed(bombSpeed) // Invader 
    {
        Bsprite.setPosition(X, Y);
        tex1.loadFromFile(tex_path);
        Bsprite.setTexture(tex1);
    }

    // IF CALLED AS METEOR FROM GAME LOOP
    void fireBomb(float X, float Y, Player* p)
    {
        Bsprite.setPosition(X, Y);
        float delta_x = 0, delta_y = 1;
        delta_y *= speed;
        Bsprite.move(delta_x, delta_y);
        float posX = Bsprite.getPosition().x;
        float posY = Bsprite.getPosition().y;

        if (posY > 800 || checkCollision(Bsprite, p->sprite)) {
            // Reset the bomb if it goes off-screen or collides with playerShip
            posX = rand() % (800 - int(Bsprite.getGlobalBounds().width));
            posY = -(rand() % 800 + Bsprite.getGlobalBounds().height);
            Bsprite.setPosition(posX, posY);
        }
    }

    // IF CALLED FROM INVADER
    void fireBomb(float X, float Y, Player* p, Sprite invader)
    {
        //Bsprite.setPosition(X, Y);
        float delta_x = 0, delta_y = 1;
        delta_y *= speed;
        Bsprite.move(delta_x, delta_y);
        float posX = Bsprite.getPosition().x;
        float posY = Bsprite.getPosition().y;
        std::srand(std::time(0));
        // Generate random number between 800 and 2400
        int lowerBound = std::rand() % 801 + 1600;

        if (posY > lowerBound) {
            // Reset the bomb if it goes off-screen or collides with playerShip
            posX = invader.getPosition().x + invader.getGlobalBounds().width / 2;
            posY = invader.getPosition().y;
            Bsprite.setPosition(posX, posY);
        }
        if (checkCollision(Bsprite, p->sprite)) {
            std::cout << "BOMB COLLIDED WITH PLAYER" << std::endl;
            if (p->powerUpShieldTurrents) {
                // Reset the bomb if it collides with playerShip and player has shield turrets power-up
                posX = invader.getPosition().x + invader.getGlobalBounds().width / 2;
                posY = invader.getPosition().y;
                Bsprite.setPosition(posX, posY);
            }
            else {
                posX = invader.getPosition().x + invader.getGlobalBounds().width / 2;
                posY = invader.getPosition().y;
                Bsprite.setPosition(posX, posY);
                p->Lives--; // Decrement lives after resetting the bomb's position
            }
        }
    }


    bool checkCollision(Sprite sprite1, Sprite sprite2) {
        // Get the global bounds of the sprites
        FloatRect rect1 = sprite1.getGlobalBounds();
        FloatRect rect2 = sprite2.getGlobalBounds();

        // Check if the bounding boxes of the sprites intersect
        if (rect1.intersects(rect2)) {
            // Check if the x and y coordinates of the sprites overlap
            float x1 = sprite1.getPosition().x;
            float y1 = sprite1.getPosition().y;
            float x2 = sprite2.getPosition().x;
            float y2 = sprite2.getPosition().y;
            float width1 = rect1.width;
            float height1 = rect1.height;
            float width2 = rect2.width;
            float height2 = rect2.height;

            if (x1 < x2 + width2 && x1 + width1 > x2 &&
                y1 < y2 + height2 && y1 + height1 > y2) {
                return true;
            }
        }
        return false;
    }

    void updatePosition(Sprite invader) {
        float posX, posY;
        posX = invader.getPosition().x + invader.getGlobalBounds().width / 2;
        posY = invader.getPosition().y;
        Bsprite.setPosition(posX, posY);
    }

};

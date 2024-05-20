#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class Bullet {
public:
    Texture tex1;
    Sprite Bsprite;
    float speed = 6;


    Bullet() {}

    Bullet(Sprite ship)
    {
        tex1.loadFromFile("img/PNG/Lasers/laserBlue07.png");
        Bsprite.setTexture(tex1);
        Vector2f pos;
        pos.x = ship.getPosition().x + ship.getGlobalBounds().width / 2;
        pos.y = ship.getPosition().y;
        Bsprite.setPosition(pos);
        //sprite.setScale(0.75, 0.75);
    }

    void updateTex(std::string pathUpdatedTex) {
        tex1.loadFromFile(pathUpdatedTex);
        Bsprite.setTexture(tex1);
    }

    void fire(Sprite ship)
    {
        float delta_x = 0, delta_y = -1;
        delta_y *= speed;
        Bsprite.move(delta_x, delta_y);
        float posX = Bsprite.getPosition().x;
        float posY = Bsprite.getPosition().y;
        
        if (posY < 0) {
            // Wrap the bullet back to the top of the screen
            posX = ship.getPosition().x + ship.getGlobalBounds().width / 2;
            posY = ship.getPosition().y;
            Bsprite.setPosition(posX, posY);
        }
    }

};
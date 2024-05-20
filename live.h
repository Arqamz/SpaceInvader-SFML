#pragma once
#include "addOns.h"

class Lives : public AddOn {
	//Texture tex; // Loads texture
	//Sprite icon; // Loads sprite
	//float speed = 5.0f; // Const for all objects

public:

    Lives(std::string texture_path) {
        tex.loadFromFile(texture_path);
        icon.setTexture(tex);
        float posX = rand() % (800 - int(icon.getGlobalBounds().width));
        float posY = -(rand() % 3000 + 800);
        icon.setPosition(posX, posY);
    }

    void dropAddOn() {
        float delta_x = 0, delta_y = 1;
        delta_y *= speed;
        icon.move(delta_x, delta_y);
        std::srand(std::time(0));
        // Generate random number between 800 and 2400 (like a delay)
        int lowerBound = std::rand() % 801 + (rand() % 801 + 1600);
        float posX = icon.getPosition().x;
        float posY = icon.getPosition().y;
        if (posY > lowerBound) {
            // Reset the bomb if it goes off-screen
            posX = rand() % (800 - int(icon.getGlobalBounds().width));
            posY = -(rand() % 800 + icon.getGlobalBounds().height);
            icon.setPosition(posX, posY);
        }
    }
};
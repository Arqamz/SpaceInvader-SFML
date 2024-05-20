#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>


using namespace sf;

class AddOn { //Abstract Parent class
public:
	Texture tex; // Loads texture
	Sprite icon; // Loads sprite
	float speed = 1.0f; // Const for all objects

	virtual void dropAddOn() = 0;

	// CALL FOR COLLISION IN MAIN GAME 
};

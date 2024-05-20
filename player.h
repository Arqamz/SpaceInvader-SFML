#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullet.h"

using namespace sf;

class Player{
public:
	Texture tex;
	Sprite sprite;
	float speed=0.9f;
	int x,y;
	Bullet* myBullet;
	Bullet* powerUp;
	bool passThrough;
	bool powerUpShieldTurrents;
	int Lives;

	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x=340.0f;y=700.0f;
		sprite.setPosition(x,y);
		sprite.setScale(0.75f,0.75f);
		myBullet = new Bullet(sprite);
		passThrough = false;
		powerUpShieldTurrents = false;
		Lives = 3;
	}

	void fire()
	{
		myBullet->fire(sprite);
	}

	void move(std::string s)
	{
		float delta_x=0,delta_y=0;
		if (s == "l")
			delta_x = -1;
		else if (s == "r")
			delta_x = 1;
		if(s=="u")
			delta_y=-1;
		else if(s=="d")
			delta_y=1;

		delta_x*=speed;
		delta_y*=speed;

		sprite.move(delta_x, delta_y);
	}

	void rotate_diagonally(float angle)
	{
		// Convert the angle to radians
		angle = angle * (3.14159265358979323846 / 180);

		// Calculate the increment values for X and Y positions
		float x_increment = cos(angle) * speed;
		float y_increment = sin(angle) * speed;

		// Update the position of the sprite in small increments
		sprite.setPosition(sprite.getPosition().x + x_increment, sprite.getPosition().y + y_increment);
	}

	// PowerUp, Fire, Danger, Live
	void PowerUp() {
		powerUpShieldTurrents = true;
		return;
	}
	void FireBullet(){
		myBullet->updateTex("img/PNG/Lasers/laserRed12.png");
		passThrough = true;
	}
	void Danger() {
		Lives--;
		return;
	}
	void LifeAddOn() {
		Lives++;
		return;
	}

};


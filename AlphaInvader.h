#pragma once
#include "Invader.h"

class AlphaInvader : public Invader {
public:
	float BombAttackSpeed; //Speed of bomb dropping (faster speed is more difficult)
	
	AlphaInvader(std::string BombtexPath){
		BombAttackSpeed = 1.0f;
		ScoreOnDeath = 10;
		projectile = new Bomb(BombtexPath, BombAttackSpeed, EnemySprite.getPosition().x, EnemySprite.getPosition().y);
	}

	// PURE VIRTUAL FROM PARENT CLASS TO DEFINE 
	void attack(Player* p) override {
		float invaderX = EnemySprite.getPosition().x;
		float invaderY = EnemySprite.getPosition().y;
		projectile->fireBomb(invaderX, invaderY, p, EnemySprite);
		resetBombTimer(); // Reset the bomb timer after firing
	}

	float getTimeDelay() override
	{
		srand(time(nullptr));
		float minDelay = 15.0f;
		float maxDelay = 20.0f;
		float delay = minDelay + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxDelay - minDelay)));
		return delay;
	}
};

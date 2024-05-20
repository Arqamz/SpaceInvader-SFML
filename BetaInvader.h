#pragma once
#include "Invader.h"

class BetaInvader : public Invader {
public:
	float BombAttackSpeed; //Speed of bomb dropping (faster speed is more difficult)

	BetaInvader(std::string BombtexPath) {
		BombAttackSpeed = 0.5f;
		const float FALL_DELAY = 2000.0f;
		ScoreOnDeath = 20;
		projectile = new Bomb(BombtexPath, BombAttackSpeed, this->EnemySprite.getPosition().x, this->EnemySprite.getPosition().y);
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
		float minDelay = 8.0f;
		float maxDelay = 15.0f;
		float delay = minDelay + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxDelay - minDelay)));
		return delay;
	}
};

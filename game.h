#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "vectorCoordinates.h"
#include "player.h"
#include "Level.h"

#include "powerUp.h"
#include "fire.h"
#include "danger.h"
#include "live.h"
#include "scores.h"

const char title[] = "OOP-Project, Spring-2023";

using namespace std;
using namespace sf;

class Game
{
public:
    Sprite background;
    Texture bg_texture;
    VectorCoordinate bg_position1; // top instance of background image
    VectorCoordinate bg_position2; // bottom instance of background image
    Player* p;

    bool firing;
    float timer;
    bool isLeftPressed;
    bool isRightPressed;

    Texture shipTexture;
    Texture shipTextureRight;
    Texture shipTextureLeft;

    Texture Level;
    Texture Stage;
    Texture lives;

    Texture shield;
    Sprite sheildSprite;

    Sprite LevelSprite;
    Sprite StageSprite;
    Sprite livesSprite;
    Texture lifeTexture;
    Sprite lifePillsSprite;

    Text stageprint;

    Levels* level;

    AddOn** AddOns = new AddOn * [4]; // PowerUp, Fire, Danger, Live

    int PlayerScore;

    Font font;
    Text scoreText;

    SoundBuffer powerUp;
    SoundBuffer health;
    SoundBuffer danger;
    SoundBuffer crashed;
    SoundBuffer HitEnemy;
    SoundBuffer bgMusc;
    
    SoundBuffer fireBullet;
    Sound fireBulletsound;

    Sound PowerUpsound;
    Sound healthsound;
    Sound dangersound;
    Sound crashedsound;
    Sound HitEnemysound;
    Music backgroundMusic;
    
    //SoundBuffer GameOver;
    //SoundBuffer WonGame;



    
    Game()
    {
        p = new Player("img/player_ship.png");
        level = new Levels();
        bg_texture.loadFromFile("img/backgroundRepeat.png");
        background.setTexture(bg_texture);
        background.setScale(1, 1);
        firing = false;
        timer = 0;
        isLeftPressed = false;
        isRightPressed = false;
        shipTexture.loadFromFile("img/player_ship.png");
        shipTextureRight.loadFromFile("img/player_ship_rotateRight.png");
        shipTextureLeft.loadFromFile("img/player_ship_rotateLeft.png");
        p->sprite.setTexture(shipTexture);
        bg_position1 = VectorCoordinate(0, 0);
        bg_position2 = VectorCoordinate(0, bg_texture.getSize().y);
        PlayerScore = 0;

        AddOns[0] = new PowerUp("img/PNG/Power-Ups/powerupRed_star.png");
        AddOns[1] = new Fire("img/PNG/Power-Ups/powerupRed.png");
        AddOns[2] = new Danger("img/PNG/Power-Ups/bolt_gold.png");
        AddOns[3] = new Lives("img/PNG/Power-Ups/pill_blue.png");

        lifeTexture.loadFromFile("img/PNG/Power-ups/pill_blue.png");
        Sprite lifeSprite(lifeTexture);

        font.loadFromFile("assets/Plaguard.otf");
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);  // adjust the font size as needed
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10, 760);  // adjust position as needed

        powerUp.loadFromFile("sounds/shield.wav");
        health.loadFromFile("sounds/health.wav");
        danger.loadFromFile("sounds/myshipDestroyed.wav");
        crashed.loadFromFile("sounds/myshipDestroyed.wav");
        HitEnemy.loadFromFile("sounds/enemyshipHit.wav");

        fireBullet.loadFromFile("sounds/laser7.wav");
        fireBulletsound.setBuffer(fireBullet);

        PowerUpsound.setBuffer(powerUp);
        healthsound.setBuffer(health);
        dangersound.setBuffer(danger);
        crashedsound.setBuffer(crashed);
        HitEnemysound.setBuffer(HitEnemy);
        
    }

    ~Game() {
        delete p;
    }

    void gameOver(int score)
    {
        RenderWindow window(VideoMode(800, 800), "Game Over!");
        Font font;
        if (!font.loadFromFile("assets/BruceForeverRegular-X3jd2.ttf")) {
            // Failed to load font, handle the error
            return;
        }

        Text gameOverText("Game Over", font, 48);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(200, 300);

        Text scoreText("YOUR SCORE: " + std::to_string(score), font, 36);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(150, 400);

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    return;
                }
            }

            window.clear(Color::Black);
            window.draw(gameOverText);
            window.draw(scoreText);
            window.display();
        }
    }


    void WonGame(int score)
    {
        RenderWindow window(VideoMode(800, 800), "Congratulations!");
        Font font;
        if (!font.loadFromFile("assets/BruceForeverRegular-X3jd2.ttf")) {
            // Failed to load font, handle the error
            return;
        }

        Text gameOverText("YOU MADE IT!", font, 48);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(170, 300);

        Text scoreText("YOUR SCORE: " + std::to_string(score), font, 36);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(150, 400);

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    return;
                }
            }

            window.clear(Color::Black);
            window.draw(gameOverText);
            window.draw(scoreText);
            window.display();
        }
    }

    void wrap_piece()
    {
        Vector2f pos = p->sprite.getPosition();
        if (pos.x < -p->sprite.getGlobalBounds().width / 2) {
            pos.x = 800 + p->sprite.getGlobalBounds().width / 2;
        }
        else if (pos.x > 800 + p->sprite.getGlobalBounds().width / 2) {
            pos.x = -p->sprite.getGlobalBounds().width / 2;
        }
        if (pos.y < -p->sprite.getGlobalBounds().height / 2) {
            pos.y = 800 + p->sprite.getGlobalBounds().height / 2;
        }
        else if (pos.y > 800 + p->sprite.getGlobalBounds().height / 2) {
            pos.y = -p->sprite.getGlobalBounds().height / 2;
        }
        p->sprite.setPosition(pos);
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

    float generateRandomDelay(int level)
    {
        srand((time(nullptr)));

        float minDelay, maxDelay;

        if (level == 0) {
            minDelay = 5.0f;
            maxDelay = 10.0f;
        }
        else if (level == 1) {
            minDelay = 3.0f;
            maxDelay = 7.0f;
        }
        else if (level == 2) {
            minDelay = 2.0f;
            maxDelay = 5.0f;
        }
        else {
            // use default values
            minDelay = 0.2f;
            maxDelay = 1.5f;
        }

        float delay = minDelay + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxDelay - minDelay)));
        return delay;
    }

    void start_game(std:: string playerName)
    {
        srand(time(0));
        RenderWindow window(VideoMode(800, 800), title);

        backgroundMusic.openFromFile("sounds/backgroundMusic.wav");
        backgroundMusic.setLoop(true);
        backgroundMusic.play();
        backgroundMusic.setVolume(30);
        Clock clock;
        Clock powerUpTimer;

        // Load the custom cursor image
        Image cursorImage;
        cursorImage.loadFromFile("img/PNG/UI/cursor.png");
        Cursor cursor;
        cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), { 0, 0 });
        window.setMouseCursor(cursor);

        const float bg_speed = 300; // pixels per second
        level->InitializeCoords();

        Font font;
        font.loadFromFile("assets/Plaguard.otf");
        stageprint.setFont(font);
        stageprint.setString("-");
        stageprint.setCharacterSize(32);
        stageprint.setFillColor(Color::White);
        stageprint.setPosition(50, 8);

        shield.loadFromFile("img/PNG/Effects/shield3.png");
        sheildSprite.setTexture(shield);

        srand(time(nullptr));
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time; // increment timer by elapsed time
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }

            if (timer >= 10) { // check if timer has reached 10 seconds
                firing = true; // set firing flag to true
            }

            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Left) {
                    isLeftPressed = true; // set variable to true
                }
                if (e.key.code == Keyboard::Right) {
                    isRightPressed = true; // set variable to true
                }
            }
            if (e.type == Event::KeyReleased) {
                if (e.key.code == Keyboard::Left) {
                    isLeftPressed = false; // set variable to false
                }
                if (e.key.code == Keyboard::Right) {
                    isRightPressed = false; // set variable to false
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
                p->move("u");
            if (Keyboard::isKeyPressed(Keyboard::Down))
                p->move("d");

            // change texture depending on key press
            if (isLeftPressed) {
                p->sprite.setTexture(shipTextureLeft);
                p->move("l");
            }
            else if (isRightPressed) {
                p->sprite.setTexture(shipTextureRight);
                p->move("r");
            }
            else {
                p->sprite.setTexture(shipTexture);
            }

            wrap_piece();
            if (firing) {
                fireBulletsound.play();
                p->fire();
            }

            window.clear(Color::Black);
            level->enemiesToKill = level->ENEMIES_PER_STAGE[level->currentLevel][level->currentStage];

            //Check for Collision with enemy
            for (int k = 0; k < level->ENEMIES_PER_STAGE[level->currentLevel][level->currentStage]; k++) {
                Enemy* enemyShooter = level->enemiesOnScreen[level->currentLevel][level->currentStage][k];
                if (enemyShooter->isAlive) {
                    if (checkCollision(enemyShooter->EnemySprite, p->myBullet->Bsprite)) {
                        PlayerScore += enemyShooter->ScoreOnDeath;
                        delete enemyShooter->projectile;
                        if (p->passThrough) {
                            enemyShooter->isAlive = false;
                            level->deadEnemies++;
                            if (level->deadEnemies >= level->enemiesToKill) {
                                level->deadEnemies = 0;
                                level->currentStage++;
                                if (level->currentStage >= level->STAGES_PER_LEVEL[level->currentLevel]) {
                                    level->currentStage = 0;
                                    level->currentLevel++;
                                    if (level->currentLevel >= level->LEVELS) {
                                        window.close();
                                        WonGame(PlayerScore);
                                    }
                                }
                            }
                        }
                        else {
                            enemyShooter->isAlive = false;
                            level->deadEnemies++;
                            if (level->deadEnemies >= level->enemiesToKill) {
                                level->deadEnemies = 0;
                                level->currentStage++;
                                if (level->currentStage >= level->STAGES_PER_LEVEL[level->currentLevel]) {
                                    level->currentStage = 0;
                                    level->currentLevel++;
                                    if (level->currentLevel >= level->LEVELS) {
                                        window.close();
                                        updateTopScores(playerName, PlayerScore);
                                        WonGame(PlayerScore);
                                    }
                                }
                            }
                            float posX = p->sprite.getPosition().x + p->sprite.getGlobalBounds().width / 2;
                            float posY = p->sprite.getPosition().y;
                            p->myBullet->Bsprite.setPosition(posX, posY);
                        }
                    }
                    if (checkCollision(enemyShooter->EnemySprite, p->sprite)) {
                        HitEnemysound.play();
                        PlayerScore += enemyShooter->ScoreOnDeath;
                        p->sprite.setPosition(340.0f, 700.0f);
                        p->Lives--;
                        delete enemyShooter->projectile;
                        enemyShooter->isAlive = false;
                        level->deadEnemies++;
                        if (level->deadEnemies >= level->enemiesToKill) {
                            level->deadEnemies = 0;
                            level->currentStage++;
                            if (level->currentStage >= level->STAGES_PER_LEVEL[level->currentLevel]) {
                                level->currentStage = 0;
                                level->currentLevel++;
                                if (level->currentLevel >= level->LEVELS) {
                                    window.close();
                                    WonGame(PlayerScore);
                                }
                            }
                        }
                    }
                }
            }

            // Add-Ons
            for (int i = 0; i < 4; i++) {
                AddOns[i]->dropAddOn();
                if (checkCollision(AddOns[i]->icon, p->sprite)) {
                    float posX = rand() % (800 - int(AddOns[i]->icon.getGlobalBounds().width));
                    float posY = -(rand() % 3000 + 800);
                    AddOns[i]->icon.setPosition(posX, posY);
                    // PowerUp, Fire, Danger, Live
                    if (i == 0) {
                        PowerUpsound.play();
                        p->PowerUp();
                        powerUpTimer.restart();
                    }
                    else if (i == 1) {
                        PowerUpsound.play();
                        p->FireBullet();
                        powerUpTimer.restart();
                    }
                    else if (i == 2) {
                        dangersound.play();
                        p->Danger();
                    }
                    else {
                        healthsound.play();
                        p->LifeAddOn();
                    }
                }
            }

            if (p->passThrough && powerUpTimer.getElapsedTime().asSeconds() >= 5.0f) {
                p->myBullet->updateTex("img/PNG/Lasers/laserBlue07.png");
                p->passThrough = false; // Revert the fire power-up
            }
            if (p->powerUpShieldTurrents && powerUpTimer.getElapsedTime().asSeconds() >= 5.0f) {
                p->powerUpShieldTurrents = false; // Revert the power-up
            }

            // Move both instances of background downwards
            bg_position1.y += bg_speed * time;
            bg_position2.y += bg_speed * time;

            // If bg_position1 goes out of the screen, wrap it around to the top
            if (bg_position1.y >= 800) {
                bg_position1.y = bg_position2.y - bg_texture.getSize().y;
            }

            // If bg_position2 goes out of the screen, wrap it around to the top
            if (bg_position2.y >= 800) {
                bg_position2.y = bg_position1.y - bg_texture.getSize().y;
            }

            switch (level->currentLevel) {
            case 0:
                Level.loadFromFile("img/PNG/UI/numeral1.png");
                break;
            case 1:
                Level.loadFromFile("img/PNG/UI/numeral2.png");
                break;
            case 2:
                Level.loadFromFile("img/PNG/UI/numeral3.png");
                break;
            default:
                break;
            }
            switch (level->currentStage) {
            case 0:
                Stage.loadFromFile("img/PNG/UI/numeral1.png");
                break;
            case 1:
                Stage.loadFromFile("img/PNG/UI/numeral2.png");
                break;
            case 2:
                Stage.loadFromFile("img/PNG/UI/numeral3.png");
                break;
            case 3:
                Stage.loadFromFile("img/PNG/UI/numeral4.png");
                break;
            case 4:
                Stage.loadFromFile("img/PNG/UI/numeral5.png");
                break;
            case 5:
                Stage.loadFromFile("img/PNG/UI/numeral6.png");
                break;
            default:
                break;
            }

            LevelSprite.setTexture(Level);
            LevelSprite.setPosition(20, 20);
            StageSprite.setTexture(Stage);
            StageSprite.setPosition(80, 20);

            //Have enemies firing bomb
            for (int k = 0; k < level->ENEMIES_PER_STAGE[level->currentLevel][level->currentStage]; k++) {
                Enemy* enemyShooter = level->enemiesOnScreen[level->currentLevel][level->currentStage][k];
                if (timer >= enemyShooter->getTimeDelay())
                {
                    enemyShooter->attack(p);
                    if (checkCollision(enemyShooter->projectile->Bsprite, p->sprite)) {
                        float posX = p->sprite.getPosition().x + p->sprite.getGlobalBounds().width / 2;
                        float posY = p->sprite.getPosition().y;
                        enemyShooter->projectile->Bsprite.setPosition(posX, posY);
                        p->Lives--;
                    }
                    enemyShooter->resetBombTimer();
                }
            }

            if (p->Lives < 1) {
                window.close();
                gameOver(PlayerScore);
            }

            // Draw the two instances of background
            background.setPosition(bg_position1.x, bg_position1.y);
            window.draw(background);
            background.setPosition(bg_position2.x, bg_position2.y);
            window.draw(background);
            window.draw(p->sprite);
            window.draw(p->myBullet->Bsprite);
            window.draw(LevelSprite);
            window.draw(StageSprite);
            window.draw(stageprint);

            if (p->Lives > 0)
            {
                lifeTexture.loadFromFile("img/PNG/UI/playerLife1_red.png");
                Vector2u textureSize = lifeTexture.getSize();
                float spriteScale = 1.5f;

                for (int i = 0; i < p->Lives; i++)
                {
                    lifePillsSprite.setTexture(lifeTexture);
                    lifePillsSprite.setScale(spriteScale, spriteScale);
                    lifePillsSprite.setPosition(window.getSize().x - (i + 1) * (textureSize.x * spriteScale + 10.f), window.getSize().y - textureSize.y * spriteScale - 10.f);
                    window.draw(lifePillsSprite);
                }
            }

            if (p->powerUpShieldTurrents) {
                sheildSprite.setPosition(p->sprite.getPosition().x - 34, p->sprite.getPosition().y - 25);
                window.draw(sheildSprite);
            }

            for (int k = 0; k < level->ENEMIES_PER_STAGE[level->currentLevel][level->currentStage]; k++) {
                Enemy* enemyInvader = level->enemiesOnScreen[level->currentLevel][level->currentStage][k];
                if (enemyInvader->isAlive) {
                    window.draw(enemyInvader->projectile->Bsprite);
                    window.draw(enemyInvader->EnemySprite);
                }
            }

            scoreText.setString("Score: " + std::to_string(PlayerScore));
            
            window.draw(scoreText);

            for (int i = 0; i < 4; i++) {
                window.draw(AddOns[i]->icon);
            }
            window.display();
        }
    }
};

#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "AlphaInvader.h"
#include "BetaInvader.h"
#include "GammaInvader.h"


using namespace sf;

class Enemy;
class Invader;

class Levels {
public:
    const int LEVELS = 3;
    const int STAGES_PER_LEVEL[3] = { 3,3,6 };

    int** ENEMIES_PER_STAGE; // number of enemies in each stage of each level

    int currentLevel;
    int currentStage;
    int enemiesToKill;
    int deadEnemies;

    Texture invaderTextures[4][5]; // Black, Blue, Green, Red
    Enemy**** enemiesOnScreen;

    //Player* pPtr;

    Levels();
    //~Levels();
    void InitializeCoords();
    void drawLevel(RenderWindow* screenToDraw, int currentLevel, int currentStage);
    void loadNextLevel(int level);  //a method to load the specified level by setting the current_level to the given leveland initializing the current_stage to 1.
    void loadNextStage(); //a method to load the next stage of the current level by incrementing the current_stage and initializing the enemy EnemySprites' coordinates based on the current level and stage.
    bool isStageComplete();
    bool isLevelComplete(); //a method to check if all enemies in the current stage are destroyed.
    bool isGameComplete(); //a method to check if all stages in the current level are completed.
};

Levels::Levels() {

    //pPtr = pIn;

    ENEMIES_PER_STAGE = nullptr;

    // Initialize current level and stage to 0
    currentLevel = 0;
    currentStage = 0;

    // Initialize current enemy shape and counter
    enemiesToKill = 0;
    deadEnemies = 0;


    std::string colorSets[3] = { "Black", "Blue", "Green" }; // , "Red" };
    for (int color = 0; color < 3; color++) {
        for (int shape = 1; shape <= 5; shape++) {
            invaderTextures[color][shape].loadFromFile("img/PNG/Enemies/enemy" + colorSets[color] + std::to_string(shape) + ".png");
        }
    }

    // Initialize the array for enemies on screen
    enemiesOnScreen = nullptr;
}

/*
Levels::~Levels() {
    // Deallocate memory for ENEMIES_PER_STAGE
    for (int i = 0; i < LEVELS; i++) {
        delete[] ENEMIES_PER_STAGE[i];
    }
    delete[] ENEMIES_PER_STAGE;

    // Deallocate memory for enemiesOnScreen
    for (int i = 0; i < LEVELS; i++) {
        for (int j = 0; j < STAGES_PER_LEVEL[i]; j++) {
            delete[] enemiesOnScreen[i][j];
        }
        delete[] enemiesOnScreen[i];
    }
    delete[] enemiesOnScreen;
}*/


void Levels::InitializeCoords() {

    // Initialize the number of enemies per stage for each level to 0
    ENEMIES_PER_STAGE = new int* [LEVELS];
    for (int level = 0; level < LEVELS; level++) {
        ENEMIES_PER_STAGE[level] = new int[STAGES_PER_LEVEL[level]];
        for (int stage = 0; stage < STAGES_PER_LEVEL[level]; stage++) {
            ENEMIES_PER_STAGE[level][stage] = 0;
        }
    }

    // Initialize the number of enemies per stage for each level
    for (int level = 0; level < 3; level++) {
        switch (level) {
        case 0:
            ENEMIES_PER_STAGE[level][0] = 14; //Rectangle
            ENEMIES_PER_STAGE[level][1] = 15; //Triangle
            ENEMIES_PER_STAGE[level][2] = 17; //Cross
            break;

        case 1:
            ENEMIES_PER_STAGE[level][0] = 15; // Cirlcle
            ENEMIES_PER_STAGE[level][1] = 20; // Diamond
            ENEMIES_PER_STAGE[level][2] = 20; // Heart
            break;

        case 2:
            ENEMIES_PER_STAGE[level][0] = 24; // Filled Rectangle
            ENEMIES_PER_STAGE[level][1] = 25; // Filled Triangle
            ENEMIES_PER_STAGE[level][2] = 25; // Cross
            ENEMIES_PER_STAGE[level][3] = 27; // Filled Circle
            ENEMIES_PER_STAGE[level][4] = 29; // Filled Heart
            ENEMIES_PER_STAGE[level][5] = 30; // Filled Diamond
            break;
        }
    }

    Texture BombTex;
    // Initialize the enemy coordinates for each stage of each level to 0
    enemiesOnScreen = new Enemy ***[LEVELS];
    for (int level = 0; level < LEVELS; level++) {
        enemiesOnScreen[level] = new Enemy * *[STAGES_PER_LEVEL[level]];
        for (int stage = 0; stage < STAGES_PER_LEVEL[level]; stage++) {
            enemiesOnScreen[level][stage] = new Enemy * [ENEMIES_PER_STAGE[level][stage]];
            for (int enemy = 0; enemy < ENEMIES_PER_STAGE[level][stage]; enemy++) {
                int rand_num = rand() % 3; // generate a random number between 0 and 2
                if (rand_num == 0) {
                    enemiesOnScreen[level][stage][enemy] = new AlphaInvader("img/PNG/Effects/star2.png");
                }
                else if (rand_num == 1) {
                    enemiesOnScreen[level][stage][enemy] = new BetaInvader("img/enemy_laser.png");
                }
                else if (rand_num == 2) {
                    enemiesOnScreen[level][stage][enemy] = new GammaInvader("img/PNG/Effects/fire15.png");
                }
            }
        }
    }

    // Assign a random texture to the enemies, same color set per stage for the 
    // first two levels but a random color and random shape for final level
    srand(time(0));
    int randomColor = 0, randomShape = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < STAGES_PER_LEVEL[i]; j++) {
            randomColor = rand() % 3;
            for (int k = 0; k < ENEMIES_PER_STAGE[i][j]; k++) {
                randomShape = rand() % 5 + 1;
                if (i == 2) {
                    randomColor = rand() % 3;
                }
                enemiesOnScreen[i][j][k]->EnemySprite.setTexture(invaderTextures[randomColor][randomShape]);
                enemiesOnScreen[i][j][k]->EnemySprite.setScale(0.75, 0.75);
            }
        }
    }

    //// LEVEL 1

        // Setting up Hollow Rectangle - 14 Shapes
    enemiesOnScreen[0][0][0]->EnemySprite.setPosition(115, 100);
    enemiesOnScreen[0][0][1]->EnemySprite.setPosition(215, 100);
    enemiesOnScreen[0][0][2]->EnemySprite.setPosition(315, 100);
    enemiesOnScreen[0][0][3]->EnemySprite.setPosition(415, 100);
    enemiesOnScreen[0][0][4]->EnemySprite.setPosition(515, 100);
    enemiesOnScreen[0][0][5]->EnemySprite.setPosition(615, 100);
    enemiesOnScreen[0][0][6]->EnemySprite.setPosition(115, 175);
    enemiesOnScreen[0][0][7]->EnemySprite.setPosition(615, 175);
    enemiesOnScreen[0][0][8]->EnemySprite.setPosition(115, 250);
    enemiesOnScreen[0][0][9]->EnemySprite.setPosition(215, 250);
    enemiesOnScreen[0][0][10]->EnemySprite.setPosition(315, 250);
    enemiesOnScreen[0][0][11]->EnemySprite.setPosition(415, 250);
    enemiesOnScreen[0][0][12]->EnemySprite.setPosition(515, 250);
    enemiesOnScreen[0][0][13]->EnemySprite.setPosition(615, 250);


    // Setting up Hollow Inverted Triangle - 15 Shapes
    enemiesOnScreen[0][1][0]->EnemySprite.setPosition(120, 50);
    enemiesOnScreen[0][1][1]->EnemySprite.setPosition(210, 50);
    enemiesOnScreen[0][1][2]->EnemySprite.setPosition(305, 50);
    enemiesOnScreen[0][1][3]->EnemySprite.setPosition(400, 50);
    enemiesOnScreen[0][1][4]->EnemySprite.setPosition(495, 50);
    enemiesOnScreen[0][1][5]->EnemySprite.setPosition(590, 50);
    enemiesOnScreen[0][1][6]->EnemySprite.setPosition(175, 130);
    enemiesOnScreen[0][1][7]->EnemySprite.setPosition(545, 130);
    enemiesOnScreen[0][1][8]->EnemySprite.setPosition(225, 210);
    enemiesOnScreen[0][1][9]->EnemySprite.setPosition(495, 210);
    enemiesOnScreen[0][1][10]->EnemySprite.setPosition(275, 280);
    enemiesOnScreen[0][1][11]->EnemySprite.setPosition(465, 280);
    enemiesOnScreen[0][1][12]->EnemySprite.setPosition(315, 360);
    enemiesOnScreen[0][1][13]->EnemySprite.setPosition(435, 360);
    enemiesOnScreen[0][1][14]->EnemySprite.setPosition(370, 430);

    // Setting up Cross - 17 Shapes
    enemiesOnScreen[0][2][0]->EnemySprite.setPosition(465, 150);
    enemiesOnScreen[0][2][1]->EnemySprite.setPosition(565, 100);
    enemiesOnScreen[0][2][2]->EnemySprite.setPosition(665, 50);
    enemiesOnScreen[0][2][3]->EnemySprite.setPosition(65, 50);
    enemiesOnScreen[0][2][4]->EnemySprite.setPosition(165, 100);
    enemiesOnScreen[0][2][5]->EnemySprite.setPosition(265, 150);
    enemiesOnScreen[0][2][6]->EnemySprite.setPosition(365, 100);
    enemiesOnScreen[0][2][7]->EnemySprite.setPosition(125, 200);
    enemiesOnScreen[0][2][8]->EnemySprite.setPosition(365, 200);
    enemiesOnScreen[0][2][9]->EnemySprite.setPosition(605, 200);
    enemiesOnScreen[0][2][10]->EnemySprite.setPosition(365, 300);
    enemiesOnScreen[0][2][11]->EnemySprite.setPosition(265, 250);
    enemiesOnScreen[0][2][12]->EnemySprite.setPosition(165, 300);
    enemiesOnScreen[0][2][13]->EnemySprite.setPosition(65, 350);
    enemiesOnScreen[0][2][14]->EnemySprite.setPosition(465, 250);
    enemiesOnScreen[0][2][15]->EnemySprite.setPosition(565, 300);
    enemiesOnScreen[0][2][16]->EnemySprite.setPosition(665, 350);

    //// LEVEL 2

        // Setting up Hollow Circle - 15 Shapes
    enemiesOnScreen[1][0][0]->EnemySprite.setPosition(360, 25);
    enemiesOnScreen[1][0][1]->EnemySprite.setPosition(427, 43);
    enemiesOnScreen[1][0][2]->EnemySprite.setPosition(484, 87);
    enemiesOnScreen[1][0][3]->EnemySprite.setPosition(522, 150);
    enemiesOnScreen[1][0][4]->EnemySprite.setPosition(522, 225);
    enemiesOnScreen[1][0][5]->EnemySprite.setPosition(484, 288);
    enemiesOnScreen[1][0][6]->EnemySprite.setPosition(427, 332);
    enemiesOnScreen[1][0][7]->EnemySprite.setPosition(360, 350);
    enemiesOnScreen[1][0][8]->EnemySprite.setPosition(293, 332);
    enemiesOnScreen[1][0][9]->EnemySprite.setPosition(236, 288);
    enemiesOnScreen[1][0][10]->EnemySprite.setPosition(198, 225);
    enemiesOnScreen[1][0][11]->EnemySprite.setPosition(198, 150);
    enemiesOnScreen[1][0][12]->EnemySprite.setPosition(236, 87);
    enemiesOnScreen[1][0][13]->EnemySprite.setPosition(293, 43);
    enemiesOnScreen[1][0][14]->EnemySprite.setPosition(365, 192);

    // Setting up Hollow Diamond - 20 Shapes
    enemiesOnScreen[1][1][0]->EnemySprite.setPosition(115, 130);
    enemiesOnScreen[1][1][1]->EnemySprite.setPosition(215, 130);
    enemiesOnScreen[1][1][2]->EnemySprite.setPosition(165, 100);
    enemiesOnScreen[1][1][3]->EnemySprite.setPosition(565, 100);
    enemiesOnScreen[1][1][4]->EnemySprite.setPosition(515, 130);
    enemiesOnScreen[1][1][5]->EnemySprite.setPosition(615, 130);
    enemiesOnScreen[1][1][6]->EnemySprite.setPosition(165, 180);
    enemiesOnScreen[1][1][7]->EnemySprite.setPosition(200, 230);
    enemiesOnScreen[1][1][8]->EnemySprite.setPosition(285, 65);
    enemiesOnScreen[1][1][9]->EnemySprite.setPosition(365, 65);
    enemiesOnScreen[1][1][10]->EnemySprite.setPosition(565, 180);
    enemiesOnScreen[1][1][11]->EnemySprite.setPosition(265, 280);
    enemiesOnScreen[1][1][12]->EnemySprite.setPosition(530, 230);
    enemiesOnScreen[1][1][13]->EnemySprite.setPosition(465, 280);
    enemiesOnScreen[1][1][14]->EnemySprite.setPosition(400, 310);
    enemiesOnScreen[1][1][15]->EnemySprite.setPosition(230, 65);
    enemiesOnScreen[1][1][16]->EnemySprite.setPosition(335, 310);
    enemiesOnScreen[1][1][17]->EnemySprite.setPosition(430, 65);
    enemiesOnScreen[1][1][18]->EnemySprite.setPosition(365, 365);
    enemiesOnScreen[1][1][19]->EnemySprite.setPosition(495, 65);

    // Setting up Hollow Heart - 20 Shapes
    enemiesOnScreen[1][2][0]->EnemySprite.setPosition(115, 200);
    enemiesOnScreen[1][2][1]->EnemySprite.setPosition(155, 45);
    enemiesOnScreen[1][2][2]->EnemySprite.setPosition(240, 50);
    enemiesOnScreen[1][2][3]->EnemySprite.setPosition(480, 55);
    enemiesOnScreen[1][2][4]->EnemySprite.setPosition(569, 48);
    enemiesOnScreen[1][2][5]->EnemySprite.setPosition(590, 200);
    enemiesOnScreen[1][2][6]->EnemySprite.setPosition(175, 280);
    enemiesOnScreen[1][2][7]->EnemySprite.setPosition(560, 280);
    enemiesOnScreen[1][2][8]->EnemySprite.setPosition(225, 360);
    enemiesOnScreen[1][2][9]->EnemySprite.setPosition(530, 360);
    enemiesOnScreen[1][2][10]->EnemySprite.setPosition(275, 430);
    enemiesOnScreen[1][2][11]->EnemySprite.setPosition(480, 430);
    enemiesOnScreen[1][2][12]->EnemySprite.setPosition(315, 510);
    enemiesOnScreen[1][2][13]->EnemySprite.setPosition(435, 510);
    enemiesOnScreen[1][2][14]->EnemySprite.setPosition(370, 580);
    enemiesOnScreen[1][2][15]->EnemySprite.setPosition(115, 125);
    enemiesOnScreen[1][2][16]->EnemySprite.setPosition(305, 125);
    enemiesOnScreen[1][2][17]->EnemySprite.setPosition(400, 125);
    enemiesOnScreen[1][2][18]->EnemySprite.setPosition(610, 125);
    enemiesOnScreen[1][2][19]->EnemySprite.setPosition(360, 210);

    //// LEVEL 3


        // Setting up Filled Rectangle - 24 Shapes
    enemiesOnScreen[2][0][0]->EnemySprite.setPosition(115, 25);
    enemiesOnScreen[2][0][1]->EnemySprite.setPosition(115, 125);
    enemiesOnScreen[2][0][2]->EnemySprite.setPosition(115, 225);
    enemiesOnScreen[2][0][3]->EnemySprite.setPosition(115, 325);
    enemiesOnScreen[2][0][4]->EnemySprite.setPosition(215, 25);
    enemiesOnScreen[2][0][5]->EnemySprite.setPosition(215, 125);
    enemiesOnScreen[2][0][6]->EnemySprite.setPosition(215, 225);
    enemiesOnScreen[2][0][7]->EnemySprite.setPosition(215, 325);
    enemiesOnScreen[2][0][8]->EnemySprite.setPosition(315, 25);
    enemiesOnScreen[2][0][9]->EnemySprite.setPosition(315, 125);
    enemiesOnScreen[2][0][10]->EnemySprite.setPosition(315, 225);
    enemiesOnScreen[2][0][11]->EnemySprite.setPosition(315, 325);
    enemiesOnScreen[2][0][12]->EnemySprite.setPosition(415, 25);
    enemiesOnScreen[2][0][13]->EnemySprite.setPosition(415, 125);
    enemiesOnScreen[2][0][14]->EnemySprite.setPosition(415, 225);
    enemiesOnScreen[2][0][15]->EnemySprite.setPosition(415, 325);
    enemiesOnScreen[2][0][16]->EnemySprite.setPosition(515, 25);
    enemiesOnScreen[2][0][17]->EnemySprite.setPosition(515, 125);
    enemiesOnScreen[2][0][18]->EnemySprite.setPosition(515, 225);
    enemiesOnScreen[2][0][19]->EnemySprite.setPosition(515, 325);
    enemiesOnScreen[2][0][20]->EnemySprite.setPosition(615, 25);
    enemiesOnScreen[2][0][21]->EnemySprite.setPosition(615, 125);
    enemiesOnScreen[2][0][22]->EnemySprite.setPosition(615, 225);
    enemiesOnScreen[2][0][23]->EnemySprite.setPosition(615, 325);

    // Setting up Filled Inverted Triangle - 25 Shapes
    enemiesOnScreen[2][1][0]->EnemySprite.setPosition(-50, 50);
    enemiesOnScreen[2][1][1]->EnemySprite.setPosition(50, 50);
    enemiesOnScreen[2][1][2]->EnemySprite.setPosition(150, 50);
    enemiesOnScreen[2][1][3]->EnemySprite.setPosition(250, 50);
    enemiesOnScreen[2][1][4]->EnemySprite.setPosition(350, 50);
    enemiesOnScreen[2][1][5]->EnemySprite.setPosition(450, 50);
    enemiesOnScreen[2][1][6]->EnemySprite.setPosition(550, 50);
    enemiesOnScreen[2][1][7]->EnemySprite.setPosition(650, 50);
    enemiesOnScreen[2][1][8]->EnemySprite.setPosition(750, 50);
    enemiesOnScreen[2][1][9]->EnemySprite.setPosition(50, 150);
    enemiesOnScreen[2][1][10]->EnemySprite.setPosition(150, 150);
    enemiesOnScreen[2][1][11]->EnemySprite.setPosition(250, 150);
    enemiesOnScreen[2][1][12]->EnemySprite.setPosition(350, 150);
    enemiesOnScreen[2][1][13]->EnemySprite.setPosition(450, 150);
    enemiesOnScreen[2][1][14]->EnemySprite.setPosition(550, 150);
    enemiesOnScreen[2][1][15]->EnemySprite.setPosition(650, 150);
    enemiesOnScreen[2][1][16]->EnemySprite.setPosition(150, 250);
    enemiesOnScreen[2][1][17]->EnemySprite.setPosition(250, 250);
    enemiesOnScreen[2][1][18]->EnemySprite.setPosition(350, 250);
    enemiesOnScreen[2][1][19]->EnemySprite.setPosition(450, 250);
    enemiesOnScreen[2][1][20]->EnemySprite.setPosition(550, 250);
    enemiesOnScreen[2][1][21]->EnemySprite.setPosition(250, 350);
    enemiesOnScreen[2][1][22]->EnemySprite.setPosition(350, 350);
    enemiesOnScreen[2][1][23]->EnemySprite.setPosition(450, 350);
    enemiesOnScreen[2][1][24]->EnemySprite.setPosition(350, 450);

    // Setting up Cross - 25 Shapes
    enemiesOnScreen[2][2][0]->EnemySprite.setPosition(765, 0); // Top Right Four
    enemiesOnScreen[2][2][1]->EnemySprite.setPosition(665, 50); // Top Right Three
    enemiesOnScreen[2][2][2]->EnemySprite.setPosition(565, 100); // Top Right Two
    enemiesOnScreen[2][2][3]->EnemySprite.setPosition(465, 150); // Top Right
    enemiesOnScreen[2][2][4]->EnemySprite.setPosition(-35, 0); // Top Left Four
    enemiesOnScreen[2][2][5]->EnemySprite.setPosition(65, 50); // Top Left Three
    enemiesOnScreen[2][2][6]->EnemySprite.setPosition(165, 100); // Top Left Two
    enemiesOnScreen[2][2][7]->EnemySprite.setPosition(265, 150); // Top Left
    enemiesOnScreen[2][2][8]->EnemySprite.setPosition(365, 0); // Up Two
    enemiesOnScreen[2][2][9]->EnemySprite.setPosition(365, 100); // Up One
    enemiesOnScreen[2][2][10]->EnemySprite.setPosition(25, 200); // Left Two
    enemiesOnScreen[2][2][11]->EnemySprite.setPosition(140, 200); // Left One
    enemiesOnScreen[2][2][12]->EnemySprite.setPosition(368, 200); // Center
    enemiesOnScreen[2][2][13]->EnemySprite.setPosition(590, 200); // Right One
    enemiesOnScreen[2][2][14]->EnemySprite.setPosition(705, 200); // Right Two
    enemiesOnScreen[2][2][15]->EnemySprite.setPosition(365, 300); // Down One
    enemiesOnScreen[2][2][16]->EnemySprite.setPosition(365, 400); // Down Two
    enemiesOnScreen[2][2][17]->EnemySprite.setPosition(265, 250); // Bottom Left
    enemiesOnScreen[2][2][18]->EnemySprite.setPosition(165, 300); // Bottom Left Two
    enemiesOnScreen[2][2][19]->EnemySprite.setPosition(65, 350); // Bottom Left Three
    enemiesOnScreen[2][2][20]->EnemySprite.setPosition(-35, 400); // Bottom Left Four
    enemiesOnScreen[2][2][21]->EnemySprite.setPosition(465, 250); // Bottom Right
    enemiesOnScreen[2][2][22]->EnemySprite.setPosition(565, 300); // Bottom Right Two
    enemiesOnScreen[2][2][23]->EnemySprite.setPosition(665, 350); // Bottom Right Three
    enemiesOnScreen[2][2][24]->EnemySprite.setPosition(765, 400); // Bottom Right Four

    // Setting up Filled Circle - 27 Shapes
    enemiesOnScreen[2][3][0]->EnemySprite.setPosition(450, 250);
    enemiesOnScreen[2][3][1]->EnemySprite.setPosition(445, 284);
    enemiesOnScreen[2][3][2]->EnemySprite.setPosition(434, 317);
    enemiesOnScreen[2][3][3]->EnemySprite.setPosition(414, 346);
    enemiesOnScreen[2][3][4]->EnemySprite.setPosition(389, 370);
    enemiesOnScreen[2][3][5]->EnemySprite.setPosition(359, 387);
    enemiesOnScreen[2][3][6]->EnemySprite.setPosition(326, 397);
    enemiesOnScreen[2][3][7]->EnemySprite.setPosition(291, 399);
    enemiesOnScreen[2][3][8]->EnemySprite.setPosition(256, 393);
    enemiesOnScreen[2][3][9]->EnemySprite.setPosition(250, 336);
    enemiesOnScreen[2][3][10]->EnemySprite.setPosition(231, 322);
    enemiesOnScreen[2][3][11]->EnemySprite.setPosition(216, 304);
    enemiesOnScreen[2][3][12]->EnemySprite.setPosition(206, 284);
    enemiesOnScreen[2][3][13]->EnemySprite.setPosition(200, 261);
    enemiesOnScreen[2][3][14]->EnemySprite.setPosition(200, 238);
    enemiesOnScreen[2][3][15]->EnemySprite.setPosition(206, 215);
    enemiesOnScreen[2][3][16]->EnemySprite.setPosition(216, 195);
    enemiesOnScreen[2][3][17]->EnemySprite.setPosition(231, 177);
    enemiesOnScreen[2][3][18]->EnemySprite.setPosition(275, 206);
    enemiesOnScreen[2][3][19]->EnemySprite.setPosition(285, 202);
    enemiesOnScreen[2][3][20]->EnemySprite.setPosition(297, 200);
    enemiesOnScreen[2][3][21]->EnemySprite.setPosition(308, 200);
    enemiesOnScreen[2][3][22]->EnemySprite.setPosition(319, 204);
    enemiesOnScreen[2][3][23]->EnemySprite.setPosition(329, 209);
    enemiesOnScreen[2][3][24]->EnemySprite.setPosition(338, 217);
    enemiesOnScreen[2][3][25]->EnemySprite.setPosition(344, 227);
    enemiesOnScreen[2][3][26]->EnemySprite.setPosition(348, 238);

    // Setting up Filled Heart - 29
    enemiesOnScreen[2][4][0]->EnemySprite.setPosition(100, 95);
    enemiesOnScreen[2][4][1]->EnemySprite.setPosition(50, 170);
    enemiesOnScreen[2][4][2]->EnemySprite.setPosition(150, 170);
    enemiesOnScreen[2][4][3]->EnemySprite.setPosition(250, 170);
    enemiesOnScreen[2][4][4]->EnemySprite.setPosition(200, 95);
    enemiesOnScreen[2][4][5]->EnemySprite.setPosition(450, 170);
    enemiesOnScreen[2][4][6]->EnemySprite.setPosition(550, 170);
    enemiesOnScreen[2][4][7]->EnemySprite.setPosition(650, 170);
    enemiesOnScreen[2][4][8]->EnemySprite.setPosition(600, 95);
    enemiesOnScreen[2][4][9]->EnemySprite.setPosition(50, 270);
    enemiesOnScreen[2][4][10]->EnemySprite.setPosition(150, 270);
    enemiesOnScreen[2][4][11]->EnemySprite.setPosition(250, 270);
    enemiesOnScreen[2][4][12]->EnemySprite.setPosition(350, 270);
    enemiesOnScreen[2][4][13]->EnemySprite.setPosition(450, 270);
    enemiesOnScreen[2][4][25]->EnemySprite.setPosition(500, 95);
    enemiesOnScreen[2][4][14]->EnemySprite.setPosition(550, 270);
    enemiesOnScreen[2][4][15]->EnemySprite.setPosition(650, 270);
    enemiesOnScreen[2][4][16]->EnemySprite.setPosition(150, 370);
    enemiesOnScreen[2][4][17]->EnemySprite.setPosition(250, 370);
    enemiesOnScreen[2][4][18]->EnemySprite.setPosition(350, 370);
    enemiesOnScreen[2][4][19]->EnemySprite.setPosition(450, 370);
    enemiesOnScreen[2][4][20]->EnemySprite.setPosition(550, 370);
    enemiesOnScreen[2][4][21]->EnemySprite.setPosition(250, 470);
    enemiesOnScreen[2][4][22]->EnemySprite.setPosition(350, 470);
    enemiesOnScreen[2][4][23]->EnemySprite.setPosition(450, 470);
    enemiesOnScreen[2][4][24]->EnemySprite.setPosition(350, 570);
    enemiesOnScreen[2][4][26]->EnemySprite.setPosition(350, 195);
    enemiesOnScreen[2][4][27]->EnemySprite.setPosition(150, 20);
    enemiesOnScreen[2][4][28]->EnemySprite.setPosition(550, 20);


    // Setting up Filled Diamond - 30 Shapes
    enemiesOnScreen[2][5][0]->EnemySprite.setPosition(230, 65);
    enemiesOnScreen[2][5][1]->EnemySprite.setPosition(285, 65);
    enemiesOnScreen[2][5][2]->EnemySprite.setPosition(365, 65);
    enemiesOnScreen[2][5][3]->EnemySprite.setPosition(430, 65);
    enemiesOnScreen[2][5][4]->EnemySprite.setPosition(495, 65);
    enemiesOnScreen[2][5][5]->EnemySprite.setPosition(165, 100);
    enemiesOnScreen[2][5][6]->EnemySprite.setPosition(565, 100);
    enemiesOnScreen[2][5][7]->EnemySprite.setPosition(285, 115);
    enemiesOnScreen[2][5][8]->EnemySprite.setPosition(360, 115);
    enemiesOnScreen[2][5][9]->EnemySprite.setPosition(430, 115);
    enemiesOnScreen[2][5][10]->EnemySprite.setPosition(285, 240);
    enemiesOnScreen[2][5][11]->EnemySprite.setPosition(365, 240);
    enemiesOnScreen[2][5][12]->EnemySprite.setPosition(430, 240);
    enemiesOnScreen[2][5][13]->EnemySprite.setPosition(115, 130);
    enemiesOnScreen[2][5][14]->EnemySprite.setPosition(215, 130);
    enemiesOnScreen[2][5][15]->EnemySprite.setPosition(515, 130);
    enemiesOnScreen[2][5][16]->EnemySprite.setPosition(615, 130);
    enemiesOnScreen[2][5][17]->EnemySprite.setPosition(165, 180);
    enemiesOnScreen[2][5][18]->EnemySprite.setPosition(565, 180);
    enemiesOnScreen[2][5][19]->EnemySprite.setPosition(320, 180);
    enemiesOnScreen[2][5][20]->EnemySprite.setPosition(410, 180);
    enemiesOnScreen[2][5][21]->EnemySprite.setPosition(250, 180);
    enemiesOnScreen[2][5][22]->EnemySprite.setPosition(480, 180);
    enemiesOnScreen[2][5][23]->EnemySprite.setPosition(200, 230);
    enemiesOnScreen[2][5][24]->EnemySprite.setPosition(530, 230);
    enemiesOnScreen[2][5][25]->EnemySprite.setPosition(465, 280);
    enemiesOnScreen[2][5][26]->EnemySprite.setPosition(265, 280);
    enemiesOnScreen[2][5][27]->EnemySprite.setPosition(400, 310);
    enemiesOnScreen[2][5][28]->EnemySprite.setPosition(335, 310);
    enemiesOnScreen[2][5][29]->EnemySprite.setPosition(365, 365);

    for (int i = 0; i < LEVELS; i++) {
        for (int j = 0; j < STAGES_PER_LEVEL[i]; j++) {
            for (int k = 0; k < ENEMIES_PER_STAGE[i][j]; k++) {
                enemiesOnScreen[i][j][k]->projectile->updatePosition(enemiesOnScreen[i][j][k]->EnemySprite);
            }
        }
    }

}



/*
void Levels::drawLevel(RenderWindow* screenToDraw, int currentLevel = 0, int currentStage = 0) {
    for (int k = 0; k < ENEMIES_PER_STAGE[currentLevel][currentStage]; k++) {
        screenToDraw->draw(enemiesOnScreen[currentLevel][currentStage][k]->EnemySprite);
    }
}

*/
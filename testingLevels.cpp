
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;


int main()
{

    Sprite*** enemiesOnScreen;

    const int LEVELS = 3;
    const int STAGES_PER_LEVEL[3] = { 3,3,6 };
    int** ENEMIES_PER_STAGE;

    // Initialize the number of enemies per stage for each level to 0
    ENEMIES_PER_STAGE = new int* [LEVELS];
    for (int level = 0; level < LEVELS; level++) {
        ENEMIES_PER_STAGE[level] = new int[STAGES_PER_LEVEL[level]];
        for (int stage = 0; stage < STAGES_PER_LEVEL[level]; stage++) {
            ENEMIES_PER_STAGE[level][stage] = 0;
        }
    }

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

    enemiesOnScreen = new Sprite * *[LEVELS];
    for (int level = 0; level < LEVELS; level++) {
        enemiesOnScreen[level] = new Sprite * [STAGES_PER_LEVEL[level]];
        for (int stage = 0; stage < STAGES_PER_LEVEL[level]; stage++) {
            enemiesOnScreen[level][stage] = new Sprite[ENEMIES_PER_STAGE[level][stage]];
        }
    }

    Texture invaderTextures[4][5];
    std::string colorSets[4] = { "Black", "Blue", "Green", "Red" };
    for (int color = 0; color < 4; color++) {
        for (int shape = 1; shape < 6; shape++) {
            invaderTextures[color][shape].loadFromFile("img/PNG/Enemies/enemy" + colorSets[color] + std::to_string(shape) + ".png");
        }
    }

    srand(time(0));
    int randomColor = 0, randomShape = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < STAGES_PER_LEVEL[i]; j++) {
            randomColor = rand() % 4;
            for (int k = 0; k < ENEMIES_PER_STAGE[i][j]; k++) {
                randomShape = rand() % 5 + 1;
                if (i == 2) {
                    randomColor = rand() % 4;
                }
                enemiesOnScreen[i][j][k].setTexture(invaderTextures[randomColor][randomShape]);
                enemiesOnScreen[i][j][k].setScale(0.75, 0.75);
            }
        }
    }


    //// LEVEL 1

        // Setting up Hollow Rectangle - 14 Shapes
    enemiesOnScreen[0][0][0].setPosition(115, 100);
    enemiesOnScreen[0][0][1].setPosition(215, 100);
    enemiesOnScreen[0][0][2].setPosition(315, 100);
    enemiesOnScreen[0][0][3].setPosition(415, 100);
    enemiesOnScreen[0][0][4].setPosition(515, 100);
    enemiesOnScreen[0][0][5].setPosition(615, 100);
    enemiesOnScreen[0][0][6].setPosition(115, 175);
    enemiesOnScreen[0][0][7].setPosition(615, 175);
    enemiesOnScreen[0][0][8].setPosition(115, 250);
    enemiesOnScreen[0][0][9].setPosition(215, 250);
    enemiesOnScreen[0][0][10].setPosition(315, 250);
    enemiesOnScreen[0][0][11].setPosition(415, 250);
    enemiesOnScreen[0][0][12].setPosition(515, 250);
    enemiesOnScreen[0][0][13].setPosition(615, 250);

    // Setting up Hollow Inverted Triangle - 15 Shapes
    enemiesOnScreen[0][1][0].setPosition(115, 50);
    enemiesOnScreen[0][1][1].setPosition(210, 50);
    enemiesOnScreen[0][1][2].setPosition(305, 50);
    enemiesOnScreen[0][1][3].setPosition(400, 50);
    enemiesOnScreen[0][1][4].setPosition(495, 50);
    enemiesOnScreen[0][1][5].setPosition(590, 50);
    enemiesOnScreen[0][1][6].setPosition(175, 130);
    enemiesOnScreen[0][1][7].setPosition(545, 130);
    enemiesOnScreen[0][1][8].setPosition(225, 210);
    enemiesOnScreen[0][1][9].setPosition(495, 210);
    enemiesOnScreen[0][1][10].setPosition(275, 280);
    enemiesOnScreen[0][1][11].setPosition(465, 280);
    enemiesOnScreen[0][1][12].setPosition(315, 360);
    enemiesOnScreen[0][1][13].setPosition(435, 360);
    enemiesOnScreen[0][1][14].setPosition(370, 430);

    // Setting up Cross - 17 Shapes
    enemiesOnScreen[0][2][0].setPosition(465, 150);
    enemiesOnScreen[0][2][1].setPosition(565, 100);
    enemiesOnScreen[0][2][2].setPosition(665, 50);
    enemiesOnScreen[0][2][3].setPosition(65, 50);
    enemiesOnScreen[0][2][4].setPosition(165, 100);
    enemiesOnScreen[0][2][5].setPosition(265, 150);
    enemiesOnScreen[0][2][6].setPosition(365, 100);
    enemiesOnScreen[0][2][7].setPosition(125, 200);
    enemiesOnScreen[0][2][8].setPosition(368, 200);
    enemiesOnScreen[0][2][9].setPosition(605, 200);
    enemiesOnScreen[0][2][10].setPosition(365, 300);
    enemiesOnScreen[0][2][11].setPosition(265, 250);
    enemiesOnScreen[0][2][12].setPosition(165, 300);
    enemiesOnScreen[0][2][13].setPosition(65, 350);
    enemiesOnScreen[0][2][14].setPosition(465, 250);
    enemiesOnScreen[0][2][15].setPosition(565, 300);
    enemiesOnScreen[0][2][16].setPosition(665, 350);


    //// LEVEL 2

        // Setting up Hollow Circle - 15 Shapes
    enemiesOnScreen[1][0][0].setPosition(360, 25);
    enemiesOnScreen[1][0][1].setPosition(427, 43);
    enemiesOnScreen[1][0][2].setPosition(484, 87);
    enemiesOnScreen[1][0][3].setPosition(522, 150);
    enemiesOnScreen[1][0][4].setPosition(522, 225);
    enemiesOnScreen[1][0][5].setPosition(484, 288);
    enemiesOnScreen[1][0][6].setPosition(427, 332);
    enemiesOnScreen[1][0][7].setPosition(360, 350);
    enemiesOnScreen[1][0][8].setPosition(293, 332);
    enemiesOnScreen[1][0][9].setPosition(236, 288);
    enemiesOnScreen[1][0][10].setPosition(198, 225);
    enemiesOnScreen[1][0][11].setPosition(198, 150);
    enemiesOnScreen[1][0][12].setPosition(236, 87);
    enemiesOnScreen[1][0][13].setPosition(293, 43);
    enemiesOnScreen[1][0][14].setPosition(365, 192);

    // Setting up Hollow Diamond - 20 Shapes
    enemiesOnScreen[1][1][0].setPosition(115, 130);
    enemiesOnScreen[1][1][1].setPosition(215, 130);
    enemiesOnScreen[1][1][2].setPosition(165, 100);
    enemiesOnScreen[1][1][3].setPosition(565, 100);
    enemiesOnScreen[1][1][4].setPosition(515, 130);
    enemiesOnScreen[1][1][5].setPosition(615, 130);
    enemiesOnScreen[1][1][6].setPosition(165, 180);
    enemiesOnScreen[1][1][7].setPosition(200, 230);
    enemiesOnScreen[1][1][8].setPosition(285, 65);
    enemiesOnScreen[1][1][9].setPosition(365, 65);
    enemiesOnScreen[1][1][10].setPosition(565, 180);
    enemiesOnScreen[1][1][11].setPosition(265, 280);
    enemiesOnScreen[1][1][12].setPosition(530, 230);
    enemiesOnScreen[1][1][13].setPosition(465, 280);
    enemiesOnScreen[1][1][14].setPosition(400, 310);
    enemiesOnScreen[1][1][15].setPosition(230, 65);
    enemiesOnScreen[1][1][16].setPosition(335, 310);
    enemiesOnScreen[1][1][17].setPosition(430, 65);
    enemiesOnScreen[1][1][18].setPosition(365, 365);
    enemiesOnScreen[1][1][19].setPosition(495, 65);

    // Setting up Hollow Heart - 20 Shapes
    enemiesOnScreen[1][2][0].setPosition(115, 200);
    enemiesOnScreen[1][2][1].setPosition(155, 45);
    enemiesOnScreen[1][2][2].setPosition(240, 50);
    enemiesOnScreen[1][2][3].setPosition(480, 55);
    enemiesOnScreen[1][2][4].setPosition(569, 48);
    enemiesOnScreen[1][2][5].setPosition(590, 200);
    enemiesOnScreen[1][2][6].setPosition(175, 280);
    enemiesOnScreen[1][2][7].setPosition(560, 280);
    enemiesOnScreen[1][2][8].setPosition(225, 360);
    enemiesOnScreen[1][2][9].setPosition(530, 360);
    enemiesOnScreen[1][2][10].setPosition(275, 430);
    enemiesOnScreen[1][2][11].setPosition(480, 430);
    enemiesOnScreen[1][2][12].setPosition(315, 510);
    enemiesOnScreen[1][2][13].setPosition(435, 510);
    enemiesOnScreen[1][2][14].setPosition(370, 580);
    enemiesOnScreen[1][2][15].setPosition(115, 125);
    enemiesOnScreen[1][2][16].setPosition(305, 125);
    enemiesOnScreen[1][2][17].setPosition(400, 125);
    enemiesOnScreen[1][2][18].setPosition(610, 125);
    enemiesOnScreen[1][2][19].setPosition(360, 210);


    //// LEVEL 3


        // Setting up Filled Rectangle - 24 Shapes
    enemiesOnScreen[2][0][0].setPosition(115, 25);
    enemiesOnScreen[2][0][1].setPosition(115, 125);
    enemiesOnScreen[2][0][2].setPosition(115, 225);
    enemiesOnScreen[2][0][3].setPosition(115, 325);
    enemiesOnScreen[2][0][4].setPosition(215, 25);
    enemiesOnScreen[2][0][5].setPosition(215, 125);
    enemiesOnScreen[2][0][6].setPosition(215, 225);
    enemiesOnScreen[2][0][7].setPosition(215, 325);
    enemiesOnScreen[2][0][8].setPosition(315, 25);
    enemiesOnScreen[2][0][9].setPosition(315, 125);
    enemiesOnScreen[2][0][10].setPosition(315, 225);
    enemiesOnScreen[2][0][11].setPosition(315, 325);
    enemiesOnScreen[2][0][12].setPosition(415, 25);
    enemiesOnScreen[2][0][13].setPosition(415, 125);
    enemiesOnScreen[2][0][14].setPosition(415, 225);
    enemiesOnScreen[2][0][15].setPosition(415, 325);
    enemiesOnScreen[2][0][16].setPosition(515, 25);
    enemiesOnScreen[2][0][17].setPosition(515, 125);
    enemiesOnScreen[2][0][18].setPosition(515, 225);
    enemiesOnScreen[2][0][19].setPosition(515, 325);
    enemiesOnScreen[2][0][20].setPosition(615, 25);
    enemiesOnScreen[2][0][21].setPosition(615, 125);
    enemiesOnScreen[2][0][22].setPosition(615, 225);
    enemiesOnScreen[2][0][23].setPosition(615, 325);

    // Setting up Filled Inverted Triangle - 25 Shapes
    enemiesOnScreen[2][1][0].setPosition(-50, 50);
    enemiesOnScreen[2][1][1].setPosition(50, 50);
    enemiesOnScreen[2][1][2].setPosition(150, 50);
    enemiesOnScreen[2][1][3].setPosition(250, 50);
    enemiesOnScreen[2][1][4].setPosition(350, 50);
    enemiesOnScreen[2][1][5].setPosition(450, 50);
    enemiesOnScreen[2][1][6].setPosition(550, 50);
    enemiesOnScreen[2][1][7].setPosition(650, 50);
    enemiesOnScreen[2][1][8].setPosition(750, 50);
    enemiesOnScreen[2][1][9].setPosition(50, 150);
    enemiesOnScreen[2][1][10].setPosition(150, 150);
    enemiesOnScreen[2][1][11].setPosition(250, 150);
    enemiesOnScreen[2][1][12].setPosition(350, 150);
    enemiesOnScreen[2][1][13].setPosition(450, 150);
    enemiesOnScreen[2][1][14].setPosition(550, 150);
    enemiesOnScreen[2][1][15].setPosition(650, 150);
    enemiesOnScreen[2][1][16].setPosition(150, 250);
    enemiesOnScreen[2][1][17].setPosition(250, 250);
    enemiesOnScreen[2][1][18].setPosition(350, 250);
    enemiesOnScreen[2][1][19].setPosition(450, 250);
    enemiesOnScreen[2][1][20].setPosition(550, 250);
    enemiesOnScreen[2][1][21].setPosition(250, 350);
    enemiesOnScreen[2][1][22].setPosition(350, 350);
    enemiesOnScreen[2][1][23].setPosition(450, 350);
    enemiesOnScreen[2][1][24].setPosition(350, 450);

    // Setting up Cross - 25 Shapes
    enemiesOnScreen[2][2][0].setPosition(765, 0); // Top Right Four
    enemiesOnScreen[2][2][1].setPosition(665, 50); // Top Right Three
    enemiesOnScreen[2][2][2].setPosition(565, 100); // Top Right Two
    enemiesOnScreen[2][2][3].setPosition(465, 150); // Top Right
    enemiesOnScreen[2][2][4].setPosition(-35, 0); // Top Left Four
    enemiesOnScreen[2][2][5].setPosition(65, 50); // Top Left Three
    enemiesOnScreen[2][2][6].setPosition(165, 100); // Top Left Two
    enemiesOnScreen[2][2][7].setPosition(265, 150); // Top Left
    enemiesOnScreen[2][2][8].setPosition(365, 0); // Up Two
    enemiesOnScreen[2][2][9].setPosition(365, 100); // Up One
    enemiesOnScreen[2][2][10].setPosition(25, 200); // Left Two
    enemiesOnScreen[2][2][11].setPosition(140, 200); // Left One
    enemiesOnScreen[2][2][12].setPosition(368, 200); // Center
    enemiesOnScreen[2][2][13].setPosition(590, 200); // Right One
    enemiesOnScreen[2][2][14].setPosition(705, 200); // Right Two
    enemiesOnScreen[2][2][15].setPosition(365, 300); // Down One
    enemiesOnScreen[2][2][16].setPosition(365, 400); // Down Two
    enemiesOnScreen[2][2][17].setPosition(265, 250); // Bottom Left
    enemiesOnScreen[2][2][18].setPosition(165, 300); // Bottom Left Two
    enemiesOnScreen[2][2][19].setPosition(65, 350); // Bottom Left Three
    enemiesOnScreen[2][2][20].setPosition(-35, 400); // Bottom Left Four
    enemiesOnScreen[2][2][21].setPosition(465, 250); // Bottom Right
    enemiesOnScreen[2][2][22].setPosition(565, 300); // Bottom Right Two
    enemiesOnScreen[2][2][23].setPosition(665, 350); // Bottom Right Three
    enemiesOnScreen[2][2][24].setPosition(765, 400); // Bottom Right Four

    // Setting up Filled Circle - 27 Shapes
    enemiesOnScreen[2][3][0].setPosition(450, 250);
    enemiesOnScreen[2][3][1].setPosition(445, 284);
    enemiesOnScreen[2][3][2].setPosition(434, 317);
    enemiesOnScreen[2][3][3].setPosition(414, 346);
    enemiesOnScreen[2][3][4].setPosition(389, 370);
    enemiesOnScreen[2][3][5].setPosition(359, 387);
    enemiesOnScreen[2][3][6].setPosition(326, 397);
    enemiesOnScreen[2][3][7].setPosition(291, 399);
    enemiesOnScreen[2][3][8].setPosition(256, 393);
    enemiesOnScreen[2][3][9].setPosition(250, 336);
    enemiesOnScreen[2][3][10].setPosition(231, 322);
    enemiesOnScreen[2][3][11].setPosition(216, 304);
    enemiesOnScreen[2][3][12].setPosition(206, 284);
    enemiesOnScreen[2][3][13].setPosition(200, 261);
    enemiesOnScreen[2][3][14].setPosition(200, 238);
    enemiesOnScreen[2][3][15].setPosition(206, 215);
    enemiesOnScreen[2][3][16].setPosition(216, 195);
    enemiesOnScreen[2][3][17].setPosition(231, 177);
    enemiesOnScreen[2][3][18].setPosition(275, 206);
    enemiesOnScreen[2][3][19].setPosition(285, 202);
    enemiesOnScreen[2][3][20].setPosition(297, 200);
    enemiesOnScreen[2][3][21].setPosition(308, 200);
    enemiesOnScreen[2][3][22].setPosition(319, 204);
    enemiesOnScreen[2][3][23].setPosition(329, 209);
    enemiesOnScreen[2][3][24].setPosition(338, 217);
    enemiesOnScreen[2][3][25].setPosition(344, 227);
    enemiesOnScreen[2][3][26].setPosition(348, 238);



    // Setting up Filled Heart - 29
    enemiesOnScreen[2][4][0].setPosition(100, 95);
    enemiesOnScreen[2][4][1].setPosition(50, 170);
    enemiesOnScreen[2][4][2].setPosition(150, 170);
    enemiesOnScreen[2][4][3].setPosition(250, 170);
    enemiesOnScreen[2][4][4].setPosition(200, 95);
    enemiesOnScreen[2][4][5].setPosition(450, 170);
    enemiesOnScreen[2][4][6].setPosition(550, 170);
    enemiesOnScreen[2][4][7].setPosition(650, 170);
    enemiesOnScreen[2][4][8].setPosition(600, 95);
    enemiesOnScreen[2][4][9].setPosition(50, 270);
    enemiesOnScreen[2][4][10].setPosition(150, 270);
    enemiesOnScreen[2][4][11].setPosition(250, 270);
    enemiesOnScreen[2][4][12].setPosition(350, 270);
    enemiesOnScreen[2][4][13].setPosition(450, 270);
    enemiesOnScreen[2][4][25].setPosition(500, 95);
    enemiesOnScreen[2][4][14].setPosition(550, 270);
    enemiesOnScreen[2][4][15].setPosition(650, 270);
    enemiesOnScreen[2][4][16].setPosition(150, 370);
    enemiesOnScreen[2][4][17].setPosition(250, 370);
    enemiesOnScreen[2][4][18].setPosition(350, 370);
    enemiesOnScreen[2][4][19].setPosition(450, 370);
    enemiesOnScreen[2][4][20].setPosition(550, 370);
    enemiesOnScreen[2][4][21].setPosition(250, 470);
    enemiesOnScreen[2][4][22].setPosition(350, 470);
    enemiesOnScreen[2][4][23].setPosition(450, 470);
    enemiesOnScreen[2][4][24].setPosition(350, 570);
    enemiesOnScreen[2][4][26].setPosition(350, 195);
    enemiesOnScreen[2][4][27].setPosition(150, 20);
    enemiesOnScreen[2][4][28].setPosition(550, 20);


    // Setting up Filled Diamond - 30 Shapes
    enemiesOnScreen[2][5][0].setPosition(230, 65);
    enemiesOnScreen[2][5][1].setPosition(285, 65);
    enemiesOnScreen[2][5][2].setPosition(365, 65);
    enemiesOnScreen[2][5][3].setPosition(430, 65);
    enemiesOnScreen[2][5][4].setPosition(495, 65);
    enemiesOnScreen[2][5][5].setPosition(165, 100);
    enemiesOnScreen[2][5][6].setPosition(565, 100);
    enemiesOnScreen[2][5][7].setPosition(285, 115);
    enemiesOnScreen[2][5][8].setPosition(360, 115);
    enemiesOnScreen[2][5][9].setPosition(430, 115);
    enemiesOnScreen[2][5][10].setPosition(285, 240);
    enemiesOnScreen[2][5][11].setPosition(365, 240);
    enemiesOnScreen[2][5][12].setPosition(430, 240);
    enemiesOnScreen[2][5][13].setPosition(115, 130);
    enemiesOnScreen[2][5][14].setPosition(215, 130);
    enemiesOnScreen[2][5][15].setPosition(515, 130);
    enemiesOnScreen[2][5][16].setPosition(615, 130);
    enemiesOnScreen[2][5][17].setPosition(165, 180);
    enemiesOnScreen[2][5][18].setPosition(565, 180);
    enemiesOnScreen[2][5][19].setPosition(320, 180);
    enemiesOnScreen[2][5][20].setPosition(410, 180);
    enemiesOnScreen[2][5][21].setPosition(250, 180);
    enemiesOnScreen[2][5][22].setPosition(480, 180);
    enemiesOnScreen[2][5][23].setPosition(200, 230);
    enemiesOnScreen[2][5][24].setPosition(530, 230);
    enemiesOnScreen[2][5][25].setPosition(465, 280);
    enemiesOnScreen[2][5][26].setPosition(265, 280);
    enemiesOnScreen[2][5][27].setPosition(400, 310);
    enemiesOnScreen[2][5][28].setPosition(335, 310);
    enemiesOnScreen[2][5][29].setPosition(365, 365);



    sf::RenderWindow window(sf::VideoMode(800, 800), "TestingShapes");
    sf::Clock clock;
    float timeDelay = 2.0f;
    int currentStage = 0, currentLevel = 0;

    while (window.isOpen()) {
        sf::Time elapsed = clock.getElapsedTime();
        // Check if the time delay has elapsed
        if (elapsed.asSeconds() >= timeDelay) {
            clock.restart(); // Reset the clock

            // Clear the screen and redraw the shapes for the current stage
            window.clear();
            for (int k = 0; k < ENEMIES_PER_STAGE[currentLevel][currentStage]; k++) {
                window.draw(enemiesOnScreen[currentLevel][currentStage][k]);
            }
            window.display();

            // Increment to the next stage
            currentStage++;

            // If we've gone through all the stages in this level
            if (currentStage >= STAGES_PER_LEVEL[currentLevel]) {
                // Wait for a delay before moving to the next level
                sf::sleep(sf::seconds(timeDelay));
                currentStage = 0;
                currentLevel++;

                // If we've gone through all the levels
                if (currentLevel >= 3) {
                    // Exit the loop and close the window
                    window.close();
                }
            }
        }
    }

    return 0;
}
#pragma once
#include "game.h"
#include <ctime>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Highscores.h"

using namespace sf;

class HighScores {

};


class Menu {
public:
    //add menu attributes here
    Font font;
    Text title;
    Text crawlText;
    Text options[4];
    Sprite leftWing;
    Sprite rightWing;
    SoundBuffer buffer;
    Sound sound;
    Game g;

    Menu();
    void display_menu();
};

Menu::Menu()
{
    font.loadFromFile("assets/spaceage.ttf");
    title.setFont(font);
    title.setString("SPACE INVADER");
    title.setCharacterSize(72);
    title.setFillColor(Color::White);
    title.setPosition(200, 300);

    font.loadFromFile("assets/TradeGothicBold.ttf");
    crawlText.setFont(font);
    crawlText.setString("IT IS A PERIOD OF CIVIL WAR...");
    crawlText.setCharacterSize(24);
    crawlText.setFillColor(Color::Yellow);
    crawlText.setPosition(275, 400);

    options[0].setFont(font);
    options[0].setString("New Game");
    options[0].setCharacterSize(48);
    options[0].setFillColor(Color::White);
    options[0].setPosition(300, 400);

    options[1].setFont(font);
    options[1].setString("Continue Game");
    options[1].setCharacterSize(48);
    options[1].setFillColor(Color::White);
    options[1].setPosition(250, 475);

    options[2].setFont(font);
    options[2].setString("Highscores");
    options[2].setCharacterSize(48);
    options[2].setFillColor(Color::White);
    options[2].setPosition(295, 550);

    options[3].setFont(font);
    options[3].setString("Exit");
    options[3].setCharacterSize(48);
    options[3].setFillColor(Color::White);
    options[3].setPosition(363, 625);

    Texture tex;
    tex.loadFromFile("img/PNG/ufoBlue.png");
    leftWing.setTexture(tex);
    //leftWing.setPosition(0, 400);

    tex.loadFromFile("img/PNG/ufoBlue.png");
    rightWing.setTexture(tex);
    //rightWing.setPosition(700, 400);

    buffer.loadFromFile("assets/selectOption.wav");
    sound.setBuffer(buffer);
}


std::string Name()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Name Input");
    sf::Font font;
    font.loadFromFile("assets/Plaguard.otf");

    sf::Text promptText("PLEASE ENTER YOUR NAME:", font, 36);
    promptText.setFillColor(sf::Color::White);
    promptText.setPosition(10, 10);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 60);

    std::string name;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == '\b' && !name.empty()) {
                        name.pop_back(); // Handle backspace
                    }
                    else if (event.text.unicode == '\r') {
                        // Handle Enter key pressed
                        std::cout << "Entered name: " << name << std::endl;
                        window.close();
                    }
                    else {
                        name += static_cast<char>(event.text.unicode); // Append entered character
                    }
                    text.setString(name); // Update displayed text
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(promptText);
        window.draw(text);
        window.display();
    }

    return name;
}



void Menu::display_menu() {
    RenderWindow window(VideoMode(800, 800), "Space Shooter");

    // Load the custom cursor image
    Image cursorImage;
    cursorImage.loadFromFile("img/PNG/UI/cursor.png");
    Cursor cursor;
    cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), { 0, 0 });
    window.setMouseCursor(cursor);

    // Print large "SPACE SHOOTER" text centered on screen
    FloatRect titleRect = title.getLocalBounds();
    title.setPosition(400 - titleRect.width / 2, 100);

    // Play crawl text
    crawlText.setString(R"(
Our         galaxy      is         attacked by  enemies.

The enemy invaders beat our squad, they destroyed all of

galactica.     

Space team  is  waiting   for your order.

Please command       the      ship to protect the galaxy

and     the                  surrounding      asteroids.

)");

    crawlText.setFillColor(Color::Yellow);
    crawlText.setCharacterSize(24);
    crawlText.setPosition(400, 700);
    crawlText.setOrigin(crawlText.getLocalBounds().width / 2, 0);

    float crawlSpeed = 1.0f;
    float crawlPosY = 800.0;

    
    while (crawlText.getPosition().y > -crawlText.getLocalBounds().height) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Update crawl text position
        crawlPosY -= crawlSpeed;
        crawlText.setPosition(400, crawlPosY);

        // Clear window and draw objects
        window.clear();
        window.draw(crawlText);
        window.draw(title);
        window.display();

    }

    Clock clock;
    RectangleShape fade;
    fade.setPosition(Vector2f(0, 0));
    fade.setFillColor(Color(0, 0, 0, 0));
    fade.setSize(Vector2f(800, 600));
    for (int i = 0; i <= 255; i++) {
        fade.setFillColor(Color(0, 0, 0, i));
        window.draw(fade);
        window.display();
        sleep(seconds(0.01));
        clock.restart();
    }

    //sleep(seconds(0.2));

    for (int i = 255; i >= 0; i--) {
        fade.setFillColor(Color(0, 0, 0, i));
        window.draw(fade);
        window.display();
        //sleep(seconds(0.1));
        clock.restart();
    }

    // Undim screen and display menu options
    int selectedOption = 0;
    Text tempOptions[4];
    for (int i = 0; i < 4; i++) {
        tempOptions[i] = options[i];
    }
    tempOptions[selectedOption].setFillColor(Color::Cyan);

    std::string playerName;
    while (window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    sound.play();
                    if (selectedOption > 0) {
                        selectedOption--;
                    }
                }
                if (event.key.code == Keyboard::Down) {
                    sound.play();
                    if (selectedOption < 3) {
                        selectedOption++;
                    }
                }
                if (event.key.code == Keyboard::Return) {
                    switch (selectedOption) {
                    case 0:
                        window.close();
                        playerName = Name();
                        g.start_game(playerName);
                        break;
                    case 1:
                        // Continue game
                        break;
                    case 2:
                        displayHighScores();
                        break;
                    case 3:
                        // Exit
                        window.close();
                        break;
                    }
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePosition = Mouse::getPosition(window);
                    // Option 0
                    if (mousePosition.x >= options[0].getPosition().x && mousePosition.x <= options[0].getPosition().x + options[0].getLocalBounds().width &&
                        mousePosition.y >= options[0].getPosition().y && mousePosition.y <= options[0].getPosition().y + options[0].getLocalBounds().height) {
                        window.close();
                        playerName = Name();
                        g.start_game(playerName);
                    }

                    // Option 1
                    if (mousePosition.x >= options[1].getPosition().x && mousePosition.x <= options[1].getPosition().x + options[1].getLocalBounds().width &&
                        mousePosition.y >= options[1].getPosition().y && mousePosition.y <= options[1].getPosition().y + options[1].getLocalBounds().height) {
                        // Handle "Continue Game" option
                    }

                    // Option 2
                    if (mousePosition.x >= options[2].getPosition().x && mousePosition.x <= options[2].getPosition().x + options[2].getLocalBounds().width &&
                        mousePosition.y >= options[2].getPosition().y && mousePosition.y <= options[2].getPosition().y + options[2].getLocalBounds().height) {
                        // Handle "Highscores" option
                    }

                    // Option 3
                    if (mousePosition.x >= options[3].getPosition().x && mousePosition.x <= options[3].getPosition().x + options[3].getLocalBounds().width &&
                        mousePosition.y >= options[3].getPosition().y && mousePosition.y <= options[3].getPosition().y + options[3].getLocalBounds().height) {
                        window.close();
                    }
                }
            }
        }

        // Update selected option's color
        for (int i = 0; i < 4; i++) {
            if (i == selectedOption) {
                tempOptions[i].setFillColor(Color::Cyan);
            }
            else {
                tempOptions[i].setFillColor(Color::White);
            }
        }

        // Draw menu options with glowing effect around selected option
        window.clear();
        window.draw(title);
        for (int i = 0; i < 4; i++) {
            if (i == selectedOption) {
                options[i].setFillColor(Color::Cyan);
            }
            else {
                options[i].setFillColor(Color::White);
            }
            window.draw(options[i]);
        }

        //// Move ship sprite with selected option
        //float shipPosY = options[selectedOption].getPosition().y - 50;
        //float shipPosX = options[selectedOption].getPosition().x;
        //leftWing.setPosition(shipPosX-50, shipPosY);
        //rightWing.setPosition(shipPosX+250, shipPosY);
        //leftWing.setScale(Vector2f(0.75f, 0.8f));
        //rightWing.setScale(Vector2f(0.75f, 0.8f));
        ////window.draw(leftWing);
        ////window.draw(rightWing);
        
        window.display();
    }
}

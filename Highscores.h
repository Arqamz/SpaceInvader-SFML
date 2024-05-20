#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

void displayHighScores() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "High Scores");
    sf::Font font;

    sf::Texture Badge1Tex;
    sf::Texture Badge2Tex;
    sf::Texture Badge3Tex;

    Badge1Tex.loadFromFile("img/badge1.png");
    Badge2Tex.loadFromFile("img/badge2.png");
    Badge3Tex.loadFromFile("img/badge3.png");

    sf::Sprite Badge1(Badge1Tex);
    sf::Sprite Badge2(Badge2Tex);
    sf::Sprite Badge3(Badge3Tex);
    Badge1.setScale(0.05f, 0.02f);
    Badge2.setScale(0.05f, 0.1f);
    Badge3.setScale(0.05f, 0.05f);
    
    if (!font.loadFromFile("assets/BruceForeverRegular-X3jd2.ttf")) {
        // Failed to load font, handle the error
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setPosition(100,60);

    Badge1.setPosition(50, 60);
    Badge2.setPosition(50, 100);
    Badge3.setPosition(50, 180);

    std::ifstream inputFile("highscores.txt");
    std::string line;
    std::string highScoresText;

    while (std::getline(inputFile, line)) {
        highScoresText += line + "\n";
    }

    text.setString(highScoresText);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.draw(Badge1);
        window.draw(Badge2);
        window.draw(Badge3);
        window.display();
    }
}

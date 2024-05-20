#pragma once

#include <iostream>
#include <fstream>
#include <sstream>


struct PlayerScores {
    std::string name;
    int score;
};

void updateTopScores(const std::string& playerName, int playerScore) {
    const std::string fileName = "highscores.txt";
    const int maxScores = 10;

    // Read the current top scores from the file
    std::ifstream inputFile(fileName);
    PlayerScores topScores[maxScores];
    int numScores = 0;
    std::string line;
    while (getline(inputFile, line) && numScores < maxScores) {
        std::istringstream iss(line);
        iss >> topScores[numScores].name >> topScores[numScores].score;
        numScores++;
    }
    inputFile.close();

    // Add the current player's score to the top scores
    topScores[numScores].name = playerName;
    topScores[numScores].score = playerScore;
    numScores++;

    // Sort the scores in descending order (simple bubble sort)
    for (int i = 0; i < numScores - 1; i++) {
        for (int j = 0; j < numScores - i - 1; j++) {
            if (topScores[j].score < topScores[j + 1].score) {
                PlayerScores temp = topScores[j];
                topScores[j] = topScores[j + 1];
                topScores[j + 1] = temp;
            }
        }
    }

    // Write the updated scores back to the file
    std::ofstream outputFile(fileName);
    for (int i = 0; i < numScores && i < maxScores; i++) {
        outputFile << topScores[i].name << " " << topScores[i].score << std::endl;
    }
    outputFile.close();
}
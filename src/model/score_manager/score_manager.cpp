/**
 * @file score.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the score class
 * @date 16/11/2024
 *
 */

#include "score_manager.hpp"

#include <fstream>
#include <iostream>
#include <string>

const std::string ScoreManager::bestScoreFilePath_ = "score.txt";

ScoreManager::ScoreManager() : currentScore_(DEFAULT_SCORE) {
    std::ifstream read(bestScoreFilePath_, std::ios::in);

    bestScore_ = DEFAULT_SCORE;

    if (read.is_open()) {
        read >> bestScore_;
        read.close();
    }
}

void ScoreManager::increaseScore(unsigned long value) {
    currentScore_ += value;
}

void ScoreManager::resetScore() { currentScore_ = DEFAULT_SCORE; }

void ScoreManager::writeInBestScoreFile(const std::string &content) {
    std::ofstream file(bestScoreFilePath_, std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        file << content << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Can't open the file" << std::endl;
    }
}

void ScoreManager::saveScore() {
    if (currentScore_ < bestScore_) {
        return;
    }

    bestScore_ = currentScore_;

    writeInBestScoreFile(std::to_string(getCurrentScore()));
}

void ScoreManager::resetBestScore() {
    bestScore_ = DEFAULT_SCORE;

    writeInBestScoreFile("0");
}

unsigned long ScoreManager::getCurrentScore() const { return currentScore_; }

unsigned long ScoreManager::getBestScore() const { return bestScore_; }

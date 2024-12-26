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

// TODO: remove "score.txt" magic variable
// maybe make the controller decide where this one should write and read the
// best-score ?

// ### Constructors ###

ScoreManager::ScoreManager() : currentScore_(DEFAULT_SCORE) {
    // setup bestScore_ variable
    std::string filePath = "score.txt";

    std::ifstream read(filePath, std::ios::in);

    bestScore_ = 0;

    if (read.is_open()) {
        read >> bestScore_;
        read.close();
    }
}

// #### Score Actions ####

void ScoreManager::increaseScore(unsigned long value) {
    currentScore_ += value;
}

void ScoreManager::resetScore() { currentScore_ = 0; }

void ScoreManager::saveScore() {
    if (currentScore_ < bestScore_) {
        return;
    }

    std::string filePath = "score.txt";
    std::ofstream write(filePath, std::ios::out | std::ios::trunc);

    if (write.is_open()) {
        write << getCurrentScore() << std::endl;
        write.close();
    } else {
        std::cerr << "Error: Can't open the file" << std::endl;
    }
}

void ScoreManager::setScore0() {
    std::string filePath = "score.txt";

    std::ofstream file(filePath, std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        file.put('0'); // Erase the content of the file and write 0
        file.close();
    } else {
        std::cerr << "Error: Can't open the file" << std::endl;
    }
}

// ### Getters ###

unsigned long ScoreManager::getCurrentScore() const { return currentScore_; }

unsigned long ScoreManager::getBestScore() const { return bestScore_; }

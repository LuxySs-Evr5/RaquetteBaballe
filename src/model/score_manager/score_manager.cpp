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
// record-score ?

// ### Constructors ###

ScoreManager::ScoreManager() : currentScore_(DEFAULT_SCORE) {
    // setup recordScore_ variable
    std::string filePath = "score.txt";

    std::ifstream read(filePath, std::ios::in);

    recordScore_ = 0;

    if (read.is_open()) {
        read >> recordScore_;
        read.close();
    }
}

// ### Destructor ###

ScoreManager::~ScoreManager() = default;

// #### Score Actions ####

void ScoreManager::increaseScore(int value) { currentScore_ += value; }

void ScoreManager::resetScore() { currentScore_ = 0; }

void ScoreManager::saveScore() {
    if (currentScore_ < recordScore_) {
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

int ScoreManager::getCurrentScore() const { return currentScore_; }

int ScoreManager::getRecordScore() const { return recordScore_; }

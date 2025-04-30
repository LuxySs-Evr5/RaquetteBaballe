/**
 * @file level_manager.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define class LevelManager
 * @date 16/12/2024
 *
 */

#include "level_manager.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

LevelManager::LevelManager() {
    // Create the racket
    racket_ = make_shared<Racket>(
        Vec2{BOARD_WIDTH / 2 + WALL_THICKNESS, RACKET_Y_POSITION}, RACKET_WIDTH,
        RACKET_HEIGHT); // + BOARD_BOUNDINGS_THICKNESS because
                        // the board has a left border

    // Left wall
    borders_.emplace_back(
        make_shared<Border>(Vec2{0, BOARD_HEIGHT}, Vec2{WALL_THICKNESS, 0}));
    // Top wall
    borders_.emplace_back(make_shared<Border>(
        Vec2{0, BOARD_HEIGHT},
        Vec2{BOARD_WIDTH + WALL_THICKNESS, BOARD_HEIGHT - WALL_THICKNESS}));
    // Right wall
    borders_.emplace_back(
        make_shared<Border>(Vec2{SCREEN_WIDTH - WALL_THICKNESS, BOARD_HEIGHT},
                            Vec2{SCREEN_WIDTH, 0}));

    loadBricks();
}

AbstractBrick::Color convertColorFromString(const string &colorName) {
    /**
     * @brief Translate the color name to the corresponding AbstractBrick::Color
     *
     * @param colorName The color name
     * @return The corresponding Color
     */
    static const unordered_map<string, AbstractBrick::Color> colorMap = {
        {"defaultBrick", AbstractBrick::Color::defaultBrick},
        {"white", AbstractBrick::Color::white},
        {"orange", AbstractBrick::Color::orange},
        {"cyan", AbstractBrick::Color::cyan},
        {"green", AbstractBrick::Color::green},
        {"red", AbstractBrick::Color::red},
        {"blue", AbstractBrick::Color::blue},
        {"magenta", AbstractBrick::Color::magenta},
        {"yellow", AbstractBrick::Color::yellow},
        {"silver", AbstractBrick::Color::silver},
        {"gold", AbstractBrick::Color::gold}};
    auto it = colorMap.find(colorName);
    if (it != colorMap.end()) {
        return it->second;
    }
    cerr << "Unknown color name" << endl;
    exit(1);
}

BonusType convertBonusFromString(const string &bonusName) {
    /**
     * @brief Translate the bonus name to the corresponding BonusType
     *
     * @param bonusName The name of the bonus
     * @return The corresponding BonusType
     */
    static const unordered_map<string, BonusType> bonusMap = {
        {"None", BonusType::None},
        {"SlowDown", BonusType::SlowDown},
        {"ExtraLife", BonusType::ExtraLife},
        {"WideRacket", BonusType::WideRacket},
        {"StickyRacket", BonusType::StickyRacket},
        {"SplitBall", BonusType::SplitBall},
        {"Lazer", BonusType::Lazer},
    };
    auto it = bonusMap.find(bonusName);
    if (it != bonusMap.end()) {
        return it->second;
    }
    cerr << "Unknown bonus name: " << bonusName << endl;
    exit(1);
}

/**
 * @brief Extract the number from a string
 *
 * @param filename The string to extract the number from
 * @return The number extracted from the string
 */
int extractNumber(const string &filename) {
    string num;
    for (char c : filename) {
        if (isdigit(c)) {
            num += c;
        }
    }
    return stoi(num); // Convert the string to an int
}

/**
 * @brief Compare two files by their number
 *
 * @param a String of the first file
 * @param b String of the second file
 * @return true if a < b
 * @return false if a >= b
 */
bool compareFiles(const string &a, const string &b) {
    return extractNumber(a) < extractNumber(b);
}

void LevelManager::loadBricks() {
    vector<string> levelFiles; // Store the paths of the level files

    // Get all the files in the levels directory and store them in the vector
    for (const auto &entry : filesystem::directory_iterator(PATH_TO_LEVELS)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            levelFiles.push_back(entry.path().string());
        }
    }

    // Sort the files by name (level number)
    sort(levelFiles.begin(), levelFiles.end(), compareFiles);

    for (const auto &filename : levelFiles) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file " << filename << endl;
            exit(1);
        }

        vector<shared_ptr<AbstractBrick>> bricks;

        // Read the file line by line and create a brick to add to the vector
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            double x, y;
            string color;
            string bonus;
            if (!(iss >> x >> y >> color)) {
                cerr << "Failed to read line" << endl;
                exit(1);
            }

            // Check if there's a 4th column for bonus
            if (!(iss >> bonus)) {
                bonus = "None"; // No bonus provided, keep it as default
            }

            x += WALL_THICKNESS; // because the board has a left border
            y += WALL_THICKNESS; // because the board has a top border
            bricks.emplace_back(AbstractBrick::makeBrick(
                Vec2{x, y}, BRICK_WIDTH, BRICK_HEIGHT,
                convertColorFromString(color), convertBonusFromString(bonus)));
        }
        bricksPerLevel_.emplace_back(bricks);
        file.close();
    }
}

void LevelManager::nextLevel() {
    if (currentLevel_ < bricksPerLevel_.size() - 1) {
        ++currentLevel_;
    }
}

void LevelManager::previousLevel() {
    if (currentLevel_ > 0) {
        --currentLevel_;
    }
}

const vector<shared_ptr<AbstractBrick>> &LevelManager::getBricks() {
    return bricksPerLevel_[currentLevel_];
}

const shared_ptr<Racket> LevelManager::getRacket() const { return racket_; }

const vector<shared_ptr<Border>> &LevelManager::getBorders() const {
    return borders_;
}

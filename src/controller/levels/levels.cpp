/**
 * @file levels.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define struct Levels
 * @date 16/12/2024
 *
 */

#include "levels.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// TODO: set + BOARD_BOUNDINGS_THICKNESS in model for the ball, racket and brick
// if needed

// ### Constructor ###
Levels::Levels() {
    // Left wall
    levelBorders_.emplace_back(Border(
        BoundingBox{Vec2{0, BOARD_HEIGHT - 1}, Vec2{WALL_THICKNESS - 1, 0}}));
    // Top wall
    levelBorders_.emplace_back(Border(BoundingBox{
        Vec2{0, BOARD_HEIGHT - 1}, Vec2{BOARD_WIDTH + WALL_THICKNESS - 1,
                                        BOARD_HEIGHT - WALL_THICKNESS - 1}}));
    // Right wall
    levelBorders_.emplace_back(Border(
        BoundingBox{Vec2{BOARD_WIDTH + WALL_THICKNESS - 1, BOARD_HEIGHT - 1},
                    Vec2{BOARD_WIDTH + 2 * WALL_THICKNESS - 1, 0}}));

    loadBricks();

}

Color convertColorFromString(const string &colorName) {
    /**
     * @brief Translate the color name to the corresponding Color
     *
     * @param colorName The name of the color
     * @return The corresponding Color
     */
    static const unordered_map<string, Color> colorMap = {
        {"defaultBrick", Color::defaultBrick},
        {"white", Color::white},
        {"orange", Color::orange},
        {"cyan", Color::cyan},
        {"green", Color::green},
        {"red", Color::red},
        {"blue", Color::blue},
        {"magenta", Color::magenta},
        {"yellow", Color::yellow},
        {"silver", Color::silver},
        {"gold", Color::gold}};
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
        {"SplitBall", BonusType::SplitBall},
    };
    auto it = bonusMap.find(bonusName);
    if (it != bonusMap.end()) {
        return it->second;
    }
    cerr << "Unknown bonus name" << endl;
    exit(1);
}

// ### Private methods ###
void Levels::loadBricks() {
    string mainPath = PATH_TO_LEVELS;
    vector<string> levelFiles; // Store the paths of the level files

    // Get all the files in the levels directory and store them in the vector
    for (const auto &entry : filesystem::directory_iterator(PATH_TO_LEVELS)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            levelFiles.push_back(entry.path().string());
        }
    }

    // Sort the files by name (level number)
    sort(levelFiles.begin(), levelFiles.end());

    for (const auto &filename : levelFiles) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file " << filename << endl;
            exit(1);
        }

        vector<Brick> bricks;

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
            bricks.emplace_back(Brick(BoundingBox{Vec2{x - BRICK_WIDTH / 2, y - BRICK_HEIGHT / 2},
                            Vec2{x + BRICK_WIDTH / 2, y + BRICK_HEIGHT / 2}}, convertColorFromString(color),
                convertBonusFromString(bonus)));
        }
        levelBricks_.emplace_back(bricks);
        file.close();
    }
}

// ### Public methods ###
void Levels::nextLevel() {
    if (currentLevel_ < levelBricks_.size() - 1) {
        ++currentLevel_;
    }
}

void Levels::previousLevel() {
    if (currentLevel_ > 0) {
        --currentLevel_;
    }
}

const vector<Brick> &Levels::getBricks() {
    return levelBricks_[currentLevel_];
}

const Ball &Levels::getBall() const { return levelBall_; }

const Racket &Levels::getRacket() const { return levelRacket_; }

const vector<Border> &Levels::getBorders() const {
    return levelBorders_;
}

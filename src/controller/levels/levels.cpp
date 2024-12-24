/**
 * @file levels.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define struct Levels
 * @date 16/12/2024
 *
 */

#include "levels.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

// TODO: Removing magic numbers and set Global variables
// TODO: set + BOARD_BOUNDINGS_THICKNESS in model for the ball, racket and brick
// if needed

// ### Constructor ###
Levels::Levels() : currentLevel(0) {
    // Left wall
    levelBorders_.emplace_back(make_shared<Border>(Border{
        BoundingBox{Vec2{0, BOARD_HEIGHT - 1}, Vec2{WALL_THICKNESS - 1, 0}}}));
    // Top wall
    levelBorders_.emplace_back(make_shared<Border>(BoundingBox{
        Vec2{0, BOARD_HEIGHT - 1}, Vec2{BOARD_WIDTH + WALL_THICKNESS - 1,
                                        BOARD_HEIGHT - WALL_THICKNESS - 1}}));
    // Right wall
    levelBorders_.emplace_back(make_shared<Border>(
        BoundingBox{Vec2{BOARD_WIDTH + WALL_THICKNESS - 1, BOARD_HEIGHT - 1},
                    Vec2{BOARD_WIDTH + 2 * WALL_THICKNESS - 1, 0}}));
}

// ### Private methods ###
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
        {"WideRacket", BonusType::WideRacket}};
    auto it = bonusMap.find(bonusName);
    if (it != bonusMap.end()) {
        return it->second;
    }
    cerr << "Unknown bonus name" << endl;
    exit(1);
}

void Levels::loadBricks() {
    string mainPath = PATH_TO_LEVELS;
    string filename = mainPath + to_string(currentLevel) + ".txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        exit(1);
    }

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
        levelBricks_.emplace_back(Brick::makeBrick(
            convertColorFromString(color),
            BoundingBox{Vec2{x - BRICK_WIDTH / 2, y - BRICK_HEIGHT / 2},
                        Vec2{x + BRICK_WIDTH / 2, y + BRICK_HEIGHT / 2}}, convertBonusFromString(bonus)));
    }
    file.close();
}

// ### Public methods ###
void Levels::levelUp() {
    if (currentLevel < MAX_LEVEL) {
        currentLevel++;
    }
}

void Levels::levelDown() {
    if (currentLevel > 0) {
        currentLevel--;
    }
}

const vector<shared_ptr<Brick>> &Levels::getBricks() {
    levelBricks_.clear();
    loadBricks();
    return levelBricks_;
}

const Ball &Levels::getBall() const { return levelBall_; }

const Racket &Levels::getRacket() const { return levelRacket_; }

const vector<shared_ptr<Border>> &Levels::getBorders() const {
    return levelBorders_;
}

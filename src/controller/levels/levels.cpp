/**
 * @file levels.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define struct Levels
 * @date 16/12/2024
 *
 */

#include "levels.hpp"
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


// TODO: Removing magic numbers and set Global variables
// TODO: set + BOARD_BOUNDINGS_THICKNESS in model for the ball, racket and brick if needed


// ### Constructor ###
Levels::Levels() {
    // Left border
    levelBorders_.push_back(make_shared<Border>(Border{BoundingBox{
        Vec2{0, BOARD_HEIGHT - 1}, Vec2{WALL_THICKNESS - 1, 0}}}));
    // Top border
    levelBorders_.push_back(make_shared<Border>(BoundingBox{
        Vec2{0, BOARD_HEIGHT - 1},
        Vec2{BOARD_WIDTH + WALL_THICKNESS - 1, BOARD_HEIGHT - WALL_THICKNESS - 1}}));
    // Right border
    levelBorders_.push_back(make_shared<Border>(BoundingBox{
        Vec2{BOARD_WIDTH + WALL_THICKNESS - 1, BOARD_HEIGHT - 1},
        Vec2{BOARD_WIDTH + 2 * WALL_THICKNESS - 1, 0}}));
}


// ### Private methods ###
Color convertColorFromString(const string& colorName) {
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
        {"gold", Color::gold}
    };
    auto it = colorMap.find(colorName);
    if (it != colorMap.end()) {
        return it->second;
    }
    cerr << "Unknown color name" << endl;
    exit(-1); // TODO: maybe change the way we handle the error
}

void Levels::loadBricks() {
    string mainPath = "Levels/";
    string filename = mainPath + to_string(level) + ".txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        exit(-1); // TODO: maybe change the way we handle the error
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        double x, y;
        string color;
        if (!(iss >> x >> y >> color)) {
            cerr << "Failed to read line" << endl;
            exit(-1); // TODO: maybe change the way we handle the error
        }
        x += WALL_THICKNESS; // because the board has a left border
        y += WALL_THICKNESS; // because the board has a top border
        levelBricks_.push_back(Brick::makeBrick(convertColorFromString(color), BoundingBox{Vec2{x - 35, y - 10}, Vec2{x + 35, y + 10}}));
    }
    file.close();
}


// ### Public methods ###
void Levels::levelUp() {
    // TODO: check if it's not open, return bool to say that the file doesn't exist
    if (level < MAX_LEVEL) {
        level++;
    }
}

void Levels::levelDown() {
    if (level > 0) {
        level--;
    }
}

const vector<shared_ptr<Brick>> Levels::getBricks() {
    levelBricks_.clear();
    loadBricks();
    return levelBricks_;
}

const Ball Levels::getBall() const {
    return levelBall_;
}

const Racket Levels::getRacket() const { return levelRacket_; }

const vector<shared_ptr<Border>> Levels::getBorders() const { return levelBorders_; }
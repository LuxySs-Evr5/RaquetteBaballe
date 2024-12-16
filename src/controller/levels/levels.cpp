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

const double BOARD_BOUNDINGS_THICKNESS = 20;
const double BOARD_WIDTH = 980;
const double BOARD_HEIGHT = 980;


// TODO: Removing magic numbers and set Global variables
// TODO: set + BOARD_BOUNDINGS_THICKNESS in model for the ball, racket and brick if needed


// ### Constructor ###
Levels::Levels() {
    levelBalls_.push_back( 
        make_shared<Ball>(Vec2{BOARD_WIDTH / 2 + BOARD_BOUNDINGS_THICKNESS - 1, 85}, Vec2{0, 1}, 10, 500)); // + BOARD_BOUNDINGS_THICKNESS because the board has a left border
    
    levelRackets_.push_back(
        make_shared<Racket>(BoundingBox{Vec2{BOARD_WIDTH / 2 + BOARD_BOUNDINGS_THICKNESS - 1, 50}, 100, 25})); // + BOARD_BOUNDINGS_THICKNESS because the board has a left border

    // Left border
    levelBorders_.push_back(make_shared<Border>(Border{BoundingBox{
        Vec2{0, BOARD_HEIGHT - 1}, Vec2{BOARD_BOUNDINGS_THICKNESS - 1, 0}}}));
    // Top border
    levelBorders_.push_back(make_shared<Border>(BoundingBox{
        Vec2{0, BOARD_HEIGHT - 1},
        Vec2{BOARD_WIDTH + BOARD_BOUNDINGS_THICKNESS - 1, BOARD_HEIGHT - BOARD_BOUNDINGS_THICKNESS - 1}}));
    // Right border
    levelBorders_.push_back(make_shared<Border>(BoundingBox{
        Vec2{BOARD_WIDTH + BOARD_BOUNDINGS_THICKNESS - 1, BOARD_HEIGHT - 1},
        Vec2{BOARD_WIDTH + 2 * BOARD_BOUNDINGS_THICKNESS - 1, 0}}));
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
    string filename = "Levels/1.txt";
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
        x += BOARD_BOUNDINGS_THICKNESS; // because the board has a left border
        y += BOARD_BOUNDINGS_THICKNESS; // because the board has a top border
        levelBricks_.push_back(make_shared<Brick>(BoundingBox{Vec2{x - 35, y - 10}, Vec2{x + 35, y + 10}}, convertColorFromString(color)));
    }
    file.close();
}


// ### Public methods ###
vector<shared_ptr<Ball>> Levels::getBalls() const { return levelBalls_; }

vector<shared_ptr<Racket>> Levels::getRackets() const { return levelRackets_; }

vector<shared_ptr<Border>> Levels::getBorders() const { return levelBorders_; }

vector<shared_ptr<Brick>> Levels::getBricks() {
    loadBricks();
    return levelBricks_;
}
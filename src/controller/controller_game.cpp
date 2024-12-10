/**
 * @file controller_game.cpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#include "controller_game.hpp"

#include <thread>

using namespace std;

constexpr std::chrono::duration<double> SLEEP_TIME(1.0f);

// ### Constructor ###
ControllerGame::ControllerGame() : gameBoard_{make_shared<GameBoard>()} {}

// ### Destructor ###
ControllerGame::~ControllerGame() {}

// ### Public methods ###
void ControllerGame::process() {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<double>;

    time_point t_last_update =
        clock::now() - std::chrono::duration_cast<clock::duration>(SLEEP_TIME);

    while (!done_) {
        time_point t_now = clock::now();

        duration delta_time = t_now - t_last_update;

        t_last_update = t_now;

        gameBoard_->update(delta_time.count());

        // Gestion du temps
        std::cout << "delta time= " << delta_time.count() << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(SLEEP_TIME));
    }
}

void ControllerGame::drawGame() {}

void ControllerGame::checkLife() {}

// ### Private methods ###

void ControllerGame::checkEventType() {}

void ControllerGame::waitKeyToRestart() {}

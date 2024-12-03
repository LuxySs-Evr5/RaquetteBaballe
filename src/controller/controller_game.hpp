/**
 * @file main_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef IN_GAME_HPP
#define IN_GAME_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <allegro5/mouse.h>

#include <bitset>
#include <string>

#include "../model/model.hpp"
#include "../vue/display_game/display_game.hpp"

using namespace std;

class ControllerGame {
  private:
    bool isGaming_ = true;
    bool win_ = false;
    bool done_ = false;
    bool draw_ = false;

    DisplayGame displayGame_;
    Model model_;

    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT_QUEUE *queue_;
    ALLEGRO_EVENT event_;
    ALLEGRO_MOUSE_STATE mouseState_;

    bitset<ALLEGRO_KEY_MAX>
        key_; // table of bit for all keyboard keys set to false

    // ### Private Methods ###
    void drawGame();
    void checkLife();
    void checkEventType();
    void waitKeyToRestart();

  public:
    ControllerGame();
    ~ControllerGame();

    // ### Public Methods ###
    void process();

    void shootLazer();
    void loadLevel(const string &filepath);
};
#endif // IN_GAME_HPP

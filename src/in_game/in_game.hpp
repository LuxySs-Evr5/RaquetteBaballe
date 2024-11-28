/**
 * @file in_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef IN_GAME_HPP
#define IN_GAME_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/keycodes.h>
#include <allegro5/mouse.h>
#include <array>

#include "../canvas/canvas.hpp"
#include "../life/life.hpp"

class InGame{
    private:
        bool isGaming_ = true;
        bool done_ = false;
        bool draw_ = false;

        ALLEGRO_DISPLAY *display_;
        ALLEGRO_BITMAP *heartImage_;
        ALLEGRO_SAMPLE *music_;
        ALLEGRO_SAMPLE_INSTANCE *instanceMusic_;
        ALLEGRO_FONT *font24_;
        ALLEGRO_FONT *font50_;

        ALLEGRO_MOUSE_STATE mouseState_;

        Canvas canvas_;
        Life life_;
        Score score_;
        
        array<bool, ALLEGRO_KEY_MAX> key_ = {}; // table of all keyboard keys set to false


    public:
        // ### Public Variables ###
        ALLEGRO_TIMER *timer;
        ALLEGRO_EVENT_QUEUE *queue;
        ALLEGRO_EVENT event;

        InGame();
        ~InGame();

        // ### Public Methods ###
        void checkInit(void *test,string type); // check if the initialization is done correctly
        void gameOver(); // draw the game over screen
        void moveRacket(const float x);
        void shootLazer();
        void drawGame();
        void loadLevel(const string &filepath);

        // ### Getters ###
        bool getDone() const;
        bool getDraw() const;
        bool getIsGaming() const;
        const array<bool, ALLEGRO_KEY_MAX> &getKeys() const ;

        // ### Setters ###
        void setDone(const bool done);
        void setDraw(const bool draw);
        void setIsGaming(const bool isGaming);
        void setKeyTrue(const int keyCode);
        void setKeyFalse(const int keyCode);

};
#endif // IN_GAME_HPP
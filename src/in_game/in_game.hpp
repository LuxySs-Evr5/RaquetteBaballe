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

        Canvas canvas_;
        Life life_;
        Score score_;
        
        bool key[ALLEGRO_KEY_MAX] = {false}; // table of all keyboard keys set to false

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
        bool *getKey();

        // ### Setters ###
        void setDone(const bool done);
        void setDraw(const bool draw);
        void setIsGaming(const bool isGaming);

};
#endif // IN_GAME_HPP
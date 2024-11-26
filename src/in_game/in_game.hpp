/**
 * @file in_game.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Class that manage the current game
 */

#ifndef IN_GAME_HPP
#define IN_GAME_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/bitmap.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <allegro5/timer.h>
#include <ctime>

#include "../canvas/canvas.hpp"
#include "../life/life.hpp"

class InGame{
    private:
        bool done_ = false;
        bool draw_ = false;
        ALLEGRO_DISPLAY *display_;
        ALLEGRO_EVENT_QUEUE *queue_;
        ALLEGRO_EVENT event_;
        ALLEGRO_BITMAP *heartImage_;
        ALLEGRO_SAMPLE *music_;
        ALLEGRO_SAMPLE_INSTANCE *instanceMusic_;
        ALLEGRO_FONT *font24_;
        ALLEGRO_FONT *font50_;
        Canvas canvas_;
        Life life_;
        Score score_;
        ALLEGRO_TIMER *timer_;
        bool key[ALLEGRO_KEY_MAX] = {false}; // table of all keyboard keys set to false

    public:
        InGame();

        ~InGame();

        void checkInit(void *test,string type);

        void gaming();

        ALLEGRO_TIMER *getTimer() const;
        bool getDone() const;
        bool getDraw() const;
        ALLEGRO_DISPLAY *getDisplay() const;
        ALLEGRO_EVENT_QUEUE *getQueue() const;
        ALLEGRO_EVENT getEvent() const;
        ALLEGRO_BITMAP *getHeartImage() const;
        ALLEGRO_SAMPLE *getMusic() const;
        ALLEGRO_SAMPLE_INSTANCE *getInstanceMusic() const;
        ALLEGRO_FONT *getFont24() const;
        ALLEGRO_FONT *getFont50() const;
        Canvas getCanvas() const;
        Life getLife() const;
        Score getScore() const;
        bool *getKey();

};
#endif // IN_GAME_HPP
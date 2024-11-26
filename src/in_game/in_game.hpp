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

        void checkInit(void *test,string type);

        void gaming();

        void moveRacket(const float x);
        void resetLife();
        void resetScore();

        // ### Getters ###
        bool getDone() const;
        bool getDraw() const;
        bool getIsGaming() const;

        ALLEGRO_DISPLAY *getDisplay() const;
        ALLEGRO_BITMAP *getHeartImage() const;
        ALLEGRO_SAMPLE *getMusic() const;
        ALLEGRO_SAMPLE_INSTANCE *getInstanceMusic() const;
        ALLEGRO_FONT *getFont24() const;
        ALLEGRO_FONT *getFont50() const;
        Canvas getCanvas() const;
        Life getLife() const;
        Score getScore() const;
        bool *getKey();

        // ### Setters ###
        void setDone(const bool done);
        void setDraw(const bool draw);
        void setIsGaming(const bool isGaming);

        void setDisplay(ALLEGRO_DISPLAY *display);
        void setHeartImage(ALLEGRO_BITMAP *heartImage);
        void setMusic(ALLEGRO_SAMPLE *music);
        void setInstanceMusic(ALLEGRO_SAMPLE_INSTANCE *instanceMusic);
        void setFont24(ALLEGRO_FONT *font24);
        void setFont50(ALLEGRO_FONT *font50);
        void setCanvas(const Canvas canvas);
        void setLife(const Life life);
        void setScore(const Score score);
        void setKey(const bool key[ALLEGRO_KEY_MAX]);

};
#endif // IN_GAME_HPP
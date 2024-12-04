/**
 * @file gui_brik.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief Define the class Brik
 * @date 27/11/2024 
 *
 */

#ifndef GUI_BRIK_HPP
#define GUI_BRIK_HPP

#include "../figures/forme.hpp"

class GuiBrik final : public Rectangle {

    public:
        GuiBrik(Point center, float width, float height, ALLEGRO_COLOR color);
        ~GuiBrik() = default;

        void draw() override;

};


#endif // GUI_BRIK_HPP
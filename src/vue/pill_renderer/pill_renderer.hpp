/**
 * @file pill_renderer.hpp
 * @author Ethan Van Ruyskensvelde (Main developer)
 * @brief PillRenderer class header
 * @date 18/12/2024
 * 
 */

#ifndef PILL_RENDERER_HPP
#define PILL_RENDERER_HPP

#include "../../model/bonus/bonus_pill.hpp"

class PillRenderer {
  public:
    /**
     * @brief Render the pill
     * 
     * @param pill 
     */
    void render(const BonusPill &bonusPill) const;
};

#endif // PILL_RENDERER_HPP
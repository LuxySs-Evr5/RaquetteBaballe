/**
 * @file initialize_allegro.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief This file contains the main function of the game Arkanoid that launches the game with allegro 
 * and manages the events
 * @date 24/11/2024
 *
 */

#include <allegro5/keycodes.h>
#include "controller/controller_game.hpp"

using namespace std;


int main(int /* argc */, char ** /* argv */){

  ControllerGame controllerGame;
  controllerGame.process();
  return 0;
}
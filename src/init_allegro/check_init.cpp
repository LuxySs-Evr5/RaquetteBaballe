/**
 * @file check_init.cpp
 * @author Ethan Van Ruyskensvelde (Main developper)
 * @brief Declare checkInit that checks if the initialization of allegro was successful
 * @date 25/11/2024
 *
 */

#include "check_init.hpp"
#include <iostream>

void checkInit(void *test,string type){
    if (test == nullptr){
        cerr << "Failed to load " << type << endl;
        exit(-1);
    }
}
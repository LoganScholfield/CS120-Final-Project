/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the sign header file
*/

#ifndef FINAL_PROJECT_SIGN_H
#define FINAL_PROJECT_SIGN_H



#include "Quad.h"
#include <string>

class Sign : public Quad {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    Sign(color fill, point center, unsigned int width, unsigned int height, std::string label);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw() const override;



};




#endif //FINAL_PROJECT_SIGN_H

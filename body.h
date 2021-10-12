/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the body header file
*/

#ifndef FINAL_PROJECT_BODY_H
#define FINAL_PROJECT_BODY_H



#include <vector>
#include "shape.h"
#include "circle.h"
#include "rect.h"

using namespace std;

class Body {
private:
    Rect chest;
    Rect neck;
    Rect belt;
    Rect pants;
    Circle shirtHole;


public:
    /* Constructors */
    Body();

    Body(Rect c, Rect n);

    /* Destructor */
    virtual ~Body() = default;

    /* Setters */
    void setChestLength(double l);
    void setChestWidth(double w);
    void setBodyCenter(double x, double y);

    void setBodyColor(double red, double green, double blue, double alpha);
    void setNeckColor(double red, double green, double blue, double alpha);
    void setPantsColor(double red, double green, double blue, double alpha);
    void setBeltColor(double red, double green, double blue, double alpha);


    /* Getters */
    double getBodyRedColor() const;
    double getBodyGreenColor() const;
    double getBodyBlueColor() const;

    double getChestLeftX() const;
    double getChestRightX() const;
    double getChestTopY() const;
    double getChestBottomY() const;

    double getNeckLeftX() const;
    double getNeckRightX() const;
    double getNeckTopY() const;
    double getNeckBottomY() const;

    double getPantsLeftX() const;
    double getPantsRightX() const;
    double getPantsTopY() const;
    double getPantsBottomY() const;

    /* Movers */
    void moveX(double deltaX);
    void moveY(double deltaY);

    /* Draw */
    void draw()const;
};



#endif //FINAL_PROJECT_BODY_H

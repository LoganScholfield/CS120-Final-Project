/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the arms header file
*/

#ifndef FINAL_PROJECT_ARMS_H
#define FINAL_PROJECT_ARMS_H

#include "shape.h"
#include "circle.h"
#include "rect.h"

using namespace std;

class Arms {
private:
    Rect leftArm;
    Circle leftHand;
    Rect rightArm;
    Circle rightHand;

public:
    /* Constructors */
    Arms();

    Arms(Rect lA, Circle lH, Rect rA, Circle rH);

    /* Destructor */
    virtual ~Arms() = default;

    /* Setter */
    void setArmSize(double l, double w);
    void setLArmCenter(double x, double y);
    void setRArmCenter(double x, double y);

    void setArmColor(double r, double g, double b, double a);
    void setArmColor(color fill);

    void setHandColor(double r, double g, double b, double a);
    void setHandColor(color fill);

    /* Getter */
    double getArmLength();
    double getArmWidth();

    double getArmsRedColor() const;
    double getArmsGreenColor() const;
    double getArmsBlueColor() const;

    double getHandsRedColor() const;
    double getHandsGreenColor() const;
    double getHandsBlueColor() const;

    double getLeftArmLeftX() const;
    double getLeftArmRightX() const;
    double getLeftArmTopY() const;
    double getLeftArmBottomY() const;

    double getRightArmLeftX() const;
    double getRightArmRightX() const;
    double getRightArmTopY() const;
    double getRightArmBottomY() const;

    double getLeftHandLeftX() const;
    double getLeftHandRightX() const;
    double getLeftHandTopY() const;
    double getLeftHandBottomY() const;

    double getRightHandLeftX() const;
    double getRightHandRightX() const;
    double getRightHandTopY() const;
    double getRightHandBottomY() const;

    /* Movers */
    void moveX(double deltaX);
    void moveY(double deltaY);

    /* Draw */
    void draw() const;
};


#endif //FINAL_PROJECT_ARMS_H

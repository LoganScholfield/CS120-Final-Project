/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the legs header file
*/

#ifndef FINAL_PROJECT_LEGS_H
#define FINAL_PROJECT_LEGS_H


#include "shape.h"
#include "circle.h"
#include "rect.h"

using namespace std;

class Legs {
private:
    Rect leftLeg;
    Circle leftFoot;
    Rect rightLeg;
    Circle rightFoot;

public:
    /* Constructors */
    Legs();

    Legs(Rect lL, Circle lF, Rect rL, Circle rF);

    /* Destructor */
    virtual ~Legs() = default;

    /* Setter */
    void setLegSize(double l, double w);
    void setLLegCenter(double x, double y);
    void setRLegCenter(double x, double y);

    void setLegColor(double r, double g, double b, double a);
    void setLegColor(color fill);

    void setFootColor(double r, double g, double b, double a);
    void setFootColor(color fill);

    /* Getter */
    double getLegLength();
    double getLegWidth();

    double getLegsRedColor() const;
    double getLegsGreenColor() const;
    double getLegsBlueColor() const;

    double getFeetRedColor() const;
    double getFeetGreenColor() const;
    double getFeetBlueColor() const;

    double getLeftLegLeftX() const;
    double getLeftLegRightX() const;
    double getLeftLegTopY() const;
    double getLeftLegBottomY() const;

    double getRightLegLeftX() const;
    double getRightLegRightX() const;
    double getRightLegTopY() const;
    double getRightLegBottomY() const;

    double getLeftFootLeftX() const;
    double getLeftFootRightX() const;
    double getLeftFootTopY() const;
    double getLeftFootBottomY() const;

    double getRightFootLeftX() const;
    double getRightFootRightX() const;
    double getRightFootTopY() const;
    double getRightFootBottomY() const;

    /* Movers */
    void moveX(double deltaX);
    void moveY(double deltaY);

    /* Draw */
    void draw() const;
};


#endif //FINAL_PROJECT_LEGS_H

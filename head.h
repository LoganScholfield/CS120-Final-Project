/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the head head file
//^says "head" twice haha
*/

#ifndef FINAL_PROJECT_KGOODELM_LSCHOLFI_JYANDO_HEAD_H
#define FINAL_PROJECT_KGOODELM_LSCHOLFI_JYANDO_HEAD_H

#include <vector>

#include "shape.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

class Head {
private:
    Circle head;
    Circle hair;
    vector<Triangle> nose;

    vector<Circle> lEye;
    vector<Circle> rEye;

    vector<Circle> mouth;

public:
    /* Constructors */
    Head();

    /* Destructor */
    virtual ~Head() = default;

    /* Setters */
    void setHeadRadius(double r);
    void setHeadCenter(double x, double y);

    void setHeadColor(double red, double green, double blue, double alpha);
    void setHeadColor(color fill);

    void setEyeColor(double red, double green, double blue, double alpha);
    void setEyeColor(color fill);

    /* Getter */
    double getHeadRadius() const;

    double getHeadRedColor() const;
    double getHeadGreenColor() const;
    double getHeadBlueColor() const;

    double getEyesRedColor() const;
    double getEyesGreenColor() const;
    double getEyesBlueColor() const;

    double getLeftX() const;
    double getRightX() const;
    double getTopY() const;
    double getBottomY() const;

    double getLEyeLeftX() const;
    double getLEyeRightX() const;
    double getLEyeTopY() const;
    double getLEyeBottomY() const;

    double getREyeLeftX() const;
    double getREyeRightX() const;
    double getREyeTopY() const;
    double getREyeBottomY() const;

    /* Movers */
    void moveX(double deltaX);
    void moveY(double deltaY);

    /* Draw */
    void draw() const;
};


#endif //FINAL_PROJECT_KGOODELM_LSCHOLFI_JYANDO_HEAD_H

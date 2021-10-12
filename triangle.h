/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the triangle header file
*/

#ifndef FINAL_PROJECT_TRIANGLE_H
#define FINAL_PROJECT_TRIANGLE_H

#include "shape.h"

struct dimensionsT {
    double base;
    double height;

    /* Constructors */
    dimensionsT();
    dimensionsT(double b, double h);

    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const dimensionsT &dT);
};

class Triangle : public Shape {
private:
    dimensionsT size;
public:
    /* Constructors */
    Triangle();
    explicit Triangle(dimensionsT size);
    explicit Triangle(color fill);
    explicit Triangle(point2D center);
    Triangle(color fill, point2D center);
    Triangle(double red, double green, double blue, double alpha);
    Triangle(double x, double y);
    Triangle(double red, double green, double blue, double alpha, double x, double y);
    Triangle(color fill, double x, double y);
    Triangle(double red, double green, double blue, double alpha, point2D center);
    Triangle(color fill, dimensionsT size);
    Triangle(point2D center, dimensionsT size);
    Triangle(color fill, point2D center, dimensionsT size);
    Triangle(double red, double green, double blue, double alpha, dimensionsT size);
    Triangle(double x, double y, dimensionsT size);
    Triangle(double red, double green, double blue, double alpha, double x, double y, dimensionsT size);
    Triangle(color fill, double x, double y, dimensionsT size);
    Triangle(double red, double green, double blue, double alpha, point2D center, dimensionsT size);

    /* Destructor */
    virtual ~Triangle() = default;

    /* Getters */
    dimensionsT getSize() const;
    double getBase() const;
    double getHeight() const;
    double getMidX() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setters */
    void setSize(dimensionsT size);
    void setSize(double base, double height);
    void setBase(double base);
    void setHeight(double height);
    void changeSize(double deltaBase, double deltaHeight);
    void changeBase(double delta);
    void changeHeight(double delta);


    /* Draw */
    void draw() const override;

};

#endif //FINAL_PROJECT_TRIANGLE_H

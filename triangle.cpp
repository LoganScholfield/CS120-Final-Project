/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the triangle file
*/

#include "triangle.h"
#include "graphics.h"
#include <iostream>
using namespace std;

/********************* Dimensions Struct ********************/

dimensionsT::dimensionsT() : base(0), height(0) {}

dimensionsT::dimensionsT(double b, double h) : base(b), height(h) {}

ostream& operator << (ostream& outs, const dimensionsT &dT) {
    outs << "[" << dT.base << ", " << dT.height << "]";
    return outs;
}


Triangle::Triangle() : Shape(), size({0, 0}) {
}

Triangle::Triangle(dimensionsT size) : Shape() {
    setSize(size);
}

Triangle::Triangle(color fill) : Shape(fill), size({0, 0}) {
}
Triangle::Triangle(point2D center) : Shape(center), size({0, 0}) {
}

Triangle::Triangle(color fill, point2D center) : Shape(fill, center), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha) : Shape(red, green, blue, alpha), size({0, 0}) {
}

Triangle::Triangle(double x, double y) : Shape(x, y), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha, double x, double y) : Shape(red, green, blue, alpha, x, y), size({0, 0}) {
}

Triangle::Triangle(color fill, double x, double y) : Shape(fill, x, y), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha, point2D center) : Shape(red, green, blue, alpha, center), size({0, 0}) {
}

Triangle::Triangle(color fill, dimensionsT size) : Shape(fill) {
    setSize(size);
}

Triangle::Triangle(point2D center, dimensionsT size) : Shape(center) {
    setSize(size);
}

Triangle::Triangle(color fill, point2D center, dimensionsT size) : Shape(fill, center) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, dimensionsT size) : Shape(red, green, blue, alpha) {
    setSize(size);
}

Triangle::Triangle(double x, double y, dimensionsT size) : Shape(x, y) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, double x, double y, dimensionsT size) : Shape(red, green, blue, alpha, x, y) {
    setSize(size);
}

Triangle::Triangle(color fill, double x, double y, dimensionsT size) : Shape(fill, x, y) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, point2D center, dimensionsT size) : Shape(red, green, blue, alpha, center) {
    setSize(size);
}

dimensionsT Triangle::getSize() const {
    return size;
}

double Triangle::getBase() const {
    return size.base;
}

double Triangle::getHeight() const {
    return size.height;
}

double Triangle::getMidX() const {
    return center.x;
}

double Triangle::getLeftX() const {
    return center.x - (size.base / 2.0);
}

double Triangle::getRightX() const {
    return center.x + (size.base / 2.0);
}

double Triangle::getTopY() const {
    return center.y - (size.height / 2.0);
}

double Triangle::getBottomY() const {
    return center.y + (size.height / 2.0);
}

void Triangle::setSize(dimensionsT size) {
    if (size.base >= 0 && size.height >= 0) {
        this->size = size;
    }
}

void Triangle::setSize(double base, double height) {
    setSize({base, height});
}

void Triangle::setBase(double base) {
    setSize({base, size.height});
}

void Triangle::setHeight(double height) {
    setSize({size.base, height});
}

void Triangle::changeSize(double deltaBase, double deltaHeight) {
    setSize({size.base + deltaBase, size.height + deltaHeight});
}

void Triangle::changeBase(double delta) {
    setSize({size.base + delta, size.height});
}

void Triangle::changeHeight(double delta) {
    setSize({size.base, size.height + delta});
}

void Triangle::draw() const {
    // Set drawing color to fill color
    glColor3f(fill.red, fill.green, fill.blue);
    // Draw circle as Triangle Fan
    glBegin(GL_TRIANGLES);
    // top mid
    glVertex2i(center.x, (center.y - (getHeight() / 2)));
    // Bottom left corner
    glVertex2i((center.x - (getBase() / 2)), (center.y + (getHeight() / 2)));
    // Bottom right corner
    glVertex2i((center.x + (getBase() / 2)), (center.y + (getHeight() / 2)));

    // End Triangle Fan
    glEnd();
}
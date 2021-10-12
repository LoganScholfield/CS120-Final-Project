/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the legs file
*/

#include "legs.h"

// Constructors
Legs::Legs() {

}

Legs::Legs(Rect lL, Circle lF, Rect rL, Circle rF): leftLeg(lL), leftFoot(lF), rightLeg(rL), rightFoot(rF) {
}

// Setters
void Legs::setLegSize(double l, double w) {

    if(l <= 0 || w <= 0){
        leftLeg.setHeight(0);
        leftLeg.setWidth(0);
        leftFoot.setRadius(0);

        rightLeg.setHeight(0);
        rightLeg.setWidth(0);
        rightFoot.setRadius(0);
    }else{
        leftLeg.setHeight(l);
        leftLeg.setWidth(w);
        leftFoot.setRadius(w/2);

        rightLeg.setHeight(l);
        rightLeg.setWidth(w);
        rightFoot.setRadius(w/2);
    }

    setLLegCenter(leftLeg.getCenterX(), leftLeg.getCenterY());
    setRLegCenter(rightLeg.getCenterX(), rightLeg.getCenterY());
}

void Legs::setLLegCenter(double x, double y) {
    if(x <= 0 || y <= 0){
        leftLeg.setCenter(0,0);
        leftFoot.setCenter(0,0);
    }else{
        leftLeg.setCenter(x,y);
        leftFoot.setCenter(x, leftLeg.getBottomY());
    }
}

void Legs::setRLegCenter(double x, double y) {
    if(x <= 0 || y <= 0){
        rightLeg.setCenter(0,0);
        rightFoot.setCenter(0,0);
    }else{
        rightLeg.setCenter(x,y);
        rightFoot.setCenter(x,rightLeg.getBottomY());
    }
}

void Legs::setLegColor(double r, double g, double b, double a) {
    leftLeg.setFillColor(r,g,b,a);
    rightLeg.setFillColor(r,g,b,a);
}

void Legs::setLegColor(color fill) {
    leftLeg.setFillColor(fill);
    rightLeg.setFillColor(fill);
}

void Legs::setFootColor(double r, double g, double b, double a) {
    leftFoot.setFillColor(r,g,b,a);
    rightFoot.setFillColor(r,g,b,a);
}

void Legs::setFootColor(color fill) {
    leftFoot.setFillColor(fill);
    rightFoot.setFillColor(fill);
}

// Getters
double Legs::getLegLength() {
    return leftLeg.getHeight();
}

double Legs::getLegWidth() {
    return leftLeg.getWidth();
}

double Legs::getLegsRedColor() const {
    return leftLeg.getFillRed();
}

double Legs::getLegsGreenColor() const {
    return leftLeg.getFillGreen();
}

double Legs::getLegsBlueColor() const {
    return leftLeg.getFillBlue();
}

double Legs::getFeetRedColor() const {
    return leftFoot.getFillRed();
}

double Legs::getFeetGreenColor() const {
    return leftFoot.getFillGreen();
}

double Legs::getFeetBlueColor() const {
    return leftFoot.getFillBlue();
}

double Legs::getLeftLegLeftX() const {
    return leftLeg.getLeftX();
}

double Legs::getLeftLegRightX() const {
    return leftLeg.getRightX();
}

double Legs::getLeftLegTopY() const {
    return leftLeg.getTopY();
}

double Legs::getLeftLegBottomY() const {
    return leftLeg.getBottomY();
}

double Legs::getRightLegLeftX() const {
    return rightLeg.getLeftX();
}

double Legs::getRightLegRightX() const {
    return rightLeg.getRightX();
}

double Legs::getRightLegTopY() const {
    return rightLeg.getTopY();
}

double Legs::getRightLegBottomY() const {
    return rightLeg.getBottomY();
}

double Legs::getLeftFootLeftX() const {
    return leftFoot.getLeftX();
}

double Legs::getLeftFootRightX() const {
    return leftFoot.getRightX();
}

double Legs::getLeftFootTopY() const {
    return leftFoot.getTopY();
}

double Legs::getLeftFootBottomY() const {
    return leftFoot.getBottomY();
}

double Legs::getRightFootLeftX() const {
    return rightFoot.getLeftX();
}

double Legs::getRightFootRightX() const {
    return rightFoot.getRightX();
}

double Legs::getRightFootTopY() const {
    return rightFoot.getTopY();
}

double Legs::getRightFootBottomY() const {
    return rightFoot.getBottomY();
}

// Movers
void Legs::moveX(double deltaX) {
    leftLeg.moveX(deltaX);
    leftFoot.moveX(deltaX);
    rightLeg.moveX(deltaX);
    rightFoot.moveX(deltaX);
}

void Legs::moveY(double deltaY) {
    leftLeg.moveY(deltaY);
    leftFoot.moveY(deltaY);
    rightLeg.moveY(deltaY);
    rightFoot.moveY(deltaY);
}

// Draw
void Legs::draw() const{
    leftFoot.draw();
    rightFoot.draw();

    leftLeg.draw();
    rightLeg.draw();
}
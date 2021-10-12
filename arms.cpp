/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the arms file
*/

#include "arms.h"

// Constructors
Arms::Arms() {

}

Arms::Arms(Rect lA, Circle lH, Rect rA, Circle rH): leftArm(lA), leftHand(lH), rightArm(rA), rightHand(rH) {
}

// Setters
void Arms::setArmSize(double l, double w) {

    if(l <= 0 || w <= 0){
        leftArm.setHeight(0);
        leftArm.setWidth(0);
        leftHand.setRadius(0);

        rightArm.setHeight(0);
        rightArm.setWidth(0);
        rightHand.setRadius(0);
    }else{
        leftArm.setHeight(l);
        leftArm.setWidth(w);
        leftHand.setRadius(l/2);

        rightArm.setHeight(l);
        rightArm.setWidth(w);
        rightHand.setRadius(l/2);
    }

    setLArmCenter(leftArm.getCenterX(), leftArm.getCenterY());
    setRArmCenter(rightArm.getCenterX(), rightArm.getCenterY());
}

void Arms::setLArmCenter(double x, double y) {
    if(x <= 0 || y <= 0){
        leftArm.setCenter(0,0);
        leftHand.setCenter(0,0);
    }else{
        leftArm.setCenter(x,y);
        leftHand.setCenter(leftArm.getLeftX(), y);
    }
}

void Arms::setRArmCenter(double x, double y) {
    if(x <= 0 || y <= 0){
        rightArm.setCenter(0,0);
        rightHand.setCenter(0,0);
    }else{
        rightArm.setCenter(x,y);
        rightHand.setCenter(rightArm.getRightX(), y);
    }
}

void Arms::setArmColor(double r, double g, double b, double a) {
    leftArm.setFillColor(r,g,b,a);
    rightArm.setFillColor(r,g,b,a);
}

void Arms::setArmColor(color fill) {
    leftArm.setFillColor(fill);
    rightArm.setFillColor(fill);
}

void Arms::setHandColor(double r, double g, double b, double a) {
    leftHand.setFillColor(r,g,b,a);
    rightHand.setFillColor(r,g,b,a);
}

void Arms::setHandColor(color fill) {
    leftHand.setFillColor(fill);
    rightHand.setFillColor(fill);
}

// Getters
double Arms::getArmLength() {
    return leftArm.getHeight();
}

double Arms::getArmWidth() {
    return leftArm.getWidth();
}

double Arms::getArmsRedColor() const {
    return leftArm.getFillRed();
}

double Arms::getArmsGreenColor() const {
    return leftArm.getFillGreen();
}

double Arms::getArmsBlueColor() const {
    return leftArm.getFillBlue();
}

double Arms::getHandsRedColor() const {
    return leftHand.getFillRed();
}

double Arms::getHandsGreenColor() const {
    return leftHand.getFillGreen();
}

double Arms::getHandsBlueColor() const {
    return leftHand.getFillBlue();
}

double Arms::getLeftArmLeftX() const {
    return leftArm.getLeftX();
}

double Arms::getLeftArmRightX() const {
    return leftArm.getRightX();
}

double Arms::getLeftArmTopY() const {
    return leftArm.getTopY();
}

double Arms::getLeftArmBottomY() const {
    return leftArm.getBottomY();
}

double Arms::getRightArmLeftX() const {
    return rightArm.getLeftX();
}

double Arms::getRightArmRightX() const {
    return rightArm.getRightX();
}

double Arms::getRightArmTopY() const {
    return rightArm.getTopY();
}

double Arms::getRightArmBottomY() const {
    return rightArm.getBottomY();
}

double Arms::getLeftHandLeftX() const {
    return leftHand.getLeftX();
}

double Arms::getLeftHandRightX() const {
    return leftHand.getRightX();
}

double Arms::getLeftHandTopY() const {
    return leftHand.getTopY();
}

double Arms::getLeftHandBottomY() const {
    return leftHand.getBottomY();
}

double Arms::getRightHandLeftX() const {
    return rightHand.getLeftX();
}

double Arms::getRightHandRightX() const {
    return rightHand.getRightX();
}

double Arms::getRightHandTopY() const {
    return rightHand.getTopY();
}

double Arms::getRightHandBottomY() const {
    return rightHand.getBottomY();
}

// Movers
void Arms::moveX(double deltaX) {
    leftArm.moveX(deltaX);
    leftHand.moveX(deltaX);
    rightArm.moveX(deltaX);
    rightHand.moveX(deltaX);
}

void Arms::moveY(double deltaY) {
    leftArm.moveY(deltaY);
    leftHand.moveY(deltaY);
    rightArm.moveY(deltaY);
    rightHand.moveY(deltaY);
}

// Draw
void Arms::draw() const{
    leftHand.draw();
    rightHand.draw();

    leftArm.draw();
    rightArm.draw();
}
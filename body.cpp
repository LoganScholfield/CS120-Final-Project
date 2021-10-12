/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the body file
*/

#include "body.h"

// Constructors
Body::Body(){

    //create body rectangle objects
    //chest = Rect();
    //neck = Rect();

}

Body::Body(Rect chest, Rect neck) {
}

// Setters
void Body::setChestWidth(double w) {

    chest.setWidth(w);
    pants.setWidth(w);
    belt.setWidth(w);
    neck.setWidth(w / 3);
    shirtHole.setRadius(w/6);

    setBodyCenter(chest.getCenterX(), chest.getCenterY());
}
void Body::setChestLength(double l) {

    chest.setHeight(l);
    pants.setHeight(l/3);
    neck.setHeight(l/8);
    belt.setHeight(l/20);

    setBodyCenter(chest.getCenterX(), chest.getCenterY());
}

void Body::setBodyCenter(double x,double y) {

    if(x <= 0 || y <= 0){
        chest.setCenter(0,0);
        neck.setCenter(0,0);
        shirtHole.setCenter(0,0);
        pants.setCenter(0,0);
        belt.setCenter(0,0);
    } else{
        chest.setCenter(x,y);
        pants.setCenter(x,(y+pants.getHeight()));
        neck.setCenter(x,(getChestTopY()-neck.getHeight()/2));
        shirtHole.setCenter(x,neck.getBottomY());
        belt.setCenter(x,pants.getTopY());
    }
}


void Body::setBodyColor(double red, double green, double blue, double alpha) {
    chest.setFillColor(red,green,blue,alpha);
}

void Body::setPantsColor(double red, double green, double blue, double alpha){
    pants.setFillColor(red,green,blue,alpha);
}

void Body::setNeckColor(double red, double green, double blue, double alpha) {
    neck.setFillColor(red,green,blue,alpha);
    shirtHole.setFillColor(red,green,blue,alpha);
}

void Body::setBeltColor(double red, double green, double blue, double alpha) {
    belt.setFillColor(red,green,blue,alpha);
}

double Body::getBodyRedColor() const {
    return chest.getFillRed();
}

double Body::getBodyGreenColor() const {
    return chest.getFillGreen();
}

double Body::getBodyBlueColor() const {
    return chest.getFillBlue();
}

double Body::getChestLeftX() const {
    return chest.getLeftX();
}

double Body::getChestRightX() const {
    return chest.getRightX();
}

double Body::getChestTopY() const {
    return chest.getTopY();
}

double Body::getChestBottomY() const {
    return chest.getBottomY();
}

double Body::getNeckLeftX() const {
    return neck.getLeftX();
}

double Body::getNeckRightX() const {
    return neck.getRightX();
}

double Body::getNeckTopY() const {
    return neck.getTopY();
}

double Body::getNeckBottomY() const {
    return neck.getBottomY();
}

double Body::getPantsLeftX() const {
    return pants.getLeftX();
}

double Body::getPantsRightX() const {
    return pants.getRightX();
}

double Body::getPantsTopY() const {
    return pants.getTopY();
}

double Body::getPantsBottomY() const {
    return pants.getBottomY();
}

void Body::moveX(double deltaX) {
    chest.moveX(deltaX);
    neck.moveX(deltaX);
    shirtHole.moveX(deltaX);
    pants.moveX(deltaX);
    belt.moveX(deltaX);
}

void Body::moveY(double deltaY) {
    chest.moveY(deltaY);
    neck.moveY(deltaY);
    shirtHole.moveY(deltaY);
    pants.moveY(deltaY);
    belt.moveY(deltaY);
}

void Body::draw() const{
    chest.draw();
    neck.draw();
    shirtHole.draw();

    pants.draw();
    belt.draw();
}


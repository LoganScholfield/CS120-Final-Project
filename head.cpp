/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the head file
*/

#include "head.h"

// Constructors
Head::Head() {

    // Create the 3 circles in each eye
    for(int i = 0; i < 3; i++){
        Circle tempEye;
        lEye.push_back(tempEye);
        rEye.push_back(tempEye);
    }

    for(int i = 0; i < 2; i++){
        Circle tempMouth;
        Triangle tempNose;
        mouth.push_back(tempMouth);
        nose.push_back(tempNose);
    }

}

// Setters
void Head::setHeadRadius(double r) {

    if(r <= 0){
        head.setRadius(0);
        hair.setRadius(0);
        // Set radius of all the eyes
        for(int i = 0; i < 3; i++){
            switch(i){
                case 0:
                    lEye[0].setRadius(0);
                    rEye[0].setRadius(0);
                    mouth[0].setRadius(0);
                    nose[0].setHeight(0);
                    nose[0].setBase(0);

                case 1:
                    lEye[1].setRadius(1);
                    rEye[1].setRadius(1);
                    mouth[1].setRadius(1);
                    nose[0].setHeight(1);
                    nose[0].setBase(1);

                case 2:
                    lEye[2].setRadius(2);
                    rEye[2].setRadius(2);
            }
        }
    } else{
        head.setRadius(r);
        hair.setRadius(r);
        // Set radius of all the eyes
        for(int i = 0; i < 3; i++){
            switch(i){
                case 0:
                    lEye[0].setRadius(r*0.2);
                    rEye[0].setRadius(r*0.2);
                    mouth[0].setRadius(r*0.4);
                    nose[0].setHeight(r/6);
                    nose[0].setBase(r/6);

                case 1:
                    lEye[1].setRadius(r*0.1);
                    rEye[1].setRadius(r*0.1);
                    mouth[1].setRadius(r*0.4);
                    nose[1].setHeight(r/6);
                    nose[1].setBase(r/6);

                case 2:
                    lEye[2].setRadius(r*0.055);
                    rEye[2].setRadius(r*0.055);
            }
        }
    }

    setHeadCenter(head.getCenterX(), head.getCenterY());

}

void Head::setHeadCenter(double x,double y) {

    if(x <= 0 || y <= 0){
        head.setCenter(0,0);
        hair.setCenter(0,0);
        // Set radius of all the eyes
        for(int i = 0; i < 3; i++){
            switch(i){
                case 0:
                    lEye[0].setCenter(0,0);
                    rEye[0].setCenter(0,0);
                    mouth[0].setCenter(0,0);
                    nose[0].setCenter(0,0);

                case 1:
                    lEye[1].setCenter(0,0);
                    rEye[1].setCenter(0,0);
                    mouth[1].setCenter(0,0);
                    nose[1].setCenter(0,0);

                case 2:
                    lEye[2].setCenter(0,0);;
                    rEye[2].setCenter(0,0);;
            }
        }
    } else{
        head.setCenter(x,y);
        hair.setCenter(x,y-2);
        // Set radius of all the eyes
        for(int i = 0; i < 3; i++){
            switch(i){
                case 0:
                    lEye[0].setCenter(x-(head.getRadius()/2),y-(head.getRadius()/4));
                    rEye[0].setCenter(x+(head.getRadius()/2),y-(head.getRadius()/4));
                    mouth[1].setCenter(x, y+(head.getRadius()/4));
                    nose[0].setCenter(x-1,y+1);

                case 1:
                    lEye[1].setCenter(x-(head.getRadius()/2),y-(head.getRadius()/4));
                    rEye[1].setCenter(x+(head.getRadius()/2),y-(head.getRadius()/4));
                    mouth[0].setCenter(x, y+(3*head.getRadius()/8));
                    nose[1].setCenter(x+2,y-1);

                case 2:
                    lEye[2].setCenter(x-(head.getRadius()/2),y-(head.getRadius()/4));
                    rEye[2].setCenter(x+(head.getRadius()/2),y-(head.getRadius()/4));
            }
        }
    }

}

void Head::setHeadColor(double red, double green, double blue, double alpha) {
    head.setFillColor(red,green,blue,alpha);
    mouth[1].setFillColor(red,green,blue,alpha);

    hair.setFillColor(75/255.0,40/255.0,0/255.0, 1);

    nose[0].setFillColor(0,0,0,1);
    nose[1].setFillColor(red,green,blue,alpha);
}

void Head::setHeadColor(color fill){
    head.setFillColor(fill);
    mouth[1].setFillColor(fill);

    nose[1].setFillColor(fill);
    hair.setFillColor(75/255.0,40/255.0,0/255.0, 1);
}

void Head::setEyeColor(double red, double green, double blue, double alpha) {

    lEye[0].setFillColor(1,1,1,alpha);
    rEye[0].setFillColor(1,1,1,alpha);

    lEye[1].setFillColor(red,green,blue,alpha);
    rEye[1].setFillColor(red,green,blue,alpha);

    lEye[2].setFillColor(0,0,0,alpha);
    rEye[2].setFillColor(0,0,0,alpha);
}

void Head::setEyeColor(color fill) {

    lEye[0].setFillColor(1,1,1,1);
    rEye[0].setFillColor(1,1,1,1);

    lEye[1].setFillColor(fill);
    rEye[1].setFillColor(fill);

    lEye[2].setFillColor(0,0,0,1);
    rEye[2].setFillColor(0,0,0,1);
}

double Head::getHeadRadius() const {
    return head.getRadius();
}

double Head::getHeadRedColor() const {
    return head.getFillRed();
}

double Head::getHeadGreenColor() const {
    return head.getFillGreen();
}

double Head::getHeadBlueColor() const {
    return head.getFillBlue();
}

double Head::getEyesRedColor() const {
    return lEye[1].getFillRed();
}

double Head::getEyesGreenColor() const {
    return lEye[1].getFillGreen();
}

double Head::getEyesBlueColor() const {
    return lEye[1].getFillBlue();
}

double Head::getLeftX() const {
    return head.getLeftX();
}

double Head::getRightX() const {
    return head.getRightX();
}

double Head::getTopY() const {
    return hair.getTopY();
}

double Head::getBottomY() const {
    return head.getBottomY();
}

double Head::getLEyeLeftX() const {
    return lEye[0].getLeftX();
}

double Head::getLEyeRightX() const {
    return lEye[0].getRightX();
}

double Head::getLEyeTopY() const {
    return lEye[0].getTopY();
}

double Head::getLEyeBottomY() const {
    return lEye[0].getBottomY();
}

double Head::getREyeLeftX() const {
    return rEye[0].getLeftX();
}

double Head::getREyeRightX() const {
    return rEye[0].getRightX();
}

double Head::getREyeTopY() const {
    return rEye[0].getTopY();
}

double Head::getREyeBottomY() const {
    return rEye[0].getBottomY();
}

void Head::moveX(double deltaX) {
    head.moveX(deltaX);

    for(int i = 0; i < 3; i++){
        lEye[i].moveX(deltaX);
        rEye[i].moveX(deltaX);
    }

    mouth[0].moveX(deltaX);
    mouth[1].moveX(deltaX);

    nose[0].moveX(deltaX);
    nose[1].moveX(deltaX);

    hair.moveX(deltaX);
}

void Head::moveY(double deltaY) {
    head.moveY(deltaY);

    for(int i = 0; i < 3; i++){
        lEye[i].moveY(deltaY);
        rEye[i].moveY(deltaY);
    }

    mouth[0].moveY(deltaY);
    mouth[1].moveY(deltaY);

    nose[0].moveY(deltaY);
    nose[1].moveY(deltaY);
    hair.moveY(deltaY);
}

void Head::draw() const{
    hair.draw();
    head.draw();

    for(int i = 0; i < 3; i++){
        lEye[i].draw();
        rEye[i].draw();
    }

    mouth[0].draw();
    mouth[1].draw();

    nose[0].draw();
    nose[1].draw();
}
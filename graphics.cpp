/*
// Created by Katie Goodelman, Joe Yando and Logan Scholfield
// Completed on May 13, 2021
// CS120 final project
// This project allows a user to go through three different screens that work to
// explain the game to the user, allow them to edit their giant and then move them through a maze
// this is the graphics file
*/
#include "graphics.h"
#include "head.h"
#include "body.h"
#include "body.cpp"
#include "arms.h"
#include "arms.cpp"
#include "legs.h"
#include "legs.cpp"
#include "button.h"
#include "button.cpp"
#include "Quad.h"
#include "Quad.cpp"
#include "rect.h"
#include "sign.h"
#include "sign.cpp"
#include "triangle.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

GLdouble width, height;
int wd;
// set enum for different screens of game

enum screens{
    first, second, third, fourth
};

screens screen;

// initialize all needed vectors and variables
Head head;
Body bod;
Arms arms;
Legs legs;

bool colorHead;
bool colorEyes;
bool colorShirt;
bool colorPants;
bool changeSize;
bool overlapping;
bool fruitTree1;
bool fruitTree2;
bool fruitTree3;
bool fruitTree4;
int treeCount = 0;


string count = "you collected ";

Button startButton({.5,0,.09},{350,200},250,150,"Click here to begin!");
Button secondButton({.4,.4,.4},{300,25},200,50,"Finalize Creation!");
Rect introBackground({20/255.0, 150/255.0,200/225.0}, 0,0, {1400,1400});
Sign introOne({.5,.55,.35},{350,355},350,75,"This is the giant creator game");
Sign introTwo({.5,.55,.35},{350,405},350,75,"Hover over the giants different body parts");
Sign introThree({.5,.55,.35},{350,455},350,75,"and click r, b or g to edit its color");

Sign exitOne({.5,.55,.35},{350,255},350,150,"Congratulations!");
Sign exitTwo({.5,.55,.35},{350,355},450,150,"You have made it through the maze successfully");

const color white(1, 1, 1);
const color lightBlue(70/255.0, 200/255.0,250/225.0);
const color green(20/255.0,180/255.0,55/255.0);
const color beanGreen(20/255.0, 150/255.0, 40/255.0);
const color leafGreen1(140/255.0, 175/255.0, 50/255.0);
const color leafGreen2(110/255.0, 200/255.0, 60/255.0);
const color brown(150/255.0, 75/255.0, 0/255.0);
const color lightBrown(200/255.0, 125/255.0, 0/255.0);
const color darkBrown(75/255.0,40/255.0,0/255.0);
const color beige(250/255.0,250/255.0,120/255.0);
const color brickRed(150/255.0,10/255.0,10/255.0);
const color mazeGreen(0.3,1.0,0.5);
const color orange(1.0,0.6,0.1);
const color purple (0.8,0.1,0.8);
const color yellow(1.0,1.0,0.2);

vector<unique_ptr<Shape>> bigClouds;
vector<unique_ptr<Shape>> smallClouds;
Rect skyBackground({70/255.0, 200/255.0,250/225.0}, 0,0, {1400,1400});
Rect mazeBackground({.3,1,.5},0,0,{1400,1400});
Rect grassBase;
Rect beanStalk;
Triangle grassT;
vector<unique_ptr<Shape>> mountains;
vector<unique_ptr<Shape>> leaves;
vector<Rect> borders;
vector<Rect> hozWalls;
vector<Rect> vertWalls;
vector<Rect> treeWalls;
vector<unique_ptr<Shape>> trees;
vector<unique_ptr<Shape>> house;
vector<Circle> magicFruits;
vector<unique_ptr<Triangle>> sunRays;
Rect user;
Circle sunBase(yellow,100,100,30);

void initCaps() {
    dimensions cap(20,20);
    hozWalls.emplace_back(Rect(brown,110,110,cap));
    hozWalls.emplace_back(Rect(brown,105, 600, cap));
    hozWalls.emplace_back(Rect(brown,220,580,cap));
    hozWalls.emplace_back(Rect(brown,400, 100, cap));
    hozWalls.emplace_back(Rect(brown,400, 150, cap));
    hozWalls.emplace_back(Rect(brown,310, 80, cap));
    hozWalls.emplace_back(Rect(brown,590, 330, cap));
    hozWalls.emplace_back(Rect(brown,220, 500, cap));
    hozWalls.emplace_back(Rect(brown,400, 180, cap));
    hozWalls.emplace_back(Rect(brown,590, 250, cap));
    hozWalls.emplace_back(Rect(brown,120, 500, cap));
    hozWalls.emplace_back(Rect(brown,490, 250, cap));
    hozWalls.emplace_back(Rect(brown,435, 590, cap));


    vertWalls.emplace_back(Rect(brown,120, 500, cap));
    vertWalls.emplace_back(Rect(brown,105, 600, cap));
    vertWalls.emplace_back(Rect(brown,330, 490, cap));
    vertWalls.emplace_back(Rect(brown,340, 400, cap));
    vertWalls.emplace_back(Rect(brown,110, 400, cap));
    vertWalls.emplace_back(Rect(brown,330, 290, cap));
    vertWalls.emplace_back(Rect(brown,455, 330, cap));
    vertWalls.emplace_back(Rect(brown,490, 250, cap));
    vertWalls.emplace_back(Rect(brown,600, 110, cap));
    vertWalls.emplace_back(Rect(brown,610, 440, cap));
    vertWalls.emplace_back(Rect(brown,435, 590, cap));
    vertWalls.emplace_back(Rect(brown,500, 490, cap));
    vertWalls.emplace_back(Rect(brown,210, 180, cap));
    vertWalls.emplace_back(Rect(brown,250, 290, cap));
    vertWalls.emplace_back(Rect(brown,520, 110, cap));
    vertWalls.emplace_back(Rect(brown,510, 490, cap));

    // tree walls for detection
    treeWalls.clear();
    dimensions wall(10,70);
    treeWalls.emplace_back(Rect(mazeGreen,250,245,wall));
    treeWalls.emplace_back(Rect(mazeGreen,100,645,wall));
    treeWalls.emplace_back(Rect(mazeGreen,600,545,wall));
    treeWalls.emplace_back(Rect(mazeGreen,600,205,wall));

}

void initUser() {
    user.setCenter(41,52);
    user.setSize(42,64);
    user.setFillColor(mazeGreen);
}

void initBorders() {
    borders.clear();
    dimensions vertSides(20,700);
    dimensions hozSides(700,20);
    borders.emplace_back(Rect(brown,10,350,vertSides));
    borders.emplace_back(Rect(brown, 690, 350, vertSides));
    borders.emplace_back(Rect(brown,350,10,hozSides));
    borders.emplace_back(Rect(brown,350,690,hozSides));

}

void initWalls() {
    // clear vectors
    hozWalls.clear();
    vertWalls.clear();

    // determine sizes of vertical walls
    dimensions vertSize1(20,300);
    dimensions vertSize2(20,250);
    dimensions vertSize3(20,100);
    dimensions vertSize4(20,150);
    // add vertical wall object pointers to vector
    vertWalls.emplace_back(Rect(brown, 110, 250, vertSize1));
    vertWalls.emplace_back(Rect(brown, 210, 60, vertSize2));
    vertWalls.emplace_back(Rect(brown, 250, 350, vertSize3));
    vertWalls.emplace_back(Rect(brown, 170, 450, vertSize3));
    vertWalls.emplace_back(Rect(brown, 220, 540, vertSize3));
    vertWalls.emplace_back(Rect(brown, 330, 620, vertSize2));
    vertWalls.emplace_back(Rect(brown, 400, 140, vertSize3));
    vertWalls.emplace_back(Rect(brown, 310, 40, vertSize3));
    vertWalls.emplace_back(Rect(brown, 330, 240, vertSize3));
    vertWalls.emplace_back(Rect(brown, 510, 410, vertSize4));
    vertWalls.emplace_back(Rect(brown, 520, 180, vertSize4));
    vertWalls.emplace_back(Rect(brown, 590, 290, vertSize3));

    // determine sizes for horizontal walls
    dimensions hozSize1(250,20);
    dimensions hozSize2(100,20);
    dimensions hozSize3(200,20);
    dimensions hozSize4(150,20);

    // add horizontal wall object pointers to vector
    hozWalls.emplace_back(Rect(brown, 225, 400, hozSize1));
    hozWalls.emplace_back(Rect(brown, 60, 600, hozSize2));
    hozWalls.emplace_back(Rect(brown, 170, 500, hozSize2));
    hozWalls.emplace_back(Rect(brown, 300, 180, hozSize3));
    hozWalls.emplace_back(Rect(brown, 290, 290, hozSize2));
    hozWalls.emplace_back(Rect(brown, 420, 490, hozSize3));
    hozWalls.emplace_back(Rect(brown, 560, 110, hozSize2));
    hozWalls.emplace_back(Rect(brown, 520, 330, hozSize4));
    hozWalls.emplace_back(Rect(brown, 540, 250, hozSize2));
    hozWalls.emplace_back(Rect(brown, 650, 440, hozSize2));
    hozWalls.emplace_back(Rect(brown, 650, 440, hozSize2));
    hozWalls.emplace_back(Rect(brown, 560, 590, hozSize1));

}

void initMazeItems() {
    trees.clear();
    dimensions trunk(20,40);
    dimensions bottom(20,20);
    // first tree
    trees.push_back(make_unique<Rect>(darkBrown, 290,260,trunk));
    trees.push_back(make_unique<Circle>(beanGreen,275,245,15));
    trees.push_back(make_unique<Circle>(beanGreen,305,245,15));
    trees.push_back(make_unique<Circle>(beanGreen,290,235,18));
    trees.push_back(make_unique<Rect>(beanGreen,290,245,bottom));

    // second tree
    trees.push_back(make_unique<Rect>(darkBrown, 50,660,trunk));
    trees.push_back(make_unique<Circle>(beanGreen,35,645,15));
    trees.push_back(make_unique<Circle>(beanGreen,65,645,15));
    trees.push_back(make_unique<Circle>(beanGreen,50,635,18));
    trees.push_back(make_unique<Rect>(beanGreen,50,645,bottom));

    // third tree
    trees.push_back(make_unique<Rect>(darkBrown, 650,560,trunk));
    trees.push_back(make_unique<Circle>(beanGreen,635,545,15));
    trees.push_back(make_unique<Circle>(beanGreen,665,545,15));
    trees.push_back(make_unique<Circle>(beanGreen,650,535,18));
    trees.push_back(make_unique<Rect>(beanGreen,650,545,bottom));

    // fourth tree
    trees.push_back(make_unique<Rect>(darkBrown, 560,220,trunk));
    trees.push_back(make_unique<Circle>(beanGreen,545,205,15));
    trees.push_back(make_unique<Circle>(beanGreen,575,205,15));
    trees.push_back(make_unique<Circle>(beanGreen,560,195,18));
    trees.push_back(make_unique<Rect>(beanGreen,560,205,bottom));

    // house end
    house.clear();
    dimensions hBase(50,40);
    dimensionsT tBase(52,25);
    dimensions door(15,25);
    dimensions window(10,10);
    dimensions windowIn(6,6);
    dimensions windowShadeV(2,8);
    dimensions windowShadeH(8,2);
    dimensions chimney(10,35);

    house.push_back(make_unique<Rect>(brickRed,665,635,chimney));
    house.push_back(make_unique<Rect>(beige,650, 660,hBase));
    house.push_back(make_unique<Triangle>(brown, 650, 628,tBase));
    house.push_back(make_unique<Rect>(brown, 650, 668, door));
    house.push_back(make_unique<Rect>(brown, 635, 650,window));
    house.push_back(make_unique<Rect>(brown, 665, 650,window));

    house.push_back(make_unique<Rect>(white, 635, 650,windowIn));
    house.push_back(make_unique<Rect>(white, 665, 650,windowIn));
    house.push_back(make_unique<Rect>(brown, 635, 650,windowShadeV));
    house.push_back(make_unique<Rect>(brown, 635, 650,windowShadeH));
    house.push_back(make_unique<Rect>(brown, 665, 650,windowShadeV));
    house.push_back(make_unique<Rect>(brown, 665, 650,windowShadeH));


    // tree one
    magicFruits.emplace_back(Circle(orange,270,240,5));
    magicFruits.emplace_back(Circle(orange,280,250,5));
    magicFruits.emplace_back(Circle(orange,290,230,5));
    magicFruits.emplace_back(Circle(orange,295,245,5));
    magicFruits.emplace_back(Circle(orange,310,242,5));

    // tree two
    magicFruits.emplace_back(Circle(purple,40,640,5));
    magicFruits.emplace_back(Circle(purple,30,650,5));
    magicFruits.emplace_back(Circle(purple,50,630,5));
    magicFruits.emplace_back(Circle(purple,60,640,5));
    magicFruits.emplace_back(Circle(purple,70,650,5));

    // tree three
    magicFruits.emplace_back(Circle(yellow,550,190,5));
    magicFruits.emplace_back(Circle(yellow,570,190,5));
    magicFruits.emplace_back(Circle(yellow,545,205,5));
    magicFruits.emplace_back(Circle(yellow,575,205,5));
    magicFruits.emplace_back(Circle(yellow,560,210,5));

    // fourth tree
    magicFruits.emplace_back(Circle(lightBlue,640,530,5));
    magicFruits.emplace_back(Circle(lightBlue,660,530,5));
    magicFruits.emplace_back(Circle(lightBlue,650,540,5));
    magicFruits.emplace_back(Circle(lightBlue,640,550,5));
    magicFruits.emplace_back(Circle(lightBlue,660,550,5));

    fruitTree1 = true;
    fruitTree2 = true;
    fruitTree3 = true;
    fruitTree4 = true;
}

void initBackground(){
    // sunRays
    dimensionsT ray(15,15);
    for (double i = 0; i < 2.0*PI+0.5; i += PI/4) {
        sunRays.push_back(make_unique<Triangle>(yellow,100 + (45 * cos(i)), 100 + (45 * sin(i)), ray));
    }

    // set grass base for bottom of screen
    grassBase.setCenter(0,650);
    grassBase.setSize(2*width,height/4);
    grassBase.setFillColor(green);

    // set beanStalk rectangle object
    beanStalk.setCenter(570,320);
    beanStalk.setSize(90, 700);
    beanStalk.setFillColor(beanGreen);

    // set triangle base for beanStalk object
    grassT.setCenter(570,350);
    grassT.setSize(190,650);
    grassT.setFillColor(beanGreen);

    // set triangles for mountains and add to vector
    dimensionsT mountain1(450,500);
    dimensionsT mountain2(350,350);
    mountains.clear();
    mountains.push_back(make_unique<Triangle>(lightBrown, 250, 315, mountain1));
    mountains.push_back(make_unique<Triangle>(brown,100, 395, mountain2));

    // set leaves for beanStalk and add to vector
    dimensionsT leaf1(30,30);
    leaves.clear();
    leaves.push_back(make_unique<Circle>(leafGreen1, 510,580, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen1, 500,580,leaf1));

    leaves.push_back(make_unique<Circle>(leafGreen1, 620,480, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen1, 630,480,leaf1));

    leaves.push_back(make_unique<Circle>(leafGreen2, 610,310, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen2, 620,310,leaf1));

    leaves.push_back(make_unique<Circle>(leafGreen2, 580,620, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen2, 590,620,leaf1));

    leaves.push_back(make_unique<Circle>(leafGreen1, 580,70, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen1, 590,70,leaf1));

    leaves.push_back(make_unique<Circle>(leafGreen2, 540,430, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen2, 530,430,leaf1));

    leaves.push_back(make_unique<Circle>(leafGreen2, 530,180, 16));
    leaves.push_back(make_unique<Triangle>(leafGreen2, 520,180,leaf1));
}
void initClouds() {
    bigClouds.clear();
    smallClouds.clear();
    dimensions largeCloudBottom (40,40);
    dimensions smallCloudBottom(30,30);

    // first cloud
    bigClouds.push_back(make_unique<Circle>(white, 250, 200, 30));
    bigClouds.push_back(make_unique<Circle>(white, 300, 200, 30));
    bigClouds.push_back(make_unique<Circle>(white, 280, 175, 30));
    bigClouds.push_back(make_unique<Rect>(white,270, 210, largeCloudBottom));

    // second cloud
    bigClouds.push_back(make_unique<Circle>(white, 400, 90, 30));
    bigClouds.push_back(make_unique<Circle>(white, 450, 90, 30));
    bigClouds.push_back(make_unique<Circle>(white, 430, 65, 30));
    bigClouds.push_back(make_unique<Rect>(white,420, 100, largeCloudBottom));

    // third cloud
    bigClouds.push_back(make_unique<Circle>(white, 50, 140, 30));
    bigClouds.push_back(make_unique<Circle>(white, 100, 140, 30));
    bigClouds.push_back(make_unique<Circle>(white, 80, 115, 30));
    bigClouds.push_back(make_unique<Rect>(white,70, 150, largeCloudBottom));

    // fourth cloud
    smallClouds.push_back(make_unique<Circle>(white, 30, 40, 20));
    smallClouds.push_back(make_unique<Circle>(white, 60, 40, 20));
    smallClouds.push_back(make_unique<Circle>(white, 50, 30, 20));
    smallClouds.push_back(make_unique<Rect>(white,45, 45, smallCloudBottom));

    // fifth cloud
    smallClouds.push_back(make_unique<Circle>(white, 170, 130, 20));
    smallClouds.push_back(make_unique<Circle>(white, 200, 130, 20));
    smallClouds.push_back(make_unique<Circle>(white, 190, 120, 20));
    smallClouds.push_back(make_unique<Rect>(white,185, 135, smallCloudBottom));
}
void initHead(){
    head.setHeadRadius(50);
    head.setHeadCenter(250,310);
    head.setHeadColor(1, 0.85, 0.45,1);
    head.setEyeColor(0,1,0,1);
}

void clearAll(){
    bigClouds.clear();
    smallClouds.clear();
    mountains.clear();
    leaves.clear();
}


void initBody(){
    bod.setChestLength(head.getHeadRadius()*3);
    bod.setChestWidth(head.getHeadRadius()*2);
    bod.setBodyCenter(250,head.getBottomY()+85);
    bod.setBodyColor(1,.2,.4,1);
    bod.setNeckColor(1, 0.85, 0.45,1);
    bod.setPantsColor(0,0,1,1);
    bod.setBeltColor(0,0,0,1);
}

void initArms(){
    arms.setArmSize(40, 80);
    arms.setLArmCenter(bod.getChestLeftX()-(arms.getArmLength()/2),bod.getChestTopY()+(arms.getArmWidth()/3));
    arms.setRArmCenter(bod.getChestRightX()+(arms.getArmLength()/2),bod.getChestTopY()+(arms.getArmWidth()/3));
    arms.setArmColor(1,.2,.4,1);
    arms.setHandColor(1, 0.85, 0.45,1);
}

void initLegs(){
    legs.setLegSize(110,40);
    legs.setLLegCenter(bod.getChestLeftX()+(legs.getLegWidth()/2), bod.getChestBottomY()+(legs.getLegLength()/2));
    legs.setRLegCenter(bod.getChestRightX()-(legs.getLegWidth()/2), bod.getChestBottomY()+(legs.getLegLength()/2));
    legs.setLegColor(0,0,1,1);
    legs.setFootColor(1, 0.85, 0.45,1);
}

void init() {
    width = 700;
    height = 700;
    string screen = "first";
    initClouds();
    initHead();
    initBody();
    initArms();
    initLegs();
    initBackground();
    initBorders();
    initWalls();
    initMazeItems();
    initUser();
    initCaps();
    changeSize = false;
}

void initChangeSize(){
    // Change head size
    head.setHeadRadius(head.getHeadRadius()/6);
    // Change body size
    bod.setChestLength(head.getHeadRadius()*3);
    bod.setChestWidth(head.getHeadRadius()*2);
    // Change leg size
    arms.setArmSize(40/6, 80/6);
    // Change arm size
    legs.setLegSize(110/6,40/6);
    // Change center
    head.setHeadCenter(42,30);
    bod.setBodyCenter(42,head.getBottomY()+15);
    arms.setLArmCenter(bod.getChestLeftX()-(arms.getArmLength()/2),bod.getChestTopY()+(arms.getArmWidth()/3));
    arms.setRArmCenter(bod.getChestRightX()+(arms.getArmLength()/2),bod.getChestTopY()+(arms.getArmWidth()/3));
    legs.setLLegCenter(bod.getChestLeftX()+(legs.getLegWidth()/2), bod.getChestBottomY()+(legs.getLegLength()/3));
    legs.setRLegCenter(bod.getChestRightX()-(legs.getLegWidth()/2), bod.getChestBottomY()+(legs.getLegLength()/3));

    changeSize = true;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0, 0, 0, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE



    switch(screen) {
        case first:
            introBackground.draw();
            startButton.draw();
            introOne.draw();
            introTwo.draw();
            introThree.draw();
            break;

        case second:
            skyBackground.draw();
            sunBase.draw();
            for(unique_ptr<Triangle> &s : sunRays) {
                s->draw();
            }
            // clouds and mountain background for build giant (small clouds go behind mountains, large clouds go in front)
            for (unique_ptr<Shape> &sC : smallClouds) {
                // #polymorphism
                sC->draw();
            }
            for (unique_ptr<Shape> &m : mountains) {
                // #polymorphism
                m->draw();
            }
            for (unique_ptr<Shape> &s : bigClouds) {
                // #polymorphism
                s->draw();
            }

            // draw grass base
            grassBase.draw();
            // draw body of beanstalk
            grassT.draw();
            beanStalk.draw();
            // draw leaves on beanstalk
            for (unique_ptr<Shape> &l : leaves) {
                // #polymorphism
                l->draw();
            }

            // giant avatar initial draw
            bod.draw();
            arms.draw();
            legs.draw();
            head.draw();
            secondButton.draw();
            break;
        case third:
            mazeBackground.draw();
            user.draw();
            for (Rect &b : borders) {
                // #polymorphism
                b.draw();
            }
            for (Rect &v : vertWalls) {
                // #polymorphism
                v.draw();
            }
            for (Rect &h : hozWalls) {
                // #polymorphism
                h.draw();
            }
            for(Rect &tW : treeWalls) {
                tW.draw();
            }
            for (unique_ptr<Shape> &t : trees) {
                // #polymorphism
                t->draw();
            }
            /*for(Circle &f: magicFruits) {
                f.draw();
            }*/
            for (unique_ptr<Shape> &h : house) {
                // #polymorphism
                h->draw();
            }


            if(!changeSize){
                initChangeSize();
                head.draw();
                bod.draw();
                arms.draw();
                legs.draw();
            } else{
                head.draw();
                bod.draw();
                arms.draw();
                legs.draw();
            }

            // Check if user has overlapped tree wall 1
            if(user.isOverlapping(treeWalls[0])){
                if(fruitTree1){
                    treeCount++;
                }
                fruitTree1 = false;
            }

            if(fruitTree1) {
                for(int i = 0; i < 5; i++) {
                    magicFruits[i].draw();
                }
            }

            // Check if user has overlapped tree wall 2
            if(user.isOverlapping(treeWalls[1])){
                if(fruitTree2){
                    treeCount++;
                }
                fruitTree2 = false;
            }

            if(fruitTree2) {
                for(int j = 5; j < 10; j++) {
                    magicFruits[j].draw();
                }
            }

            // Check if user has overlapped tree wall 4
            if(user.isOverlapping(treeWalls[3])){
                if(fruitTree3){
                    treeCount++;
                }
                fruitTree3 = false;
            }

            if(fruitTree3) {
                for(int i = 10; i < 15; i++) {
                    magicFruits[i].draw();
                }
            }

            // Check if user has overlapped tree wall 3
            if(user.isOverlapping(treeWalls[2])){
                if(fruitTree4){
                    treeCount++;
                }
                fruitTree4 = false;
            }

            if(fruitTree4) {
                for(int j = 15; j < 20; j++) {
                    magicFruits[j].draw();
                }
            }

            if(user.getRightX() > 625 && user.getBottomY() > 640){
                screen = fourth;
            }

            break;
        case fourth:
            string congratMessage;
            if(treeCount >= 4){
                congratMessage = "You did amazing";
            } else if(treeCount == 0){
                congratMessage = "Try collecting apples";
            }
            else{
                congratMessage = "You can do better";
            }

            string FinalMessage = "You have collected ";
            FinalMessage.append(to_string(treeCount*5));
            FinalMessage.append(" magical fruit");
            Sign exitThree({.5,.55,.35},{350,410},450,15,FinalMessage);
            Sign exitFour({.5,.55,.35},{350,450},450,40,congratMessage);

            introBackground.draw();
            exitOne.draw();
            exitTwo.draw();
            exitThree.draw();
            exitFour.draw();



            break;
    }
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {

    // Initialize all the coloring things to false
    colorHead = false;
    colorEyes = false;
    colorShirt = false;
    colorPants = false;

    // Check if cursor is over the head or neck
    if((head.getLeftX() < x && head.getRightX() > x) && (head.getBottomY() > y && head.getTopY() < y)){
        colorHead = true;
    }else if((bod.getNeckLeftX() < x && bod.getNeckRightX() > x) && (bod.getNeckBottomY() > y && head.getTopY() < y)){
        colorHead = true;
    }

    // Check if cursor is over the eyes
    if((head.getLEyeLeftX() < x && head.getLEyeRightX() > x) && (head.getLEyeBottomY() > y && head.getLEyeTopY() < y)) {
        colorHead = false;
        colorEyes = true;
    } else if((head.getREyeLeftX() < x && head.getREyeRightX() > x) && (head.getREyeBottomY() > y && head.getREyeTopY() < y)){
        colorHead = false;
        colorEyes = true;
    }

    // Check if cursor is over the shirt or arms
    if((bod.getChestLeftX() < x && bod.getChestRightX() > x) && (bod.getChestBottomY() > y && bod.getChestTopY() < y)){
        colorShirt = true;
    } else if((arms.getLeftArmLeftX() < x && arms.getLeftArmRightX() > x) && (arms.getLeftArmBottomY() > y && arms.getLeftArmTopY() < y)){
        colorShirt = true;

    } else if((arms.getRightArmLeftX() < x && arms.getRightArmRightX() > x) && (arms.getRightArmBottomY() > y && arms.getRightArmTopY() < y)){
        colorShirt = true;

    }
    // Check if cursor is over the pants or legs
    if((bod.getPantsLeftX() < x && bod.getPantsRightX() > x) && (bod.getPantsBottomY() > y && bod.getPantsTopY() < y)){
        colorPants = true;
        colorShirt = false;
    } else if((legs.getLeftLegLeftX() < x && legs.getLeftLegRightX() > x) && (legs.getLeftLegBottomY() > y && legs.getLeftLegTopY() < y)){
        colorPants = true;

    } else if((legs.getRightLegLeftX() < x && legs.getRightLegRightX() > x) && (legs.getRightLegBottomY() > y && legs.getRightLegTopY() < y)){
        colorPants = true;

    }

    if(screen == second) {
        switch (key) {
            case 'r' : {
                if (colorHead) {
                    if (head.getHeadRedColor() < 0.96) {
                        bod.setNeckColor(head.getHeadRedColor() + 0.05, head.getHeadGreenColor(),
                                         head.getHeadBlueColor(), 1);
                        arms.setHandColor(head.getHeadRedColor() + 0.05, head.getHeadGreenColor(),
                                          head.getHeadBlueColor(), 1);
                        legs.setFootColor(head.getHeadRedColor() + 0.05, head.getHeadGreenColor(),
                                          head.getHeadBlueColor(), 1);
                        head.setHeadColor(head.getHeadRedColor() + 0.05, head.getHeadGreenColor(),
                                          head.getHeadBlueColor(), 1);
                    } else {
                        arms.setHandColor(0, head.getHeadGreenColor(), head.getHeadBlueColor(), 1);
                        legs.setFootColor(0, head.getHeadGreenColor(), head.getHeadBlueColor(), 1);
                        bod.setNeckColor(0, head.getHeadGreenColor(), head.getHeadBlueColor(), 1);
                        head.setHeadColor(0, head.getHeadGreenColor(), head.getHeadBlueColor(), 1);
                    }
                } else if (colorEyes) {
                    if (head.getEyesRedColor() < 0.96) {
                        head.setEyeColor(head.getEyesRedColor() + 0.05, head.getEyesGreenColor(),
                                         head.getEyesBlueColor(), 1);
                    } else {
                        head.setEyeColor(0, head.getEyesGreenColor(), head.getEyesBlueColor(), 1);
                    }
                } else if (colorShirt) {
                    if (bod.getBodyRedColor() < 0.96) {
                        arms.setArmColor(bod.getBodyRedColor() + 0.05, bod.getBodyGreenColor(), bod.getBodyBlueColor(),
                                         1);
                        bod.setBodyColor(bod.getBodyRedColor() + 0.05, bod.getBodyGreenColor(), bod.getBodyBlueColor(),
                                         1);
                    } else {
                        arms.setArmColor(0, bod.getBodyGreenColor(), bod.getBodyBlueColor(), 1);
                        bod.setBodyColor(0, bod.getBodyGreenColor(), bod.getBodyBlueColor(), 1);
                    }
                } else if (colorPants) {
                    if (legs.getLegsRedColor() < 0.96) {
                        bod.setPantsColor(legs.getLegsRedColor() + 0.05, legs.getLegsGreenColor(),
                                          legs.getLegsBlueColor(), 1);
                        legs.setLegColor(legs.getLegsRedColor() + 0.05, legs.getLegsGreenColor(),
                                         legs.getLegsBlueColor(), 1);
                    } else {
                        bod.setPantsColor(0, legs.getLegsGreenColor(), legs.getLegsBlueColor(), 1);
                        legs.setLegColor(0, legs.getLegsGreenColor(), legs.getLegsBlueColor(), 1);
                    }
                }
            }
            case 'g' : {
                if (colorHead) {
                    if (head.getHeadGreenColor() < 0.96) {
                        arms.setHandColor(head.getHeadRedColor(), head.getHeadGreenColor() + 0.05,
                                          head.getHeadBlueColor(), 1);
                        legs.setFootColor(head.getHeadRedColor(), head.getHeadGreenColor() + 0.05,
                                          head.getHeadBlueColor(), 1);
                        bod.setNeckColor(head.getHeadRedColor(), head.getHeadGreenColor() + 0.05,
                                         head.getHeadBlueColor(), 1);
                        head.setHeadColor(head.getHeadRedColor(), head.getHeadGreenColor() + 0.05,
                                          head.getHeadBlueColor(), 1);
                    } else {
                        arms.setHandColor(head.getHeadRedColor(), 0, head.getHeadBlueColor(), 1);
                        legs.setFootColor(head.getHeadRedColor(), 0, head.getHeadBlueColor(), 1);
                        bod.setNeckColor(head.getHeadRedColor(), 0, head.getHeadBlueColor(), 1);
                        head.setHeadColor(head.getHeadRedColor(), 0, head.getHeadBlueColor(), 1);
                    }
                } else if (colorEyes) {
                    if (head.getEyesGreenColor() < 0.96) {
                        head.setEyeColor(head.getEyesRedColor(), head.getEyesGreenColor() + 0.05,
                                         head.getEyesBlueColor(), 1);
                    } else {
                        head.setEyeColor(head.getEyesRedColor(), 0, head.getEyesBlueColor(), 1);
                    }
                } else if (colorShirt) {
                    if (bod.getBodyGreenColor() < 0.96) {
                        arms.setArmColor(bod.getBodyRedColor(), bod.getBodyGreenColor() + 0.05, bod.getBodyBlueColor(),
                                         1);
                        bod.setBodyColor(bod.getBodyRedColor(), bod.getBodyGreenColor() + 0.05, bod.getBodyBlueColor(),
                                         1);
                    } else {
                        arms.setArmColor(bod.getBodyRedColor(), 0, bod.getBodyBlueColor(), 1);
                        bod.setBodyColor(bod.getBodyRedColor(), 0, bod.getBodyBlueColor(), 1);
                    }
                } else if (colorPants) {
                    if (legs.getLegsGreenColor() < 0.96) {
                        bod.setPantsColor(legs.getLegsRedColor(), legs.getLegsGreenColor() + 0.05,
                                          legs.getLegsBlueColor(), 1);
                        legs.setLegColor(legs.getLegsRedColor(), legs.getLegsGreenColor() + 0.05,
                                         legs.getLegsBlueColor(), 1);
                    } else {
                        bod.setPantsColor(legs.getLegsRedColor(), 0, legs.getLegsBlueColor(), 1);
                        legs.setLegColor(legs.getLegsRedColor(), 0, legs.getLegsBlueColor(), 1);
                    }
                }
            }
            case 'b' : {
                if (colorHead) {
                    if (head.getHeadBlueColor() < 0.96) {
                        arms.setHandColor(head.getHeadRedColor(), head.getHeadGreenColor(),
                                          head.getHeadBlueColor() + 0.05, 1);
                        legs.setFootColor(head.getHeadRedColor(), head.getHeadGreenColor(),
                                          head.getHeadBlueColor() + 0.05, 1);
                        bod.setNeckColor(head.getHeadRedColor(), head.getHeadGreenColor(),
                                         head.getHeadBlueColor() + 0.05, 1);
                        head.setHeadColor(head.getHeadRedColor(), head.getHeadGreenColor(),
                                          head.getHeadBlueColor() + 0.05, 1);
                    } else {
                        arms.setHandColor(head.getHeadRedColor(), head.getHeadGreenColor(), 0, 1);
                        legs.setFootColor(head.getHeadRedColor(), head.getHeadGreenColor(), 0, 1);
                        bod.setNeckColor(head.getHeadRedColor(), head.getHeadGreenColor(), 0, 1);
                        head.setHeadColor(head.getHeadRedColor(), head.getHeadGreenColor(), 0, 1);
                    }
                } else if (colorEyes) {
                    if (head.getEyesBlueColor() < 0.96) {
                        head.setEyeColor(head.getEyesRedColor(), head.getEyesGreenColor(),
                                         head.getEyesBlueColor() + 0.05, 1);
                    } else {
                        head.setEyeColor(head.getEyesRedColor(), head.getEyesGreenColor(), 0, 1);
                    }
                } else if (colorShirt) {
                    if (bod.getBodyBlueColor() < 0.96) {
                        arms.setArmColor(bod.getBodyRedColor(), bod.getBodyGreenColor(), bod.getBodyBlueColor() + 0.05,
                                         1);
                        bod.setBodyColor(bod.getBodyRedColor(), bod.getBodyGreenColor(), bod.getBodyBlueColor() + 0.05,
                                         1);
                    } else {
                        arms.setArmColor(bod.getBodyRedColor(), bod.getBodyGreenColor(), 0, 1);
                        bod.setBodyColor(bod.getBodyRedColor(), bod.getBodyGreenColor(), 0, 1);
                    }
                } else if (colorPants) {
                    if (legs.getLegsBlueColor() < 0.96) {
                        bod.setPantsColor(legs.getLegsRedColor(), legs.getLegsGreenColor(),
                                          legs.getLegsBlueColor() + 0.05, 1);
                        legs.setLegColor(legs.getLegsRedColor(), legs.getLegsGreenColor(),
                                         legs.getLegsBlueColor() + 0.05, 1);
                    } else {
                        bod.setPantsColor(legs.getLegsRedColor(), legs.getLegsGreenColor(), 0, 1);
                        legs.setLegColor(legs.getLegsRedColor(), legs.getLegsGreenColor(), 0, 1);
                    }
                }
            }
        }
    }

    glutPostRedisplay();
}

void kbdUp(unsigned char key, int x, int y) {




    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {

    if(screen == third) {
        switch (key) {
            case GLUT_KEY_DOWN:
                // check if avatar is at border
                overlapping = user.isOverlapping(borders[3]);

                if(borders[3].getTopY() - user.getBottomY() < 5){
                    overlapping = true;
                }

                // See if it overlaps with any horizontal rectangles
                for(int i = 0; i < hozWalls.size();i++){
                    if(user.isOverlapping(hozWalls[i])){
                        overlapping = true;
                    }
                    else if(((hozWalls[i].getTopY() - user.getBottomY() < 6 && user.getBottomY() < hozWalls[i].getTopY())) && (hozWalls[i].getLeftX() <= user.getRightX() && !(hozWalls[i].getRightX() < user.getLeftX()))){
                        overlapping = true;
                    }
                }
                if(!overlapping) {
                    head.moveY(5);
                    bod.moveY(5);
                    arms.moveY(5);
                    legs.moveY(5);
                    user.moveY(5);
                }
                break;
            case GLUT_KEY_LEFT:
                overlapping = user.isOverlapping(borders[0]);

                // See if it overlaps with any horizontal rectangles
                for(int i = 0; i < vertWalls.size();i++) {
                    if (user.isOverlapping(vertWalls[i])) {
                        overlapping = true;
                    } else if (((user.getLeftX() - vertWalls[i].getRightX() < 6 &&
                                 user.getLeftX() > vertWalls[i].getRightX())) &&
                               (vertWalls[i].getTopY() <= user.getBottomY() &&
                                !(vertWalls[i].getBottomY() < user.getTopY()))) {
                        overlapping = true;
                    }

                }
                if(!overlapping) {
                    head.moveX(-5);
                    bod.moveX(-5);
                    arms.moveX(-5);
                    legs.moveX(-5);
                    user.moveX(-5);
                }
                break;
            case GLUT_KEY_RIGHT:

                overlapping = user.isOverlapping(borders[1]);

                if(borders[1].getLeftX() - user.getRightX() < 5){
                    overlapping = true;
                }

                // See if it overlaps with any horizontal rectangles
                for(int i = 0; i < vertWalls.size();i++){
                    if(user.isOverlapping(vertWalls[i])){
                        overlapping = true;
                    }

                        // Make sure a move won't make it become overlapping
                    else if(((vertWalls[i].getLeftX()-user.getRightX() < 6 && user.getRightX() < vertWalls[i].getRightX())) &&
                    (vertWalls[i].getTopY() <= user.getBottomY() && !(vertWalls[i].getBottomY() < user.getTopY()))){
                        overlapping = true;
                    }

                }
                if(!overlapping) {
                    head.moveX(5);
                    bod.moveX(5);
                    arms.moveX(5);
                    legs.moveX(5);
                    user.moveX(5);
                }
                break;
            case GLUT_KEY_UP:

                overlapping = user.isOverlapping(borders[2]);
                // See if it overlaps with any horizontal rectangles
                for(int i = 0; i < hozWalls.size();i++){
                    if(user.isOverlapping(hozWalls[i])){
                        overlapping = true;
                    }
                    else if(((user.getTopY()-hozWalls[i].getBottomY() < 6 && user.getTopY() > hozWalls[i].getBottomY()))
                    && (hozWalls[i].getLeftX() <= user.getRightX() && !(hozWalls[i].getRightX() < user.getLeftX()))){
                        overlapping = true;
                    }
                }

                if(!overlapping) {
                    head.moveY(-5);
                    bod.moveY(-5);
                    arms.moveY(-5);
                    legs.moveY(-5);
                    user.moveY(-5);
                }
                break;
        }
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    if(startButton.isOverlapping(x,y)){
        startButton.hover();
    } else{
        startButton.release();
    }
    glutPostRedisplay();

    if(secondButton.isOverlapping(x,y)){
        secondButton.hover();
    } else{
        secondButton.release();
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    switch(button){
        case GLUT_LEFT_BUTTON:
            if(screen == first) {
                if (state == GLUT_DOWN && startButton.isOverlapping(x, y)) {
                    startButton.pressDown();
                } else {
                    startButton.release();
                }
                if (state == GLUT_UP && startButton.isOverlapping(x, y)) {
                    screen = second;
                }
            }
            if(screen == second) {
                if (state == GLUT_DOWN && secondButton.isOverlapping(x, y)) {
                    secondButton.pressDown();
                } else {
                    secondButton.release();
                }
                if (state == GLUT_UP && secondButton.isOverlapping(x, y)) {
                    screen = third;
                }
            }
    }


    glutPostRedisplay();
}

void cloudTimer(int dummy) {

    for (unique_ptr<Shape> &s : bigClouds) {
        // Move all the clouds to the left
        s->moveX(-0.5);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(720);
        }
    }

    for (unique_ptr<Shape> &s : smallClouds) {
        // Move all the clouds to the left (smaller clouds move faster)
        s->moveX(-1);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(720);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(60, cloudTimer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbdUp);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, cloudTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
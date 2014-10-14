#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <iostream>


using namespace std;



static int const coefficient[11][11] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 1, 2, 16, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 2, 6, 12, 0, 0, 0, 0, 0, 0},
										 {0, 0, 1, 3, 15, 50, 0, 0, 0, 0, 0},
										 {0, 0, 1, 2, 3, 30, 75, 0, 0, 0, 0},
										 {0, 0, 0, 1, 6, 12, 36, 100, 0, 0, 0},
										 {0, 0, 0, 1, 3, 6, 19, 90, 720, 0, 0},
										 {0, 0, 0, 1, 2, 4, 8, 20, 80, 1200, 0},
										 {0, 0, 0, 1, 2, 3, 5, 10, 30, 600, 1800}};

const int SCREEN_WIDTH = 878;
const int SCREEN_HEIGHT = 640;

const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;


//ball Order Positions
int ballX = 170;
int ballY = 640;
int ballX2 = 170;
int ballY2 = 540;

//first ball line
int range = 540;

//ball TTF position
int moveX = 11;
int moveY = 13;

//winning ball animation
int color = 1;
int counter = 0;

//paytable
int hits = 0;
int balanceCount = 0;

//alien counter
int alienCount =0;

bool chunk = true;

int incDecCount = 0;
int radioFrame = 0;
int radarFrame = 0;
int logoFrame = 0;

#endif

#pragma once
#include "game.h"
#include "RGBPixMap.h"
#include<stdlib.h>

#define width_win 500
#define height_win 500
#define COLUMNS 40
#define ROWS 40
#define FPS 10

class GlutCallback {
public:
	static void init();
	static void display();
	static void reshape(int,int);
	static void timer(int);
	static void keyboard(int,int,int);
};
#pragma once
#include<GL/glew.h>
#include<GL/glut.h>
#include<ctime>

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX 60

#define font GLUT_BITMAP_TIMES_ROMAN_24

class Color
{
public:
	float R, G, B;
};

extern const int NumMenu;
extern int choosen;
extern bool isMenu;
extern bool selected[];

extern int score;

extern int gridX, gridY;
extern int snake_length;
extern bool food;
extern int foodX, foodY;
extern short sDirection;
extern short newDirection;
extern bool gameOver;

extern int posX[MAX], posY[MAX];

void initGrid(int, int);
void drawGrid();
void unit(int, int);
void drawSnake();
void drawFood();
void random(int&, int&);

void ShowMenu();
void drawString(char*, Color, float, float);
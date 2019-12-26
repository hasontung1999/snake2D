#include"game.h"

const int NumMenu = 2;
const char* labels[NumMenu] = { "Play","Exit" };
int choosen = -1;
bool isMenu = true;
bool selected[NumMenu] = { 0,1 };
Color color[2] = { {1.0,1.0,1.0},{1.0,0.0,0.0} };
POINT position[NumMenu] = { {20,15},{20,10} };

int gridX, gridY;
int snake_length = 5;
bool food = true;
int foodX, foodY;
short sDirection = RIGHT;
short newDirection = RIGHT;

int posX[MAX] = { 20,20,20,20,20 }, posY[MAX] = { 20,19,18,17,16 };

void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

void drawGrid()
{
	for (int x = 0; x < gridX; x++)
	{
		for (int y = 0; y < gridY; y++)
		{
			unit(x, y);
		}
	}
}

void unit(int x,int y)
{
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
	{
		glLineWidth(3.0);
		glColor3f(1.0, 0.0, 0.0);
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(0.25, 0.25, 0.25);
	}

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void drawFood()
{
	if (food)
		random(foodX, foodY);
	food = false;
	glColor3f(1.0, 0.0, 0.0);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void drawSnake()
{
	for (int i = snake_length - 1; i > 0;i--)
	{
		posX[i] = posX[i - 1];
		posY[i] = posY[i - 1];
	}
	if (newDirection == UP && sDirection != DOWN) {
		sDirection = UP;
		posY[0]++;
	}
	else if (newDirection == DOWN && sDirection != UP) {
		sDirection = DOWN;
		posY[0]--;
	}
	else if (newDirection == RIGHT && sDirection != LEFT) {
		sDirection = RIGHT;
		posX[0]++;
	}
	else if (newDirection == LEFT && sDirection != RIGHT) {
		sDirection = LEFT;
		posX[0]--;
	}
	for (int i = 1; i < snake_length; i++) {
		if (posX[0] == posX[i] && posY[0] == posY[i]) {
			gameOver = true;
			return;
		}
	}
	for (int i = 0; i < snake_length; i++)
	{
		if (i == 0)
			glColor3f(0.0, 1.0, 0.0);
		else
			glColor3f(0.0, 0.0, 1.0);
		glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
	}
	if (posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1) {
		gameOver = true;
		return;
	}
	if (posX[0] == foodX && posY[0] == foodY)
	{
		score++;
		snake_length++;
		if (snake_length > MAX)
			snake_length = MAX;
		food = true;
	}
}

void random(int &x, int &y)
{
	int maxX = gridX - 2;
	int maxY = gridY - 2;
	int min = 1;
	srand(time(NULL));
	x = min + rand() % (maxX - min);
	y = min + rand() % (maxY - min);
}

void drawString(const char* string, Color color, float x, float y)
{
	glRasterPos2d(x, y);
	glColor3f(color.R, color.G, color.B);
	for (int i = 0; i < strlen(string); i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

void ShowMenu()
{
	for (int i = 0; i < NumMenu; i++)
	{
		if (selected[i])
			drawString(labels[i], color[1], position[i].x, position[i].y);
		else
			drawString(labels[i], color[0], position[i].x, position[i].y);
	}
	glutSwapBuffers();
	glutPostRedisplay();
}

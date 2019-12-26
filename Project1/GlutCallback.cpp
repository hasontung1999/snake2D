#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "GlutCallback.h"

bool gameOver = false;
RGBpixmap pix;
int score = 0;
int width;
int height;

void GlutCallback::init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}
void GlutCallback::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (isMenu)
	{
		pix.readBMPFile("snake.bmp");
		glPixelZoom(width*1.0/width_win, height*1.0/height_win);
		glRasterPos2f(0.0, 20.0);
		pix.draw();
		ShowMenu();
	}
	if (choosen == 1)
	{
		drawGrid();
		drawSnake();
		drawFood();
		glutSwapBuffers();
		if (gameOver)
		{
			char _score[10];
			_itoa(score, _score, 10);
			char text[50] = "Your score : ";
			strcat(text, _score);
			MessageBox(NULL, text, "GAME OVER!!!", 0);
			exit(0);
		}
	}
	else if (choosen == 0)
		exit(0);
	
}

void GlutCallback::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	width =(GLsizei) w;
	height =(GLsizei) h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void GlutCallback::timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}

void GlutCallback::keyboard(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (isMenu)
		{
			if (selected[0] == 1)
			{
				selected[0] = 0;
				selected[NumMenu - 1] = 1;
			}
			else
				for (int i = 1; i < NumMenu; i++)
				{
					if (selected[i] == 1)
					{
						selected[i] = 0;
						selected[i - 1] = 1;
					}
				}
		}

		else if (newDirection != DOWN)
			newDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (isMenu)
		{
			if (selected[NumMenu - 1] == 1)
			{
				selected[NumMenu - 1] = 0;
				selected[0] = 1;
			}
			else
				for (int i = NumMenu - 1; i >= 0; i--)
				{
					if (selected[i] == 1)
					{
						selected[i] = 0;
						selected[i + 1] = 1;
					}
				}
		}
		else if (newDirection != UP)
			newDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (isMenu)
		{
			for (int i = 0; i < NumMenu; i++)
				if (selected[i])
					choosen = i;
			isMenu = false;
		}
		else if (newDirection != LEFT)
			newDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (newDirection != RIGHT)
			newDirection = LEFT;
		break;
	}

}
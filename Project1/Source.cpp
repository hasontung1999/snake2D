#include "GlutCallback.h"
extern int width;
extern int height;

int main(int argc, char** argv)
{
	GlutCallback *gl = new GlutCallback();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(width_win, height_win);
	glutCreateWindow("Snake");

	glutDisplayFunc(gl->display);
	glutReshapeFunc(gl->reshape);
	glutTimerFunc(0, gl->timer, 0);
	glutSpecialFunc(gl->keyboard);
	gl->init();

	glutMainLoop();
	delete gl;
	return 0;
}
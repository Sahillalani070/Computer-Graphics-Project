#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include "world.hpp"

#define ROWS 40.0
#define COLUMNS 40.0
#define FPS 10

//Adjust window of the game here
#define WINDOW_WIDTH 600
#define WINDOW_LENGTH 600

std::ofstream ofile;
std::ifstream ifile;
bool gameOver = false;

void init();
void display_callback();
void input_callback(int, int, int);
void reshape_callback(int, int);
void timer_callback(int);
World *world = NULL;

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	return 0;
}

void main_game(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_LENGTH);
	glutCreateWindow("The Snake Game");
	init();
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutSpecialFunc(input_callback);
	glutTimerFunc(100, timer_callback, 0);
	glutMainLoop();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	world = new World(COLUMNS, ROWS);
//	initGrid(COLUMNS, ROWS);
}
//
////Callbacks
void display_callback() {
	if (world->snake->isSnakeDead) {
		ofile.open("score.dat", std::ios::trunc);
		ofile << world->snake->snakeLength - INIT_SNAKE_LEN << std::endl;
		ofile.close();
		ifile.open("score.dat", std::ios::in);
		char a[4];
		ifile >> a;
		std::cout << a;
		char text[50] = "Your score : ";
		strcat(text, a);
		MessageBox(NULL, text, "Game Over", 0);
		exit(0);
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
//	draw_grid();
//	draw_food();
//	draw_snake();
	world->draw();
	glutSwapBuffers();
}
void reshape_callback(int w, int h) {
	glViewport(0, 0, (GLfloat) w, GLfloat(h));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void timer_callback(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}
void input_callback(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (world->snake->snakeDirection != GLUT_KEY_DOWN)
			world->snake->snakeDirection = GLUT_KEY_UP;
		break;
	case GLUT_KEY_DOWN:
		if (world->snake->snakeDirection != GLUT_KEY_UP)
			world->snake->snakeDirection = GLUT_KEY_DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (world->snake->snakeDirection != GLUT_KEY_LEFT)
			world->snake->snakeDirection = GLUT_KEY_RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (world->snake->snakeDirection != GLUT_KEY_RIGHT)
			world->snake->snakeDirection = GLUT_KEY_LEFT;
		break;
	}
}

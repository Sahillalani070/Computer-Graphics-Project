/*
 -------------------------------------
 File:    snake.hpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include <GL/glut.h>
#include <GL/gl.h>
#include "snakeFood.hpp"
#define SNAKE_MAX_LEN 60
#define INIT_SNAKE_LEN 3

class Snake {
public:
	int snakePosX[60], snakePosY[60];
	int snakeLength;
	int sGridX, sGridY;
	GLfloat snakeHeadColorR, snakeHeadColorG, snakeHeadColorB;
	GLfloat snakeBodyColorR, snakeBodyColorG, snakeBodyColorB;
	short snakeDirection;
	bool isSnakeDead;
	Snake(int snakePositionX, int snakePositionY, int gridX, int gridY);
	void drawSnake();
	void updateSnakeLength();
};

#endif /* SNAKE_HPP_ */

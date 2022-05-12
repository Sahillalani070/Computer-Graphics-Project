/*
 -------------------------------------
 File:    snake.cpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#include "snake.hpp"

Snake::Snake(int snakePositionX, int snakePositionY, int gridX, int gridY) {
	//Set Start position of snake

	snakeHeadColorR = 1.0;
	snakeHeadColorG = 1.0;
	snakeHeadColorB = 1.0;

	snakeBodyColorR = 0.5;
	snakeBodyColorG = 0.75;
	snakeBodyColorB = 0;

	snakeDirection = GLUT_KEY_RIGHT;
	isSnakeDead = false;

	sGridX = gridX;
	sGridY = gridY;

	snakeLength = INIT_SNAKE_LEN;
	int snakeXPosVals[3] = { 20, 20, 20 };
	int snakeYPosVals[3] = { 20, 19, 18 };
	for (int i = 0; i < 3; i++) {
		snakePosX[i] = snakeXPosVals[i];
		snakePosY[i] = snakeYPosVals[i];
	}

}

void Snake::updateSnakeLength() {
	snakeLength += 1;
}

void Snake::drawSnake() {
	//Setting snake direction

	for (int i = snakeLength - 1; i > 0; i--) {
		snakePosX[i] = snakePosX[i - 1];
		snakePosY[i] = snakePosY[i - 1];
	}

	if (snakeDirection == GLUT_KEY_UP) {
		snakePosY[0] += 1;
	} else if (snakeDirection == GLUT_KEY_RIGHT) {
		snakePosX[0] += 1;
	} else if (snakeDirection == GLUT_KEY_LEFT) {
		snakePosX[0] -= 1;
	} else if (snakeDirection == GLUT_KEY_DOWN) {
		snakePosY[0] -= 1;
	}

	for (int j = 0; j < snakeLength; j++) {
		if (j == 0)
			glColor3f(snakeHeadColorR, snakeHeadColorR, snakeHeadColorR);
		else
			glColor3f(snakeBodyColorR, snakeBodyColorR, snakeBodyColorR);

		glRectd(snakePosX[j], snakePosY[j], snakePosX[j] + 1, snakePosY[j] + 1);
	}

	//Snake hit the border, so its dead
	if (snakePosX[0] == 0 || snakePosY[0] == 0 || snakePosX[0] == sGridX - 1
			|| snakePosY[0] == sGridY - 1) {
		isSnakeDead = true;
	}
	//Snake hit body
	int k = 1;
	while (k < snakeLength && !isSnakeDead) {
		if (snakePosX[0] == snakePosX[k] && snakePosY[0] == snakePosY[k]) {
			isSnakeDead = true;
		} else {
			k += 1;
		}

	}

}

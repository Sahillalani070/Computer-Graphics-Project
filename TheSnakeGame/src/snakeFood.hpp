/*
 -------------------------------------
 File:    snakeFood.hpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#ifndef SNAKEFOOD_HPP_
#define SNAKEFOOD_HPP_
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include "snake.hpp"

class Food {
public:
	GLfloat foodColorR, foodColorG, foodColorB;
	GLfloat foodPosX, foodPosY;
	Food(int x, int y, GLfloat colorR, GLfloat colorG, GLfloat colorB);
	void drawFood();
};

#endif /* SNAKEFOOD_HPP_ */

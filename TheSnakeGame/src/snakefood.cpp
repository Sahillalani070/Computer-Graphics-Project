/*
 -------------------------------------
 File:    snakefood.cpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#include "snakefood.hpp"
#include <iostream>

Food::Food(int x, int y, GLfloat colorR, GLfloat colorG, GLfloat colorB) {
	foodColorR = colorR;
	foodColorG = colorG;
	foodColorB = colorB;

	foodPosX = x;
	foodPosY = y;

}

void Food::drawFood() {
//	std::cout << "Drawing Food..\n";
//	std::cout << "Food position x: " << foodPosX << " \n";
//	std::cout << "Food position Y: " << foodPosY << " \n";

	glLineWidth(2.0);
	glColor3f(foodColorR, foodColorG, foodColorB);

	glBegin(GL_POLYGON);
	glVertex2f(foodPosX, foodPosY);
	glVertex2f(foodPosX + 1, foodPosY);
	glVertex2f(foodPosX + 1, foodPosY + 1);
	glVertex2f(foodPosX, foodPosY + 1);
	glEnd();

	std::cout << "Food Drawn.\n";
}


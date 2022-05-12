/*
 -------------------------------------
 File:    grid.cpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#include "grid.hpp"

Grid::Grid(int x, int y) {
	gridX = x;
	gridY = y;

}

void Grid::drawGrid() {
	for (int posX = 0; posX < gridX; posX++) {
		for (int posY = 0; posY < gridY; posY++) {
			unit_square(posX, posY);
		}
	}
}

void Grid::unit_square(int x, int y) {
	//To set Drawing mode
	GLenum Mode;

	//For Grid Border
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
		//Set Grid Line width
		lineWidth = 3.0;

		//Set Grid Colour
		lineColorR = 1.0;
		lineColorG = 0.0;
		lineColorB = 0.0;
		Mode = GL_POLYGON;
	}
	//For everything else
	else {
		//Set Grid Line width
		lineWidth = 1.0;

		//Set Grid Colour
		lineColorR = 1.0;
		lineColorG = 1.0;
		lineColorB = 1.0;
		Mode = GL_LINE_LOOP;
	}

	glLineWidth(lineWidth);
	glColor3f(lineColorR, lineColorG, lineColorB);

	glBegin(Mode);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

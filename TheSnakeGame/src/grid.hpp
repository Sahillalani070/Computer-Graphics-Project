/*
 -------------------------------------
 File:    grid.hpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#ifndef GRID_HPP_
#define GRID_HPP_
#include <GL/glut.h>
#include <GL/gl.h>

class Grid {
public:
	int gridX, gridY; //Coords

	//Set Line width
	GLfloat lineWidth;

	//RGB value for line
	GLfloat lineColorR, lineColorG, lineColorB;

	Grid(int x, int y); //Constructor
	void drawGrid();
	void unit_square(int x, int y);

};

#endif /* GRID_HPP_ */

/*
 -------------------------------------
 File:    world.hpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_
#include <GL/glut.h>
#include <GL/gl.h>

#include "grid.hpp"
#include "snake.hpp"
#include "snakeFood.hpp"
#include <stdlib.h>

class World {
public:
	Grid *grid;
	Snake *snake;
	bool isFirstTime;
	int maxX, min, maxY;
	World(int x, int y);
	bool isFoodEatenBySnake();
	~World();
	void draw();
};

#endif /* WORLD_HPP_ */

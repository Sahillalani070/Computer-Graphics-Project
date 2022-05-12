/*
 -------------------------------------
 File:    world.cpp
 Project: TheSnakeGame
 file description
 -------------------------------------
 Author:  Sharan Rohit Raj Natarajan
 ID:      191962120
 Email:   nata2120@mylaurier.ca
 Version  2021-12-04
 -------------------------------------
 */
#include "world.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Food *snakeFood = NULL;

World::World(int x, int y) {
	//Initialize Grid
	grid = new Grid(x, y);
	snake = new Snake(20, 20, x, y);
	isFirstTime = true;
	maxX = x - 2;
	min = 1;
	maxY = y - 2;
}

void World::draw() {
	grid->drawGrid();
	snake->drawSnake();

	srand(time(NULL));

	if (isFoodEatenBySnake()) {
		std::cout << "Food Created\n";
		snakeFood = new Food(rand() % (maxX - min) + min,
				rand() % (maxY - min) + min, 0.0, 1.0, 0.0);
	}
	snakeFood->drawFood();

}

bool World::isFoodEatenBySnake() {

	if (isFirstTime) {
		isFirstTime = false;
		return true;
	}

	else if (snake->snakePosX[0] == snakeFood->foodPosX
			&& snake->snakePosY[0] == snakeFood->foodPosY) {
		snake->updateSnakeLength();
		return true;
	}

	else {
		return false;
	}
}

World::~World() {

}

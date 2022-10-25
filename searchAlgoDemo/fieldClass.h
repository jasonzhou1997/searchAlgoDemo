#pragma once
#ifndef _FIELDCLASS_H
#define _FIELDCLASS_H

#include "cellClass.h"
#include "globalConstant.h"
#include <vector>
#include <sfml/Graphics.hpp>
#include <iostream> // for debugging output
#include <fstream>
#include <string>

class fieldClass
{
public:

	/*
	Constructor for filedClass, 
	takes input Row and column from user input
	and constructs the cell vector
	*/
	fieldClass(const int ROWS, const int COLUMNS);

	/*
	Destructor for fieldClass,
	delete dynamically allocated cellClass in the cells vector
	*/
	~fieldClass();
	/*
	Calls reset function for each cells element to set each cell state as free
	*/
	void restartField();
	/*
	Draws the window based on state of each cell
	*/
	void draw(sf::RenderWindow& window);
	/*
	Mark the cell as an obstacle
	*/
	void markCellObstacle(int row, int col);
	/*
	Mark the cell as the start position
	*/
	void markCellStart(int row, int col);
	/*
	Mark the cell as the goal position
	*/
	void markCellGoal(int row, int col);
	/*
	Save the current cells vector into a text file
	*/
	void saveMap(std::string fileName);
private:
	std::vector<std::vector<cellClass*>> cells;
	bool doneBuildingField;

};

#endif // !_FIELDCLASS_H



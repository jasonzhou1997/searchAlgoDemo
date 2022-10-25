#pragma once
#ifndef _cellClass_H
#define _cellClass_H

#include "globalConstant.h"
class cellClass
{
private:
	bool isFree;
	bool isObstacle;
	bool isStart;
	bool isGoal;

	int cellRowNum;
	int cellColNum;

	char mouseState;
public:
	cellClass(int row, int col);
	// getter function to check if cell is an obstacle
	bool getIsObstacle() const;
	// getter function to check if cell is start position
	bool getIsStart() const;
	// getter function to check if cell is goal position
	bool getIsGoal() const;
	// getter function to check if cell is free
	bool getIsFree() const;

	// setter function to set the cell into obstacle
	void setToObstacle();
	// setter function to set the cell into start position
	void setToStart();
	// setter function to set the cell into goal position
	void setToGoal();
	// setter function to set the cell into free cell
	void reset();

	/*
	Gets the state of the cell:
	0: Free
	1: Obstacle
	2: Start
	3: Goal
	*/
	int getCellState() const;
};
#endif // !_cellClass_H




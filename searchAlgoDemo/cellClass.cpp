#include "cellClass.h"

cellClass::cellClass(int row, int col)
{
	cellRowNum = row;
	cellColNum = col;

	isFree = true;
	isObstacle = false;
	isStart = false;
	isGoal = false;
}


void cellClass::setToObstacle()
{
	isFree = false;
	isObstacle = true;
	isStart = false;
	isGoal = false;
}
void cellClass::setToStart()
{
	isFree = false;
	isObstacle = false;
	isStart = true;
	isGoal = false;
}
void cellClass::setToGoal()
{
	isFree = false;
	isObstacle = false;
	isStart = false;
	isGoal = true;
}
bool cellClass::getIsObstacle() const
{
	return isObstacle;
}
bool cellClass::getIsStart() const
{
	return isStart;
}
bool cellClass::getIsGoal() const
{
	return isGoal;
}
bool cellClass::getIsFree() const
{
	return isFree;
}

void cellClass::reset()
{
	isFree = true;
	isObstacle = false;
	isStart = false;
	isGoal = false;
}

int cellClass::getCellState() const
{
	if (getIsFree())
	{
		return FREE_CELL_STATE;
	}
	else if (getIsObstacle())
	{
		return OBSTACLE_CELL_STATE;
	}
	else if (getIsStart())
	{
		return START_CELL_STATE;
	}
	return GOAL_CELL_STATE;
}

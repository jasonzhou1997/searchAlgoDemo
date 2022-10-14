#pragma once
#ifndef _cellClass_H
#define _cellClass_H
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
	bool getIsObstacle() const;
	bool getIsStart() const;
	bool getIsGoal() const;
	bool getIsFree() const;

	void setToObstacle();
	void setToStart();
	void setToGoal();

	void reset();

	char getMouseState() const;
};
#endif // !_cellClass_H




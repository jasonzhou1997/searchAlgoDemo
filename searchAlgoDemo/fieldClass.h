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
	fieldClass(const int ROWS, const int COLUMNS);

	~fieldClass();
	void restartField();
	void draw(sf::RenderWindow& window);
	void markCellObstacle(int row, int col);
	void markCellStart(int row, int col);
	void markCellGoal(int row, int col);
	void saveMap(std::string fileName);
private:
	std::vector<std::vector<cellClass*>> cells;
	bool doneBuildingField;

};

#endif // !_FIELDCLASS_H



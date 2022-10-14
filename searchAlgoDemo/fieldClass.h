#pragma once
#ifndef _FIELDCLASS_H
#define _FIELDCLASS_H

#include "cellClass.h"
#include "globalConstant.h"
#include <vector>
#include <sfml/Graphics.hpp>
class fieldClass
{
public:
	fieldClass(const int ROWS, const int COLUMNS);

	~fieldClass();
	void restartField();
	void draw(sf::RenderWindow& window);
private:
	std::vector<std::vector<cellClass*>> cells;
	bool doneBuildingField;

};

#endif // !_FIELDCLASS_H



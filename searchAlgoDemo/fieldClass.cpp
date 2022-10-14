#include "fieldClass.h"


fieldClass::fieldClass(const int ROWS, const int COLUMNS)
{
	doneBuildingField = false;
	cells.resize(ROWS, std::vector<cellClass*>(COLUMNS));
	for (unsigned int row = 0; row < ROWS; row++)
	{
		for (unsigned int col = 0; col < COLUMNS; col++)
		{
			cells[row][col] = new cellClass(row, col);
		}
	}
}
fieldClass::~fieldClass()
{
	for (unsigned int row = 0; row < cells.size(); row++)
	{
		for (unsigned int col = 0; col < cells[0].size(); col++)
		{
			delete(cells[row][col]);
		}
	}
}
void fieldClass::restartField()
{
	doneBuildingField = false;
	for (unsigned int row = 0; row < cells.size(); row++)
	{
		for (unsigned int col = 0; col < cells[0].size(); col++)
		{
			cells[row][col]->reset();
		}
	}
}

void fieldClass::draw(sf::RenderWindow& window)
{
	sf::RectangleShape cellShape(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
	cellShape.setFillColor(sf::Color(146, 182, 255));

	for (unsigned int row = 0; row < cells.size(); row++)
	{
		for (unsigned int col = 0; col < cells[0].size(); col++)
		{
			cellShape.setPosition(CELL_SIZE * row, CELL_SIZE * col);
			window.draw(cellShape);
		}
	}
}
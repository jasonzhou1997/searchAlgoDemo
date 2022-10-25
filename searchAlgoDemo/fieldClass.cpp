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
			// set the cell into free state
			cells[row][col]->reset();
		}
	}
}
void fieldClass::markCellObstacle(int row, int col)
{
	cells[row][col]->setToObstacle();
}
void fieldClass::markCellStart(int row, int col)
{
	cells[row][col]->setToStart();
}
void fieldClass::markCellGoal(int row, int col)
{
	cells[row][col]->setToGoal();
}

void fieldClass::saveMap(std::string fileName)
{
	// create a text file
	std::ofstream outFile;
	
	outFile.open(fileName);
	// Input the row and column number of the map size into first row of the text file
	outFile << cells.size() << cells[0].size() << "\n";
	for (unsigned int row = 0; row < cells.size(); row++)
	{
		for (unsigned int col = 0; col < cells[0].size(); col++)
		{
			outFile << cells[row][col]->getCellState();
		}
		outFile << "\n";
	}
	outFile.close();
}

void fieldClass::draw(sf::RenderWindow& window)
{
	sf::RectangleShape cellShape(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

	sf::Sprite iconSprite;
	sf::Texture iconTexture;
	iconTexture.loadFromFile("obsStartEndIcon16.png");
	iconSprite.setTexture(iconTexture);

	for (unsigned int row = 0; row < cells.size(); row++)
	{
		for (unsigned int col = 0; col < cells[0].size(); col++)
		{
			cellShape.setPosition(CELL_SIZE * row, CELL_SIZE * col);
			// assume cell is free so no texture is needed
			int textureColumn = -1;
			// if current cell is free, do nothing, if not check it's state (obstacle/start/goal)
			if (!cells[row][col]->getIsFree())
			{
				if (cells[row][col]->getIsObstacle())
				{
					textureColumn = 0;
				}
				else if (cells[row][col]->getIsStart())
				{
					textureColumn = 1;
				}
				else if (cells[row][col]->getIsGoal())
				{
					textureColumn = 2;
				}
				cellShape.setFillColor(sf::Color(146, 182, 255));
				window.draw(cellShape);
				iconSprite.setPosition(CELL_SIZE * row, CELL_SIZE * col);
				std::cout << "Current textTure Column: " << textureColumn << "\n";
				iconSprite.setTextureRect(sf::IntRect(CELL_SIZE * textureColumn, 0, CELL_SIZE, CELL_SIZE));
				window.draw(iconSprite);
			}
			else
			{
				cellShape.setFillColor(sf::Color(146, 182, 255));
				window.draw(cellShape);
			}

		}
	}
}
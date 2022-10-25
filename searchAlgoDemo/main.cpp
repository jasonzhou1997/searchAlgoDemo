#include <sfml/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include "globalConstant.h"
#include "menuOption.h"
#include "astarSearch.h"
#include "fieldClass.h"
#include <vector>

int main(int argc, char* argv[])
{
	//if (argc != TOTAL_INPUT_ARG_COUNT)
	//{
	//	std::cout << "Usage: "
	//		<< argv[EXE_INPUT_ARG_POSITION]
	//		<< " <algorithm>"
	//		<< "\n";
	//}
	std::vector<std::vector<int>> defaultMap{
		{0, 0, 0, 0, 0, 0, 0, 2},
		{0, 1, 1, 1, 0, 0, 1, 0},
		{0, 1, 1, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 1, 0, 1, 0},
		{0, 0, 1, 0, 1, 0, 1, 0},
		{1, 0, 1, 0, 1, 0, 0, 0},
		{3, 0, 0, 0, 1, 0, 0, 0}
	};
	//std::cout << defaultMap.size() << defaultMap[0].size() << "\n";
	int userOption;
	do
	{
		userOption = menuOption();

		if (userOption == EXIT_PROGRAM_OPTION)
		{
			std::cout << "Thanks for using this program" << "\n";
			return 0;
		}
		if (userOption == ASTAR_OPTION)
		{
			std::cout << "Astar Algorithm runs here: " << "\n";

			astarSearch aStar(defaultMap);
			aStar.findPath();
			aStar.printPath();
		}
		if (userOption == GREEDY_OPTION)
		{

			std::cout << "Greedy Algorithm runs here" << "\n";
		}
		if (userOption == DIJSTRA_OPTION)
		{
			std::cout << "Dijstra Algorithm runs here" << "\n";
		}
		if (userOption == MAKE_MAP_OPTION)
		{
			std::cout << "A new map will be made here" << "\n";
			std::cout << "Enter the width and height of the map: " << "\n";
			const int ROWS = []()-> int {
				int t;
				std::cin >> t;
				return t;
			}();
			const int COLUMNS = []()-> int {
				int t;
				std::cin >> t;
				return t;
			}();

			sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_RESIZE, SCREEN_RESIZE * (FONT_HEIGHT + CELL_SIZE * COLUMNS)), "Minesweeper", sf::Style::Close);
			//Here we're resizing the window
			window.setView(sf::View(sf::FloatRect(0.0, 0.0, CELL_SIZE * COLUMNS, FONT_HEIGHT + CELL_SIZE * ROWS)));

			// have the app running at the same frequency as the monitor's refresh rate
			window.setVerticalSyncEnabled(true);
			fieldClass myField(ROWS, COLUMNS);

			while (window.isOpen())
			{
				sf::Event event;
				int n = static_cast<int>(floor(sf::Mouse::getPosition(window).x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE)));
				int m = static_cast<int>(floor(sf::Mouse::getPosition(window).y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE)));

				int mouseXPos = std::max(0, std::min(n, COLUMNS - 1));
				int mouseYPos = std::max(0, std::min(m, ROWS - 1));

				// pollEvent pops the event from the window event queue
				// without the event loop, window will become unresponsive
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
						case sf::Event::Closed:
						{
							window.close();
							break;
						}
						case sf::Event::KeyReleased:
						{
							switch (event.key.code)
							{
							case sf::Keyboard::R:
							{
								myField.restartField();
							}
							case sf::Keyboard::A:
							{
								myField.draw(window);
								window.display();
							}
							case sf::Keyboard::S:
							{
								std::string fileName;
								std::cout << "Please enter the map Name :" << "\n";
								std::cin >> fileName;
								myField.saveMap(fileName + ".txt");
								window.close();
								break;
							}
							break;
							}
						}
						// mouseLeftClick allows converting the clicked cell into obstacle
						case sf::Event::MouseButtonPressed:
						{
							if (event.mouseButton.button == sf::Mouse::Right)
							{
								std::cout << "the right button was pressed" << std::endl;
								std::cout << "mouse x: " << event.mouseButton.x << std::endl;
								std::cout << "mouse y: " << event.mouseButton.y << std::endl;
							}
							else if (event.mouseButton.button == sf::Mouse::Left)
							{
								myField.markCellObstacle(mouseXPos, mouseYPos);
							}
							break;
						}
					}
				}
				window.clear();
				myField.draw(window);
				window.display();
			}

		}
	} while (userOption != EXIT_PROGRAM_OPTION);
	std::cout << "Thanks for using this program" << "\n";
	return 0;
}


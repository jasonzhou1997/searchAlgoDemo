#include <sfml/Graphics.hpp>
#include <iostream>
#include "globalConstant.h"
#include "menuOption.h"
#include "astarSearch.h"
#include <vector>

int main(int argc, char *argv[])
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
	std::cout << defaultMap.size() << defaultMap[0].size() << "\n";
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
			std::cout << "Astar Algorithm runs here" << "\n";
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
		}
	} while (userOption != EXIT_PROGRAM_OPTION);
	std::cout << "Thanks for using this program" << "\n";
	return 0;
}


#include <iostream>
#include "globalConstant.h"
#include "menuOption.h"

int menuOption()
{
	std::cout << GREEDY_OPTION << ". Apply Greedy Search Algorithm" << "\n";
	std::cout << DIJSTRA_OPTION << ". Apply Dijstra's Search Algorithm" << "\n";
	std::cout << ASTAR_OPTION << ". Apply Astar Search Algorithm" << "\n";
	std::cout << MAKE_MAP_OPTION << ". Apply map making" << "\n";
    std::cout << EXIT_PROGRAM_OPTION << ". Exit the program" << "\n";

	std::cout << "Enter the choice: ";
	int userOption;
	bool validInputFound = false;
	while (!validInputFound)
	{
		std::cin >> userOption;
        // check if number entered is in correct state or
        // is in between the last option number and first option number
        if (std::cin.fail() ||
            (userOption > LAST_OPTION_NUM || userOption < FIRST_OPTION_NUM))
        {
            std::cin.clear();
            std::cin.ignore(IGNORE_NUM_CHARACTERS, '\n');
            std::cout << "The Input should be an integer between "
                << FIRST_OPTION_NUM
                << " and "
                << LAST_OPTION_NUM
                << "\n";
            std::cout << "Enter your choice: ";
        }
        else
        {
            validInputFound = true;
        }
	}
    return userOption;

}
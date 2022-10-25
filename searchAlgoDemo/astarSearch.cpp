#include "astarSearch.h"
astarSearch::astarSearch(std::vector<std::vector<int>>myMap)
{
	map = myMap;
	std::vector<std::pair<int, int>> startEndVec = findStartAndEnd(map);
	start = new Node(startEndVec[0].first, startEndVec[0].second);
	goal = new Node(startEndVec[1].first, startEndVec[1].second);
	mapWidth = myMap.size();
	mapHeight = myMap[0].size();
	objPQ.push(start);
	pathFound = false;
}

astarSearch::~astarSearch()
{
}
void astarSearch::printPath()
{
	std::vector<std::vector<int>> pathMap = map;
	for (auto elements : pathCells)
	{
		pathMap[elements.first][elements.second] = 9;
	}
	for (int row = 0; row < pathMap.size(); row++)
	{
		for (int col = 0; col < pathMap[0].size(); col++)
		{
			std::cout << pathMap[row][col] << " ";
		}
		std::cout << "\n";
	}
}
std::vector<std::pair<int, int>> astarSearch::findStartAndEnd(std::vector<std::vector<int>>myMap)
{
	std::vector<std::pair<int, int>> startEndVec;
	std::pair<int, int> start;
	std::pair<int, int> end;
	for (int row = 0; row < myMap.size(); row++)
	{
		for (int col = 0; col < myMap[0].size(); col++)
		{
			// goal: 2 in map
			if (myMap[row][col] == 2)
			{
				end.first = row;
				end.second = col;
			}
			// start: 3 in map
			if (myMap[row][col] == 3)
			{
				start.first = row;
				start.second = col;
			}
		}
	}
	startEndVec.push_back(start);
	startEndVec.push_back(end);
	return startEndVec;

}
int astarSearch::calcHCostManhatten(Node* node)
{
	int x = abs(goal->xCoord - node->xCoord);
	int y = abs(goal->yCoord - node->yCoord);
	return 10 * (x + y);
}

int astarSearch::calcGCostGrid(Node* parent, Node* end)
{
	int x = abs(parent->xCoord - end->xCoord);
	int y = abs(parent->yCoord - end->yCoord);

	if (x == 1 && y == 1)
	{
		return parent->gCost + 14;
	}
	return parent->gCost + 10;
}

void astarSearch::expandNodeAstar(Node* currNode)
{
	std::vector<int> possibleMoveX = { 1, -1, 0, 0, 1, 1, -1, -1 };
	std::vector<int> possibleMoveY = { 0, 0, 1, -1, 1, -1, 1, -1 };

	for (int i = 0; i < 8; i++)
	{
		Node* neighbour = new Node(currNode->xCoord + possibleMoveX[i], currNode->yCoord + possibleMoveY[i]);
		if (searchedList.isMember(currNode->xCoord + possibleMoveX[i], currNode->yCoord + possibleMoveY[i]))
		{
			neighbour = searchedList.get(currNode->xCoord + possibleMoveX[i], currNode->yCoord + possibleMoveY[i]);
		}

		//std::cout << "isInClosedList: " << isInClosedList(neighbour) << " isInMap: " << isInMap(neighbour) << " isObstacle:" << isObstacle(neighbour) <<"\n";
		if (!isInClosedList(neighbour) && isInMap(neighbour) && !isObstacle(neighbour))
		{
			//std::cout <<"currX: " << neighbour->xCoord <<" currY: " << neighbour->yCoord << " GCost: " << neighbour->gCost << " HCost: " << neighbour->hCost << "\n";
			if (!isInSearchedList(neighbour))
			{
				neighbour->gCost = calcGCostGrid(currNode, neighbour);
				neighbour->hCost = calcHCostManhatten(neighbour);
				neighbour->parent = currNode;

				objPQ.push(neighbour);
				searchedList.put(neighbour);
			}
			else if (neighbour->gCost > calcGCostGrid(currNode, neighbour))
			{
				neighbour->gCost = calcGCostGrid(currNode, neighbour);
				neighbour->parent = currNode;
				objPQ.push(neighbour);
			}
		}
	}

}

bool astarSearch::isObstacle(Node* node)
{
	return (map[node->xCoord][node->yCoord] == 1);
}

bool astarSearch::isInMap(Node* node)
{
	return (node->xCoord >= 0 && node->xCoord < mapWidth) && (node->yCoord >= 0 && node->yCoord < mapHeight);
}

bool astarSearch::isInClosedList(Node* node)
{
	return closedList.isMember(node->xCoord, node->yCoord);
}

bool astarSearch::isInSearchedList(Node* node)
{
	return searchedList.isMember(node->xCoord, node->yCoord);
}

void astarSearch::extractPath(Node* node)
{
	Node* currNode = node;
	std::cout << "A star Path Found: " << "\n";
	while (currNode != start)
	{
		path.put(currNode);
		pathCells.push_back({ currNode->xCoord, currNode->yCoord });
		std::cout << "X coordinate: " << currNode->xCoord 
			<< " Y coordinate: " << currNode->yCoord 
			<< " H Cost: " << currNode->hCost 
			<< " G Cost: " << currNode->gCost 
			<< "\n";
		currNode = currNode->parent;
	}
	std::reverse(pathCells.begin(), pathCells.end());
}

void astarSearch::findPath()
{
	std::cout << "goalX: " << goal->xCoord << " goalY: " << goal->yCoord << "\n";
	Node* currNode = objPQ.pop();
	while (*currNode != *goal)
	{
		closedList.put(currNode);
		expandNodeAstar(currNode);
		currNode = objPQ.pop();
		if (*currNode == *goal)
		{
			pathFound = true;
		}
	}
	extractPath(currNode);

}
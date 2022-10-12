#pragma once
#ifndef _ASTARSEARCH_H
#define _ASTARSEARCH_H

#include "nodeList.h"
#include "Node.h"
#include "priorityQueueClass.h"
#include <vector>
#include <iostream>
class astarSearch
{
public:
	astarSearch(std::vector<std::vector<int>>myMap);
	~astarSearch();
	void findPath();
	void printPath();


private:
	std::vector<std::vector<int>>map;
	Node* start;
	Node* goal;
	int mapWidth;
	int mapHeight;
	priorityQueueClass objPQ;
	nodeList closedList;
	nodeList searchedList;
	nodeList path;
	std::vector<std::pair<int, int>> pathCells;
	bool pathFound;

	std::vector<std::pair<int, int>> findStartAndEnd(std::vector<std::vector<int>>myMap);
	int calcHCostManhatten(Node* node);
	int calcGCostGrid(Node* parent, Node* end);
	void expandNodeAstar(Node* currNode);
	void extractPath(Node* currNode);
	bool isInClosedList(Node* node);
	bool isInMap(Node* node);
	bool isObstacle(Node* node);
	bool isInSearchedList(Node* node);
};
#endif // !_ASTARSEARCH_H




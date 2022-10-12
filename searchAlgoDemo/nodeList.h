#pragma once
#ifndef _NODELIST_H
#define _NODELIST_H
#include "Node.h"
#include <vector>
class nodeList
{
private:
	std::vector<Node*> nodeListVec;
public:
	nodeList();
	~nodeList();
	void put(Node* node);
	Node* get(int xCoord, int yCoord);
	bool isMember(int xCoord, int yCoord);
};
#endif // !_NODELIST_H




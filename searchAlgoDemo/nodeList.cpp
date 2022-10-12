#include "nodeList.h"

nodeList::nodeList(){}
nodeList::~nodeList(){}

void nodeList::put(Node* node)
{
	nodeListVec.push_back(node);
}

Node* nodeList::get(int xCoord, int yCoord)
{
	for (Node* node : nodeListVec)
	{
		if (node->xCoord == xCoord && node->yCoord == yCoord)
		{
			return node;
		}
	}
	return nullptr;
}

bool nodeList::isMember(int xCoord, int yCoord)
{
	for (Node* node : nodeListVec)
	{
		if (node->xCoord == xCoord && node->yCoord == yCoord)
		{
			return true;
		}
	}
	return false;
}
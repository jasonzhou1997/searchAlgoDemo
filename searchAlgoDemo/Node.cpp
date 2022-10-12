#include "Node.h"

Node::Node(int xCoord, int yCoord)
{
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->gCost = 0.0;
	this->hCost = 0.0;
	this->parent = nullptr;
}
Node::~Node(){}

float Node::calcFCost()
{
	return gCost + hCost;
}


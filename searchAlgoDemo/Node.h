#pragma once
#ifndef _NODE_H
#define _NODE_H

class Node
{
public:
	Node(int xCoord, int yCoord);
	~Node();
	int xCoord;
	int yCoord;
	Node* parent;
	float gCost;
	float hCost;
	float calcFCost();
	bool operator==(const Node& rhs) const
	{
		return (xCoord == rhs.xCoord && yCoord == rhs.yCoord);
	}
	bool operator!=(const Node& rhs) const
	{
		return !operator==(rhs);
	}
};
#endif // !_NODE_H




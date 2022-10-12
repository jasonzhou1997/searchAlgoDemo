#pragma once
#ifndef _PRIORITYQUEUECLASS_H
#define _PRIORITYQUEUECLASS_H
#include<queue>
#include<vector>
#include "Node.h"
struct compareNode
{
	bool operator()(Node* lhs, Node* rhs)
	{
		// compare f cost first, if f cost are equal, compare by h cost
		if (lhs->calcFCost() == rhs->calcFCost())
		{
			return lhs->hCost > rhs->hCost;
		}
		return lhs->calcFCost() > rhs->calcFCost();
	}
};
class priorityQueueClass
{
private:
	std::priority_queue<Node*, std::vector<Node*>, compareNode> pq;
	std::vector<Node*> openList;
public:
	bool empty();
	Node* getMember(Node* node);
	void push(Node* node);
	Node* pop();

};
#endif // !_PRIORITYQUEUEClASS_H




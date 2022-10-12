#include "priorityQueueClass.h"

bool priorityQueueClass::empty()
{
	return pq.empty();
}

Node* priorityQueueClass::getMember(Node* node)
{
	for (Node* openListNode : openList)
	{
		if (node == openListNode)
		{
			return openListNode;
		}
	}
	return nullptr;
}
void priorityQueueClass::push(Node* node)
{
	pq.push(node);
	openList.push_back(node);
}

Node* priorityQueueClass::pop()
{
	Node* toPop = pq.top();
	pq.pop();
	int idxToPop = 0;
	for (int i = 0; i < openList.size(); i++)
	{
		if (openList[i] == toPop)
		{
			idxToPop = i;
			break;
		}
	}
	openList.erase(openList.begin() + idxToPop);
	return toPop;
}


#ifndef NODE_H
#define NODE_H

class Node
{
private:
	Node* parent; //A pointer to the node's parent. Null if root node
	int value; //Data held in the node, in this case an int

	Node* left; //Left child. Null if leaf
	Node* right; //Right child. Null if leaf

	bool isLeftChild; //True if the boolean is the left child of its parent node

public:
	Node();
	~Node();

	int getLeftSibling();
	int getRightSibling();
	int getParentValue();
	int getValue();

	void createChildren();
};

#endif

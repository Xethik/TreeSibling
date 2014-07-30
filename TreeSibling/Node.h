#ifndef NODE_H
#define NODE_H

class Node
{
private:
	Node* parent; //A pointer to the node's parent. Null if root node
	int value; //Data held in the node, in this case an int

	Node* left; //Left child. Null if leaf
	Node* right; //Right child. Null if leaf

	

public:
	Node(int, Node*, bool);
	~Node();

	bool isLeftChild; //True if the boolean is the left child of its parent node

	int getLeftSibling(); //Get parent's left child's value
	int getRightSibling(); //Get parent's right child's value

	Node* getLeftChild(); //Get left child
	Node* getRightChild(); //Get right child

	int getParentValue(); //Get parent's value
	int getValue(); //Get node's value

	void createChildren(); //Add left and right child
};

#endif

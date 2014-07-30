#include "Node.h"


Node::Node(int val, Node* par, bool isLeft) : value(val), parent(par), isLeftChild(isLeft)
{

}


Node::~Node()
{
	//delete left and right
}

int Node::getLeftSibling(){
	if (!isLeftChild && parent != nullptr) {
		return parent->getLeftChild()->getValue();
	}
	else {
		return 0;
	}
}

int Node::getRightSibling(){
	if (isLeftChild && parent != nullptr) {
		return parent->getRightChild()->getValue();
	}
	else {
		return 0;
	}
}

Node* Node::getLeftChild() {
	return left;
}

Node* Node::getRightChild(){
	return right;
}

int Node::getParentValue(){
	if (parent != nullptr) {
		return parent->getValue();
	}
	return 0;
}

int Node::getValue(){
	return value;
}

void Node::createChildren(){
	left = new Node(value + getLeftSibling(), this, true);
	right = new Node(value + getRightSibling(), this, false);
}
#include "Node.h"


Node::Node(int val, Node* par, bool isLeft) : value(val), parent(par), isLeftChild(isLeft)
{

}


Node::~Node()
{
	//delete left and right
}

int Node::getLeftSibling(){
	if (isLeftChild) {
		return 0;
	}
	else {
		return parent->getLeftChild();
	}
}

int Node::getRightSibling(){
	if (isLeftChild) {
		return parent->getRightChild();
	}
	else {
		return 0;
	}
}

int Node::getLeftChild() {
	if (left != nullptr){
		return left->getValue();
	}
	return 0;
}

int Node::getRightChild(){
	if (right != nullptr){
		return right->getValue();
	}
	return 0;
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

void Node::createChildren(int, int){
	left = new Node(value + getLeftSibling(), this, true);
	right = new Node(value + getRightSibling(), this, true);
}
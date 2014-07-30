//Michael Hogan
//Creates a tree with depth n, where all left children have values equal to their parent + their parent's left sibling
//	and all right children have values equal to their parent + their parent's right sibling.

#include "Node.h"

void createDepth(Node* curNode, int curDepth, int maxDepth) {
	if (curDepth < maxDepth) {
		curNode->createChildren();
		createDepth(curNode->getLeftChild(), curDepth + 1, maxDepth);
		createDepth(curNode->getRightChild(), curDepth + 1, maxDepth);
	}
}

int main() {
	int depth = 1;
	Node* root = new Node(1, nullptr, false);

	createDepth(root, 1, 3);

	return 0;
}
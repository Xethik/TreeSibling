//Michael Hogan
//Creates a tree with depth n, where all left children have values equal to their parent + their parent's left sibling
//	and all right children have values equal to their parent + their parent's right sibling.

#include "Node.h"
#include <cmath>

void createDepth(Node* curNode, int curDepth, int maxDepth) {
	if (curDepth < maxDepth) {
		curNode->createChildren();
		createDepth(curNode->getLeftChild(), curDepth + 1, maxDepth);
		createDepth(curNode->getRightChild(), curDepth + 1, maxDepth);
	}
}

int main() {
	int depth = 2;
	int** tree = new int*[depth];
	for (int i = 0; i < depth; i++) {
		tree[i] = new int[(int)pow(2, i - 1)];
	}
	return 0;
}
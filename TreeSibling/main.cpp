//Michael Hogan
//Creates a tree with depth n, where all left children have values equal to their parent + their parent's left sibling
//	and all right children have values equal to their parent + their parent's right sibling.

#include <cmath>
#include <iostream>

int main() {
	int depth;
	std::cout << "Enter a tree depth ( > 0): ";
	while (!(std::cin >> depth)) {
		std::cout << "Invalid input, enter an integer greater than zero." << std::endl << "Enter a tree depth ( > 0): ";
		std::cin.clear();
		std::cin.ignore('\n');
	}
	int** tree = new int*[depth];

	tree[0] = new int[1];
	tree[0][0] = 1;

	for (int i = 1; i < depth; i++) {
		int rowSize = (int)pow(2, i);
		tree[i] = new int[rowSize];

		for (int j = 0; j < rowSize; j++) {
			int siblingVal = 0;
			if (j % 2 == 0) { //If even, check left sibling. If odd, check right
				if (j > 1) { //Don't check left if on edge of tree
					siblingVal = tree[i - 1][j / 2 - 1];
				}
			}
			else {
				if (j < rowSize - 1) { //Don't check right if on edge of tree
					siblingVal = tree[i - 1][j / 2 + 1];
				}
			}
			tree[i][j] = siblingVal + tree[i-1][j/2]; //Sibling value + parent value
		}
	}

	for (int i = 0; i < depth; i++) {
		int rowSize = (int)pow(2, i);
		for (int j = 0; j < rowSize; j++) {
			std::cout << tree[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
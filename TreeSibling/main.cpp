//Michael Hogan
//Creates a tree with depth n, where all left children have values equal to their parent + their parent's left sibling
//	and all right children have values equal to their parent + their parent's right sibling.

#include <cmath>
#include <iostream>
#include <iomanip>
#include <deque>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Convert an integer value to string
string intToString(int val) {
	ostringstream ss;
	ss << val;
	return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<int>& nodesQueue, ostream& out) {
	deque<int>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel / 2; i++) {
		out << ((i == 0) ? setw(startLen - 1) : setw(nodeSpaceLen - 2)) << "" << "/";
		out << setw(2 * branchLen + 2) << "" << "\\";
	}
	out << endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<int>& nodesQueue, ostream& out) {
	deque<int>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel; i++, iter++) {
		out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter) ? setfill('_') : setfill(' '));
		out << setw(branchLen + 2) << ((*iter) ? intToString(*iter) : "");
		out << ((*iter) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
	}
	out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<int>& nodesQueue, ostream& out) {
	deque<int>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel; i++, iter++) {
		out << ((i == 0) ? setw(indentSpace + 2) : setw(2 * level + 2)) << ((*iter) ? intToString(*iter) : "");
	}
	out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(int** tree, int level, int indentSpace, int depth, ostream& out) {
	int h = depth;
	int nodesInThisLevel = 1;

	int branchLen = 2 * ((int)pow(2.0, h) - 1) - (3 - level)*(int)pow(2.0, h - 1);  // eq of the length of branch for each node of each level
	int nodeSpaceLen = 2 + (level + 1)*(int)pow(2.0, h);  // distance between left neighbor node's right arm and right neighbor node's left arm
	int startLen = branchLen + (3 - level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

	deque<int> nodesQueue;
	nodesQueue.push_back(tree[0][0]);
	for (int r = 0; r < h - 1; r++) {
		printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
		branchLen = branchLen / 2 - 1;
		nodeSpaceLen = nodeSpaceLen / 2 + 1;
		startLen = branchLen + (3 - level) + indentSpace;
		printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
		for (int i = 0; i < nodesInThisLevel; i++) {
			nodesQueue.pop_front();

			nodesQueue.push_back(tree[r + 1][i * 2]);
			nodesQueue.push_back(tree[r + 1][i * 2 + 1]);

		}
		nodesInThisLevel *= 2;
	}
	printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
	printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

int main() {
	int depth;
	cout << "Enter a tree depth ( > 0): ";
	while (!(cin >> depth)) {
		cout << "Invalid input, enter an integer greater than zero." << endl << "Enter a tree depth ( > 0): ";
		cin.clear();
		cin.ignore('\n');
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

	printPretty(tree, 1, 0, depth, cout);
	return 0;
}
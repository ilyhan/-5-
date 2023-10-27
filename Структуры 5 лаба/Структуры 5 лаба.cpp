#include <fstream>
#include <iostream>
#include "Stack.h"
#include "Tree.h"
using namespace std;

int main()
{
	TreeNode* root = nullptr;

	ifstream file("Data3.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			int k;
			file >> k;
			addElem(root, k);
		}
	}
	file.close();
	
	Stack lf;
	searchAllLeaf(root, lf);

	resultFunc(root, lf);

}



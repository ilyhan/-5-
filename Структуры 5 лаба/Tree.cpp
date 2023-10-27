#include <fstream>
#include <iostream>
#include "Stack.h"
#include "Tree.h"
using namespace std;

bool fl = false;
int k = 0;
int cont = 0;
int mx;
int mn;
Stack steck;
int MX = 0, MN = 9999;

void initNode(TreeNode*& root, int elem) {
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}

void addElem(TreeNode*& root, int elem)
{
	//≈сли ветки не существует
	if (!root)
	{ //создадим ее и зададим в нее данные
		root = new TreeNode;
		initNode(root, elem);
		return;
	}
	else {//»наче сверим вносимое
		if (root->data > elem)
		{ //≈сли оно меньше того, что в этой ветке - добавим влево
			addElem(root->left, elem);
		}
		else
		{ //»наче в ветку справа
			addElem(root->right, elem);
		}
	}
}

void lengthTripsToLeaf(TreeNode* root) {
	if (root) {
		steck.push(root->data);
		lengthTripsToLeaf(root->left);
		lengthTripsToLeaf(root->right);
		if (!root->left && !root->right) {
			int p = steck.length();
			/*cout << root->data << " root data " << p << endl;*/
			if (mn > p) mn = p;
			if (p > mx) mx = p;
		}
		steck.pop();
	}
}

void maxminTrip(TreeNode* root, int leaf) {
	if (root) {
		if (root->data == leaf) {
			fl = true;
		}

		maxminTrip(root->left, leaf);

		if (fl && root->right) {
			mn = 9999;
			mx = 0;
			lengthTripsToLeaf(root->right);
			//cout << root->data << " mx =   " << mx << " mn =  " << mn << " cont = " << cont<<" leaf "<<leaf << endl;
			if (mn + cont < MN) MN = mn + cont;
			if (mx + cont > MX) MX = mx + cont;
		}
		else {
			maxminTrip(root->right, leaf);
		}

		if (fl) {
			cont++;
		}
	}
}


TreeNode* searchElem(TreeNode* root, int elem) {
	if (root) {
		if (root->data == elem) {
			return root;
		}
		else if (elem < root->data) {
			searchElem(root->left, elem);
		}
		else searchElem(root->right, elem);
	}
}

void searchAllLeaf(TreeNode* root, Stack& lf) {
	if (root) {
		if (!root->left && !root->right) {
			lf.push(root->data);
		}
		searchAllLeaf(root->left, lf);
		searchAllLeaf(root->right, lf);
	}
}


void resultFunc(TreeNode* root, Stack& lf) {
	while (!lf.is_empty()) {
		maxminTrip(root, lf.peek());
		cont = 0;
		fl = false;
		lf.pop();
	}

	cout << MX << " " << MN;
}
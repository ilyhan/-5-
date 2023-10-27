#pragma once
#include "Stack.h"

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

void initNode(TreeNode*& root, int elem);

void addElem(TreeNode*& root, int elem);

void lengthTripsToLeaf(TreeNode* root);

void maxminTrip(TreeNode* root, int leaf);

TreeNode* searchElem(TreeNode* root, int elem);

void searchAllLeaf(TreeNode* root, Stack& lf);

void resultFunc(TreeNode* root, Stack& lf);

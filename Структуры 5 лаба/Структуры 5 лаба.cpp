#include <iostream>
using namespace std;

template<typename datatype>

class BinaryTree {
	public:
	struct TreeNode {
		datatype data;
		BinaryTree* left;
		BinaryTree* right;
	};
	TreeNode* Root;

    BinaryTree() :(root = nullptr);

    BinaryTree(datatype elem) {
        TreeNode* Root = new TreeNode;
        initNode(Root, elem);
    }

	TreeNode* getRoot() {
		return Root;
	}

    void initNode(TreeNode*& root, datatype elem) {
        root->data = elem;
        root->left = nullptr;
        root->right = nullptr;
    }

	void addElem(TreeNode*& root, datatype elem)
	{
		//Если ветки не существует
		if (!root)
		{ //создадим ее и зададим в нее данные
			root = new TreeNode;
			initNode(root, elem)
			return;
		}
		else //Иначе сверим вносимое
			if (root->data > elem)
			{ //Если оно меньше того, что в этой ветке - добавим влево
				addElem(elem, root->left);
			}
			else
			{ //Иначе в ветку справа
				addElem(elem, root->right);
			};
	}
};







int main()
{
    cout << "Hello World!\n";
}



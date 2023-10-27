#include <fstream>
#include <iostream>

using namespace std;

class Stack {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* top;
public:

	Stack() {
		top = nullptr;
	}

	void push(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
	}

	void pop() {
		Node* temp = top;
		top = top->next;
		temp->next = 0;
		delete temp;
	}

	int peek() {
		return top->data;
	}

	int length() {
		Node* p = top;
		int count=0;
		while (p) {
			count++;
			p = p->next;
		}
		return count;
	}

	bool is_empty() {
		return top == nullptr;
	}

	void clear() {
		while (!is_empty()) {
			pop();
		}
	}

	void print() {
		Node* current = top;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

};

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

struct Node {
	int data;
	Node* next;
};

void initNode(TreeNode*& root, int elem) {
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}

void addElem(TreeNode*& root, int elem)
{
	//Если ветки не существует
	if (!root)
	{ //создадим ее и зададим в нее данные
		root = new TreeNode;
		initNode(root, elem);
		return;
	}
	else {//Иначе сверим вносимое
		if (root->data > elem)
		{ //Если оно меньше того, что в этой ветке - добавим влево
			addElem(root->left, elem);
		}
		else
		{ //Иначе в ветку справа
			addElem(root->right, elem);
		}
	}
}
bool fl = false;
int k = 0;

Node* head = nullptr;
void addToHead(int elem) {
	Node* p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

void printList() {
	Node* p = head;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}

int cont = 0;
int mx;
int mn;
Stack steck;
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


int MX = 0, MN = 9999;
void maxminTrip(TreeNode*root, int leaf) {
	if (root) {
		if(root->data == leaf){
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

	while (!lf.is_empty()) {
		maxminTrip(root, lf.peek());
		cont = 0;
		fl = false;
		lf.pop();
	}


	cout << MX << " " << MN;

}



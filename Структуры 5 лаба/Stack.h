#pragma once
class Stack {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* top;
public:
	Stack();
	void push(int value);
	void pop();
	int peek();
	int length();
	bool is_empty();
	void clear();
	void print();
};
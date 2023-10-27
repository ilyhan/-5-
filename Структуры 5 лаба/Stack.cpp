#include <fstream>
#include <iostream>
#include "Stack.h"
using namespace std;

	Stack::Stack() {
		top = nullptr;
	}

	void Stack::push(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
	}

	void Stack::pop() {
		Node* temp = top;
		top = top->next;
		temp->next = 0;
		delete temp;
	}

	int Stack::peek() {
		return top->data;
	}

	int Stack::length() {
		Node* p = top;
		int count = 0;
		while (p) {
			count++;
			p = p->next;
		}
		return count;
	}

	bool Stack::is_empty() {
		return top == nullptr;
	}

	void Stack::clear() {
		while (!is_empty()) {
			pop();
		}
	}

	void Stack::print() {
		Node* current = top;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
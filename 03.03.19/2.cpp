#include <iostream>
struct Node {
	char data;
	Node* Next;
	Node* prev = NULL;
};
class string_deque {
private:
	Node* head;
	Node* tail;
public:
	string_deque(): tail(NULL) {}
	void push(char x) {
		Node* temp = new Node;
		temp->prev = head;
		head->Next = temp;
		temp-> data = x;
		head = temp;
	}
	char pop() {
		Node* temp = head;
		while (temp->Next) {
			temp = temp->Next;
		}
		char x = temp->data;
		delete temp;
		return x;
	}
	~string_deque() {
		while ((head) = NULL) {
			Node* temp = head;
			head = head->Next;
			delete temp;
		}
	}
};

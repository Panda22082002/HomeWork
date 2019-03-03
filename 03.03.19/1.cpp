#include <iostream>
using namespace std;
struct Node {
	double data;
	Node* next;
	Node* prev = NULL;
};
class double_stack {
private:
	Node* head;
public:
	double_stack(): head(NULL) {}
	void push(double x) {
		Node* temp = new Node;
		temp->data = x;
		temp->next = head;
		head = temp;
	}
	double pop() {
		double x = head->data;
		Node*temp = head;
		head = head->next;
		delete temp;
		return x;
	}
	~double_stack() {
		while ((head) = NULL) {
			Node*temp = head;
			head = head->next;
			delete temp;
		}
	}
};

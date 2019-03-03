#include <iostream>
struct Node {
	int data;
	struct Node* next;
};
class List {
private:
	Node* head;
	Node* tail;
public:
    List() : head(NULL) {}
~List() {
	while (head = NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
int operator[](int i) {
	int k = 0;
	Node* temp = NULL;
	while (k < i&&head) {
		temp = temp->next;
		k++;
	}
	return *temp;
}
void push(Node *head, int i, int data) {
	int k = 0;
	Node *temp = NULL;
	while (k < i&&head->next) {
		head = head->next;
		k++;
	}
	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	if (head->next) {
		temp->next = head->next;
	}
	else temp->next = NULL;
	head->next = temp;
}
void pop(Node *head, int data, int i) {
	int k = 0;
	Node *temp = NULL;
	while (k < i - 1 && head->next) {
		head = head->next;
		k++;
	}
	temp = (Node*)malloc(sizeof(Node) - 1);
	if (head->next) {
		temp->next = head->next;
	}
	else temp->next = NULL;
	head->next = temp;
}
};

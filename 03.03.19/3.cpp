#include <iostream>
struct Node {
	char data;
	Node* next = NULL;
	Node* prev = NULL;
};
class char_deque {
private:
	Node* head;
	Node* tail;
public:
	char_deque(): head(NULL), tail(NULL) {}
	void push_front(char x) {
		Node* temp = new Node;
                temp ->prev = NULL;
                temp ->data = x;
        if(head != NULL){
            head ->prev = temp;
            temp ->next = head;
            head = temp;
        }
        else{
            temp ->next = NULL;
            tail = temp;
            head = tail;
        }
    }
    void push_back(char x){
        Node* temp = new Node;
        temp ->next = NULL;
        temp ->data = x;
        if(tail != NULL){
            tail ->next = temp;
            temp ->prev = tail;
            tail = temp;
        }
        else{
            temp ->prev = NULL;
            tail = temp;
            head = tail;
        }
    }
    void pop_front() {
    char x = head ->data;
    cout<<x;
    head = head ->next;
    }
    void pop_back(){
    char x = tail ->data;
    cout<<x;
    tail = tail ->prev;
    }
    ~char_deque(){
    while(head != NULL){
        Node* temp = head;
        head = head ->next;
        delete temp;
        }
    }
};

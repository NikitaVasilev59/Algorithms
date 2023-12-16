#include <iostream>
using namespace std;
struct Node {
	double data;
	struct Node* next = NULL;
};
class OneLinkedList {
public:
	struct Node* head = NULL, * tail = NULL;
public:
	void pop_front(void) {
		if (head == NULL) {
			return;
		}
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}
		struct Node* temp = head;
		head = head->next;
		delete(temp);
	}
	void pop_back(void) {
		if (tail == NULL) {
			return;
		}
		if (tail == head) {
			delete(tail);
			head = tail = NULL;
		}
		struct Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete(tail);
		tail = temp;
	}
	void push_front(double data) {
		struct Node* list = new struct Node;
		list->data = data;
		list->next = head;
		if (tail == NULL) {
			tail = list;
		}
		head = list;
	}
	void push_back(double data) {
		struct Node* list = new struct Node;
		list->data = data;
		if (head == NULL) {
			head = list;
		}
		if (tail != NULL) {
			tail->next = list;
		}
		tail = list;
	}
};
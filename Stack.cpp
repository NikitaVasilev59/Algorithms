#include <iostream>
using namespace std;
struct Stack {
	int lenght = 0;
	int capacity = 1000;
	int* list = new int[capacity];
};
bool stack_empty(struct Stack s) {
	if (s.lenght == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool stack_full(struct Stack s) {
	if (s.lenght == s.capacity) {
		return true;
	}
	else {
		return false;
	}
}
bool push(struct Stack s, int elem) {
	if (!stack_full(s)) {
		s.list[s.lenght] = elem;
		s.lenght++;
		return true;
	}
	else {
		return false;
	}
}
bool pop(struct Stack s) {
	if (!stack_empty(s)) {
		s.lenght--;
		return true;
	}
	else {
		return false;
	}
}

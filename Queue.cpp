#include <iostream>
using namespace std;
struct Queue {
	int lenght = 1000;
	int head = 0, tail = 0;
	int* list = new int[lenght];
};
int dequeue(struct Queue s) { //возвращает крайний элемент и удаляет его из массива
	if (s.head != s.tail && s.head == s.lenght - 1) {
		s.head = 0;
		return s.list[s.lenght - 1];
	}
	else if (s.head != s.tail) {
		s.head++;
		return s.list[s.head - 1];
	}
}
void enqueue(struct Queue s, int elem) {
	s.tail = elem;
	if (s.tail == s.lenght - 1) {
		s.tail = 0;
	}
	else {
		s.tail++;
	}
}


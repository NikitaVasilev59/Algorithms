#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

int partition(vector<int>* nums, int left, int right) {
	int pivot = (*nums)[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if ((*nums)[j] <= pivot) {
			i++;
			swap((*nums)[i], (*nums)[j]);
		}
	}
	swap((*nums)[i + 1], (*nums)[right]);
	return i + 1;
}
int Randomized_Partition(vector<int>* nums, int left, int right) {
	srand(time(0));
	int i = left + rand() % (right - left + 1);
	swap((*nums)[i], (*nums)[right]);
	return partition(nums, left, right);
}
void Randomized_Quick_Sort(vector<int>* nums, int left, int right) {
	if (left < right) {
		int q = Randomized_Partition(nums, left, right);
		Randomized_Quick_Sort(nums, left, q - 1);
		Randomized_Quick_Sort(nums, q + 1, right);
	}
}
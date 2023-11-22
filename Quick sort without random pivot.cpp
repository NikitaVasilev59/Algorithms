#include <iostream>
#include <vector>
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
void QuickSort(vector<int>* nums, int left, int right) {
	if (left < right) {
		int q = partition(nums, left, right);
		QuickSort(nums, left, q - 1);
		QuickSort(nums, q + 1, right);
	}
}
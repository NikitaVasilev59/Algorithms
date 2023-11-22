#include <iostream>
#include <vector>
using namespace std;
void SiftUp(vector<int>* nums, int index) {
	if (index == 0) {
		return;
	}
	int parent = (index - 1) / 2;
	if ((*nums)[index] > (*nums)[parent]) {
		swap((*nums)[index], (*nums)[parent]);
		SiftUp(nums, parent);
	}
}
void SiftDown(vector<int>* nums, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if ((left) < (*nums).size() && right >= (*nums).size() && (*nums)[index] < (*nums)[left]) {
		swap((*nums)[left], (*nums)[index]);
		SiftDown(nums, left);
	}
	else if (((left) < (*nums).size()) && right < (*nums).size() && ((*nums)[left] > (*nums)[right]) && ((*nums)[index] < (*nums)[left])) {
		swap((*nums)[left], (*nums)[index]);
		SiftDown(nums, left);
	}
	else if ((right) < (*nums).size() && (*nums)[index] < (*nums)[right]) {
		swap((*nums)[right], (*nums)[index]);
		SiftDown(nums, right);
	}
}
void heapify(vector<int>* nums) {
	for (int i = (*nums).size() - 1; i >= 0; i--) {
		SiftDown(nums, i);
	}
}
void ExtractMax(vector<int>* nums) {
	cout << (*nums)[0] << " ";
	swap((*nums)[0], (*nums)[(*nums).size() - 1]);
	(*nums).pop_back();
	SiftDown(nums, 0);
}
int main(void) {
	vector<int> nums = { 1,7,8,45,6,4,12,78,465,7,74,15,64,23 };
	heapify(&nums);
	for (int i = 0; i < 14; i++) {
		ExtractMax(&nums);
	}
	return 0;

}
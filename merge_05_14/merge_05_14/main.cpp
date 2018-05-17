#include <vector>
#include <iostream>
#include <random>

int rand_int(int low, int high) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range
	return distr(eng);
}

void merge(std::vector<int>& vals, int low, int mid, int high) {
	std::vector<int> result;
	int i=low, j=mid+1;
	while( i <= mid && j <= high) {
			if (vals[i] <= vals[j]) {
				result.push_back(vals[i]);
				i++;
			}
			else {
				result.push_back(vals[j]);
				j++;
			}
	}
	if (i <= mid)
		for (; i <= mid; i++)
			result.push_back(vals[i]);
	else if (j <= high)
		for (; j <= high; j++)
			result.push_back(vals[j]);
	for (i = low; i <= high; i++)
		vals[i] = result[i - low];
}

void merge_sort(std::vector<int>& vals, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		merge_sort(vals, low, mid);
		merge_sort(vals, mid + 1, high);
		merge(vals, low, mid, high);
	}
}

int main() {
	std::vector<int> vals;
	int low=0,high = 10,mid=(low+high)/2;
	for (int i = low; i <= high; i++)
		vals.push_back(rand_int(0,99));

	for (int i = low; i <= high; i++)
		std::cout << vals[i] << " ";

	merge_sort(vals, low, high);

	std::cout << std::endl;
	for (int i = 0; i < vals.size(); i++)
		std::cout << vals[i] << " ";
	system("pause");
}
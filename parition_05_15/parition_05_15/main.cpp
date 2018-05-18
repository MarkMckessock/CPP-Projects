#include <iostream>
#include <vector>
#include <random>

int rand_int(int low, int high) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range
	return distr(eng);
}

int partition(std::vector<int>& vals, int low, int high) {
	int pivot = vals[low],hole = low;	
	bool increment = true;
	while (high >= low) {
 		if (increment) {
			if (vals[high] <= pivot) {
				vals[hole] = vals[high];
				vals[high] = pivot;
				hole = high;
				low++;
				increment = false;
			}
			else
				high--;
		}
		else {
			if (vals[low] > pivot) {
				vals[hole] = vals[low];
				vals[low] = pivot;
				hole = low;
				increment = true;
			}
			else
				low++;
		}
	}
	return hole;
}

void quick_sort(std::vector<int>& vals, int low, int high) {
	if (low < high) {
		int pivot = partition(vals, low, high);
		quick_sort(vals, low, pivot - 1);
		quick_sort(vals, pivot + 1, high);
	}
}

int main() {
	std::vector<int> vals;
	for (int i = 0; i < 20; i++)
		vals.push_back(rand_int(-10, 50));

	for (auto num : vals)
		std::cout << num << " ";
	std::cout << std::endl;

	quick_sort(vals, 0, 19);
	for (auto num : vals)
		std::cout << num << " ";
	system("pause");
}
#include <ctime>
#include <vector>
#include <iostream>
#include <random>
#include <fstream>

int rand_int(int low, int high) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range
	return distr(eng);
}

std::vector<int> gen_vec(int n) {
	std::vector<int> vals;
	for (int i = 0; i < n; i++) {
		vals.push_back(rand_int(-100, 100));
	}
	return vals;
}

int partition(std::vector<int>& vals, int low, int high) {
	int pivot = vals[low], hole = low;
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
	std::string path = "C:/Users/Mark/Documents/times_1000.txt";
	int increment = 10000;
	std::clock_t begin,end;
	std::vector<double> times;
	std::ofstream file;
	file.open(path);
	for (int i = 0; i <= 10*increment; i+=increment) {
		std::vector<int> vals = gen_vec(i);
		std::cout << "Array Generated";
		begin = clock();
		quick_sort(vals,0,vals.size()-1);
		end = clock();
		times.push_back(double(end - begin) / CLOCKS_PER_SEC);
		std::cout << "N: " << i << "\tTime: " << times[i/increment] << std::endl;
		file << "N: " << i << "\tTime: " << times[i/increment] << std::endl;
	}
	system("pause");
	file.close();
}
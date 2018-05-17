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

void bubble_sort(std::vector<int>& vals) {
	int temp;
	for (int i = 0; i < vals.size(); i++) {
		for (int j = 0; j < vals.size() - i - 1; j++) {
			if (vals[j] > vals[j + 1]) {
				temp = vals[j];
				vals[j] = vals[j + 1];
				vals[j + 1] = temp;
			}
		}
	}
}

int main() {
	std::clock_t begin,end;
	std::vector<double> times;
	std::ofstream file;
	file.open("C:/Users/Mark/Documents/times_1000.txt");
	for (int i = 0; i <= 10*10000; i+=10000) {
		std::vector<int> vals = gen_vec(i);
		std::cout << "Array Generated";
		begin = clock();
		bubble_sort(vals);
		end = clock();
		times.push_back(double(end - begin) / CLOCKS_PER_SEC);
		std::cout << "N: " << i << "\tTime: " << times[i/10000] << std::endl;
		file << "N: " << i << "\tTime: " << times[i/10000] << std::endl;
	}
	system("pause");
	file.close();
}
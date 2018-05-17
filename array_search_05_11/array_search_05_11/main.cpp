#include <vector>
#include <iostream>

int find_key_iterative(std::vector<int> vals,int key) {
	for (int i = 0; i < vals.size(); i++)
		if (vals[i] == key)
			return i;
	return -1;
}

int find_key_recursive(std::vector<int>::iterator iter,std::vector<int>& vals, int key) {
	if (*iter == key)
		return iter - vals.begin();
	else if (iter == vals.end()-1)
		return -1;
	else
		return find_key_recursive(++iter, vals, key);
}

int find_key_bin_iterative(std::vector<int> vals,int key) {
	std::vector<int>::iterator low = vals.begin(), mid, high = vals.end() - 1;
	while (low < high) {
		//set mid
		mid = low;
		std::advance(mid, std::distance(low, high) / 2);

		if (*mid == key)
			return mid - vals.begin();
		if (*mid > key)
			high = mid;
		else
			low = mid;

	}
	return -1;
}

int find_key_bin_recursive(std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>& vals,int key) {
	if (low >= high)
		return 1;
	std::vector<int>::iterator mid = low;
	std::advance(mid, std::distance(low, high) / 2);
	if (*mid == key)
		return mid - vals.begin();
	return *mid > key ? find_key_bin_recursive(low, mid, vals, key) : find_key_bin_recursive(mid, high, vals, key);
}

int main() {
	std::vector<int> vals;
	for (int i = 0; i < 100; i++) {
		vals.push_back(i);
	}
	int key = 19;
	std::cout << "Key: " << key << " @ " << find_key_recursive(vals.begin(), vals, key) << std::endl;
	std::cout << "Key: " << key << " @ " << find_key_iterative(vals, key) << std::endl;
	std::cout << "Key: " << key << " @ " << find_key_bin_recursive(vals.begin(),vals.end()-1,vals, key) << std::endl;
	std::cout << "Key: " << key << " @ " << find_key_bin_iterative(vals,key) << std::endl;
	system("pause");
}
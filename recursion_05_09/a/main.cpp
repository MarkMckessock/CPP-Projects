#include <iostream>

int term_n_recursive(int n) {
	return n == 1 ? 3 : 4 + term_n_recursive(n - 1);
}

int term_n_iterative(int n) {
	int result = 3;
	for (int i = 0; i < n-1; i++)
		result += 4;
	return result;
}

int main() {
	std::cout << term_n_iterative(5) << " " << term_n_recursive(5) << std::endl;
	system("pause");
}
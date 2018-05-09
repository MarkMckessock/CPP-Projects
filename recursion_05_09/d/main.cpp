#include <iostream>

int term_n_recursive(int n) {
	return n == 1 ? -2 : -3 * term_n_recursive(n - 1) - 1;
}

int term_n_iterative(int n) {
	int result = -2;
	for (int i = 0; i < n - 1; i++) {
		result = (result *-3) - 1;
	}
	return result;
}

int main() {
	for (int i = 1; i < 6; i++)
		std::cout << i << ": " << term_n_recursive(i) << " " << term_n_iterative(i) << std::endl;
	system("pause");
}
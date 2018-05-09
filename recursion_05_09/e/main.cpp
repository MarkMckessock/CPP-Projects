#include <iostream>

int term_n_recursive(int n) {
	if (n == 1)
		return -1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return -3;
	else
		return -term_n_recursive(n - 1) + 2 * term_n_recursive(n - 2) + 4 * term_n_recursive(n - 3);
}

int term_n_iterative(int n) {
	if (n == 1)
		return -1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return -3;
	int prev_1 = -3, prev_2 = 2, prev_3 = -1, temp;
	for (int i = 0; i < n - 3; i++) {
		temp = prev_1;
		prev_1 = prev_1 * -1 + prev_2 * 2 + prev_3 * 4;
		prev_3 = prev_2;
		prev_2 = temp;
	}
	return prev_1;
}

int main() {
	for (int i = 1; i < 8; i++)
		std::cout << i << ": " << term_n_recursive(i) << " " << term_n_iterative(i) << std::endl;
	system("pause");
}
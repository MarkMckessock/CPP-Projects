#include <iostream>

int term_n_iterative(int n) {
	if (n == 1)
		return 3;
	else if (n == 2)
		return 5;
	int prev_1 = 5, prev_2 = 3,temp;
	for (int i = 0; i < n - 2; i++) {
		temp = prev_1;
		prev_1 += prev_2;
		prev_2 = temp; 
	}
	return prev_1;
}

int term_n_recursive(int n) {
	if (n == 1)
		return 3;
	else if (n == 2)
		return 5;
	else
		return term_n_recursive(n - 1) + term_n_recursive(n - 2);
}

int main() {
	for (int i = 1; i < 6; i++) {
		std::cout << i << ": " << term_n_iterative(i) << " " << term_n_recursive(i) << std::endl;
	}
	system("pause");
}
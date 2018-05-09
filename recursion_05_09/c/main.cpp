#include <iostream>

int term_n_recursive(int n) {
	if (n == 1 || n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else
		return term_n_recursive(n - 1) + term_n_recursive(n - 2) + term_n_recursive(n - 3);
}

int term_n_interative(int n) {
	if (n == 1 || n == 2)
		return 1;
	else if (n == 3)
		return 2;

	int prev_1 = 2, prev_2 = 1, prev_3 = 1, temp;
	for (int i = 0; i < n - 3; i++) {
		temp = prev_1; //2
		prev_1 += (prev_2 + prev_3);//4
		prev_3 = prev_2;//1
		prev_2 = temp;//2
	}
	return prev_1;
}

int main() {
	for (int i = 1; i < 10; i++) {
		std::cout << i << ": " << term_n_interative(i) << " " << term_n_recursive(i) << std::endl;
	}
	system("pause");
}
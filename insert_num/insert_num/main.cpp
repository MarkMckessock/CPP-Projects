#include <iostream>
#define MAX_NUMS 20

int insert_value(int *arr, int *n, int value) {
	if (*n >= MAX_NUMS) return 0;
	int i;
	for (i = *n; i >= 0; i--) {
		if (arr[i - 1] > value)
			arr[i] = arr[i - 1];
		else {
			arr[i] = value;
			*n++;
			return 1;
		}
	}
}

int main() {
	int values[20] = { 1,2,3,4,5,6,7,8,10,11,12,13 };
	int n = 12;
	int value = 0;

	insert_value(values, &n, value);

	for (int i = 0; i < n; i++)
		std::cout << values[i] << std::endl;
	system("pause");
}
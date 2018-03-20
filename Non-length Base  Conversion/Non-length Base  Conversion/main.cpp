#include <string>
#include <iostream>
using namespace std;

int convert_char(char input) {
	if (input >= '0' && input <= '9')
		return input - '0';
	else if (input >= 'a' && input <= 'z')
		return input - 'a' + 10;
	else if (input >= 'A' && input <= 'Z')
		return input - 'A' + 10;
}

int convert_num(int base, string number) {
	int i = 0;
	int answer = 0;
	while (number[i]) {
		answer *= base;
		answer += convert_char(number[i]);
		i++;
	}
	return answer;
}

int main() {
	string number;
	int base;
	cout << "Enter a base:";
	cin >> base;
	cout << "Enter a base " << base << " number:";
	cin >> number;

	cout << convert_num(base, number);
	system("pause");
}
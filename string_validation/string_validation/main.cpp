#include <iostream>
#include <string>
#define MIN_CHARS 5
#define MAX_CHARS 10
using namespace std;

bool valid(string str) {
	int i = 0, invalid_chars = 0;
	while (str[i]) {
		if (!(str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
			invalid_chars++;
		i++;
	}
	if (str[i - 1] == '.' && invalid_chars == 1)
		if (i >= MIN_CHARS && i <= MAX_CHARS)
			return true;
	return false;
}

int main() {
	string input;
	
	do {
		cout << "Enter a string containing only letters or numbers and ending with a period" << endl;
		cin >> input;
	} while (!valid(input));

	cout << input << endl;
	system("pause");
}
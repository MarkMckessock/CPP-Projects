#include <iostream>
#include <string>
#define MAX_VALID_CHARS 200

using namespace std;

bool valid(string str,int stretch) {
	int i = 0;
	while (str[i]) {
		if (str[i] < 'a' || str[i] > 'z' || (str[i+1] && str[i] > str[i+1]))
			return false;
		i++;
	}
	cout << i << endl;
	if (i%stretch != 0)
		return false;
	if (i > MAX_VALID_CHARS)
		return false;
	return true;
}

int main() {
	int stretch;
	string input;
	do {
		cout << "Enter a value for stretch:" << endl;
		cin >> stretch;
	} while (stretch < 1 || stretch > 10);

	do {
		cout << "Enter a string. The lenth must be a multiple of " << stretch << endl;
		cin >> input;
	} while (!valid(input,stretch));

	cout << "Valid input: " << input << endl;
	system("pause");
}
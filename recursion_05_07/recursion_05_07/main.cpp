#include <string>
#include <iostream>

int count_char_iter(std::string str, char c) {
	int i = 0,count = 0;
	while (str[i]) {
		if (str[i] == c)
			count++;
		i++;
	}
	return count;
}

int count_char_recurse(char* str, char c) {
	int i = *str == c;
	return !*str ? i : i + count_char_recurse(++str, c);
}

int main() {
	char str[81] = "abcbcbc";
	std::cout << count_char_recurse(str, 'b') << std::endl;
	system("pause");
}
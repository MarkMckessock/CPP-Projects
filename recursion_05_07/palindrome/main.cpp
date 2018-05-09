#include <string>
#include <iostream>

int is_palindrome(std::string str) {
	for (int i = 0; i < str.size()/2; i++)
		if (str[i] != str[str.size() - 1 - i])
			return 0;
	return 1;
}


int is_palindrome_recursive(std::string::iterator first, std::string::iterator last) {
	if (*first != *last)
		return 0;
	if (first == last || first == last+1) //base case
		return 1;
	return is_palindrome_recursive(++first, --last) ? 1 : 0;
}

int main() {
	std::string str = "pottop";
	std::cout << is_palindrome(str) << std::endl;
	std::cout << is_palindrome_recursive(str.begin(),--str.end()) << std::endl;
	system("pause");
}
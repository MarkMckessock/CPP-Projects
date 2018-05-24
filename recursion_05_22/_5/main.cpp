#include <string>
#include <iostream>

int check_string(std::string& str,std::string::iterator iter) {
	if (iter != str.end()) {
		if (*iter >= 'a' && *iter <= 'z')
			return 20 + check_string(str,++iter);
		else if (*iter >= 'A' && *iter <= 'Z')
			return 5 + check_string(str,++iter);
		else if (*iter == '*' || *iter == '+' || *iter == '%')
			return 50 + check_string(str,++iter);
		else
			return  1 + check_string(str,++iter);
	}
	else
		return 0;
}

int main() {
	std::string test = "hhAA%0";
	std::cout << check_string(test,test.begin()) << std::endl;
	system("pause");
}
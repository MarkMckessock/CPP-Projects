#include <iostream>
#include <string>
#include "Expression.h"
#include <stdexcept>
using namespace std;

int main() {
	Expression expression;
	expression.read();
	try {
		expression.parse();
	}
	catch (std::domain_error& e) {
		cout << e.what() << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	expression.print();
	system("pause");
}
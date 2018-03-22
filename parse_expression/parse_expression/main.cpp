#include <iostream>
#include <string>
#include "Expression.h"
#include <stdexcept>
using namespace std;

int main() {
	Expression expression;
	expression.read();
	if (!expression.validate()) {
		cout << "Invalid expression." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	expression.parse();
	expression.print();
	system("pause");
}
#include <string>
#include "Expression.h"
#include <iostream>
#include <stdexcept>
#include <memory>
#include "rand.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	std::unique_ptr<Expression> expression;
	std::string expr_str;

	while (true) {
		cout << "Enter a valid expression" << endl;
		getline(cin, expr_str);
		try {
			expression.reset(new Expression(expr_str));
			cout << "Expression: " << expression->get_string() << endl;
			system("pause");
		}
		catch (std::domain_error& e) {
			cout << e.what() << endl;
			system("pause");
		}
	}
}
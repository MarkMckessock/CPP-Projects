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
	std::string expr_str;
	std::vector<Expression> expressions;
	int expr_count;
	cout << "How many expressions do you want to create? " << endl;
	cin >> expr_count;

	for (int i = 0; i < expr_count;) {
		try{
			cout << "Enter your expression:" << endl;
			getline(cin, expr_str);
			expressions.push_back(Expression(expr_str));
			i++;
		}
		catch (std::domain_error& e) {
			cout << e.what() << endl;
			system("pause");
		}
	}
}
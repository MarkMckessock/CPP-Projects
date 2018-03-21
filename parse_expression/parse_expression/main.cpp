#include <iostream>
#include <string>
#include "Expression.h"
using namespace std;

int main() {
	Expression expression;
	expression.read();
	expression.parse();
}
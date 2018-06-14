#include <vector>
#include "Matrix.h"

int main() {
	Matrix products;
	Matrix payscale;

	products.parse("C:/Users/Mark/Documents/sales_2.txt");
	payscale.parse("C:/Users/Mark/Documents/payscale_2.txt");

	products.output();
	payscale.output();

	Matrix wages = products * payscale;

	wages.output();
	system("pause");
}


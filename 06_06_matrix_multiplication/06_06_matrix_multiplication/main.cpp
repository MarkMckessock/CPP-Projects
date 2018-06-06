#include <vector>
#include "Matrix.h"

int main() {
	Matrix products;
	Matrix payscale;

	products.parse("C:/Users/Mark/Documents/product_sale.txt");
	payscale.parse("C:/Users/Mark/Documents/payscales.txt");

	products.output();
	payscale.output();

	Matrix wages = products * payscale;

	wages.output();
	system("pause");
}


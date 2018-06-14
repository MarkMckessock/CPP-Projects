#include "Matrix.h"

Matrix::Matrix(){
}

void Matrix::parse(std::string path) {
	std::ifstream file;
	file.open(path);

	std::string str;
	std::vector<std::string> lines;
	while (std::getline(file, str)) {
		lines.push_back(str);
	}
	std::vector<std::vector<std::string>> items;
	for (auto& line : lines)
		items.push_back(split(line, '\t'));

	for (unsigned int i = 1; i < items.size(); i++) {
		for (unsigned int j = 1; j < items[0].size(); j++)
			values[items[i][0]][items[0][j]] = std::stod(items[i][j]);
	}
}

Matrix Matrix::operator*(Matrix& mtr) {
	Matrix result;
	for (auto& worker : values){
		for (auto& payscale : mtr.values[mtr.values.begin()->first]) {
			double payment = 0;
			for (auto& product : values[worker.first])
				payment += values[worker.first][product.first] * mtr.values[product.first][payscale.first];
			result.values[worker.first][payscale.first] = payment;
		}
	}
	return result;
}

void Matrix::output() {
	std::cout << "\t";
	for (auto& heading : values[values.begin()->first])
		std::cout << heading.first << "\t";
	std::cout << std::endl;

	for (auto& row : values) {
		std::cout << row.first << "\t";
		for (auto& column : values[row.first])
			std::cout << column.second << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
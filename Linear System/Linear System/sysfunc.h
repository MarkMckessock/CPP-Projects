#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <random>
#include "System.h"
#include "strip.h"
using namespace std;

inline int rand_int(int low, int high) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range
	return distr(eng);
}

inline void read_systems(vector<System> &systems) {
	bool error = false;
	string path, line;
	vector<string> lines;
	cout << "Enter the path of the file to read:" << endl;
	cin >> path;
	ifstream file(strip(path, '"'));
	while (getline(file, line)) {
		lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++) {
		if (lines[i] == "") {
			lines.erase(lines.begin() + i);
		}
	}
	for (int i = 0; i < lines.size(); i += 2) {
		try {
			systems.push_back(System(lines[i], lines[i + 1]));
		}
		catch (...) {
			cout << "Invalid system found while parsing" << endl;
			error = true;
		}
	}
	if(!error)
		cout << "All systems loaded sucessfully" << endl;
	else
		cout << "Some systems loaded successfully" << endl;
}

inline void print_systems(vector<System> &systems, bool show_solutions = false) {
	for (int i = 0; i < systems.size(); i++) {
		cout << "System " << i + 1 << endl;
		cout << systems[i].get_string() << endl << endl;
		if (show_solutions) {
			try {
				cout << "Solution: " << systems[i].solve() << endl;
			}
			catch (std::domain_error& e) {
				cout << e.what() << endl;
			}
		}
	}
	if (systems.size() == 0)
		cout << "No systems loaded." << endl;
}

inline void gen_random_system(vector<System> & systems) {
	int rand_count;
	string eqn_1, eqn_2;
	cout << "How many random systems do you wish to generate?" << endl;
	cin >> rand_count;
	for (int i = 0; i < rand_count; i++) {
		eqn_1 = to_string(rand_int(-25, 25)) + "/" + to_string(rand_int(1, 4)) + "x" + (rand_int(0, 1) ? " + " : " - ") +
			to_string(rand_int(-25, 25)) + "/" + to_string(rand_int(1, 4)) + "y = " + to_string(rand_int(-25, 25)) + "/" + to_string(rand_int(1, 4));
		eqn_2 = to_string(rand_int(-25, 25)) + "/" + to_string(rand_int(1, 4)) + "x" + (rand_int(0, 1) ? " + " : " - ") +
			to_string(rand_int(-25, 25)) + "/" + to_string(rand_int(1, 4)) + "y = " + to_string(rand_int(-25, 25)) + "/" + to_string(rand_int(1, 4));
		systems.push_back(System(eqn_1, eqn_2));
	}
	cout << rand_count << " systems generated successfully." << endl;
}

inline void get_user_system(vector<System> &systems) {
	string eqn_1, eqn_2, buff;
	//clear buffer
	getline(cin, buff);
	cout << "Enter a linear system containing two equations in the form Ax + By = C" << endl << "Enter equation 1: " << endl;
	getline(cin, eqn_1);
	system("cls");
	cout << "Enter a linear system containing two equations in the form Ax + By = C" << endl << "Enter equation 2: " << endl;
	getline(cin, eqn_2);
	systems.push_back(System(eqn_1, eqn_2));
}
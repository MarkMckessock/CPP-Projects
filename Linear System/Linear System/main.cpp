#include <string>
#include <vector>
#include <iostream>
#include "System.h"
#include "sysfunc.h"
using namespace std;
//possible errors:
//differnt variables in 2 systems.
int main() {
	vector<System> systems;
	while (true) {
		int choice = 0;
		system("cls");
		cout << "Linear Systems" << endl << string('-', 16) << endl;
		cout << "(1)\tRead from file" << endl;
		cout << "(2)\tCreate random systems" << endl;
		cout << "(3)\tEnter system" << endl;
		cout << "(4)\tChallenge Mode" << endl;
		cout << "(5)\tSolve all systems" << endl;
		cout << "(6)\tPrint all systems" << endl;
		cout << "(7)\tQuit" << endl;
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			read_systems(systems);
			break;
		case 2:
			gen_random_system(systems);
			break;
		case 3:
			get_user_system(systems);
			break;
		case 4:
			//choose random system, ask for user solution, check if correct
			break;
		case 5:
			print_systems(systems, true);
			break;
		case 6:
			print_systems(systems);
			break;
		case 7:
			//write systems to file
			exit(EXIT_SUCCESS);
		}
		system("pause");
	}
	
}
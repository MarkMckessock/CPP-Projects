#include "System.h"
#include <string>
#include <iostream>
#include "Equation.h"

System::System(){}

System::System(std::string _eqn_1, std::string _eqn_2){
	try {
		eqn_1 = Equation(_eqn_1);
		eqn_2 = Equation(_eqn_2);
	}
	catch (std::invalid_argument& e) {
		throw;
	}
}

std::string System::get_string() {
	return eqn_1.get_string() + "\n" + eqn_2.get_string();
}

std::string System::solve() {
	//solve for var 1 in first equation
	Equation solve_x;
	if (eqn_1.get_op() == '+') {
		//implement operator into fraction valueDO THIS
		solve_x = Equation(eqn_1.get_rs() / eqn_1.get_ls_const()[0], '+', (eqn_1.get_ls_const()[1] / eqn_1.get_ls_const()[0])*-1,eqn_1.get_ls_var());
	}
	else
		solve_x = Equation(eqn_1.get_rs() / eqn_1.get_ls_const()[0], '+', eqn_1.get_ls_const()[1] / eqn_1.get_ls_const()[0],eqn_1.get_ls_var());
	//std::cout << "y-coef: " << solve_x.get_ls_const()[1].get_string() << std::endl;
	//std::cout << "const: " << solve_x.get_ls_const()[0].get_string() << std::endl;
	//substitute for x and solve
	//if variables are in the same pos in both equations
	Fraction y;
	if (solve_x.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
		Fraction solve_y_coef = (eqn_2.get_ls_const()[0] * solve_x.get_ls_const()[1]) + eqn_2.get_ls_const()[1];
		//std::cout << eqn_2.get_ls_const()[0].get_string() << " * " << solve_x.get_ls_const()[1].get_string() << " + " << eqn_2.get_ls_const()[1].get_string() << std::endl;
		Fraction const_term = (eqn_2.get_ls_const()[0] * solve_x.get_ls_const()[0]);
		if (const_term.num >= 0)
			const_term = eqn_2.get_rs() - const_term;
		else
			const_term = eqn_2.get_rs() + const_term;
		solve_y_coef.simplify();
		const_term.simplify();
		y = const_term / solve_y_coef;
		//y.simplify();
	}
	else {

	}
	//solve for x in either eq'n
	Fraction x;
	//OVERFLOW ON DIVISION OF Y BY CONST.
	if (eqn_1.get_op() == '-')
		x = (eqn_1.get_rs() / eqn_1.get_ls_const()[0]) + (y / eqn_1.get_ls_const()[0]);
	else
		x = (eqn_1.get_rs() / eqn_1.get_ls_const()[0]) - (y / eqn_1.get_ls_const()[0]);
	//std::cout << (eqn_1.get_rs() / eqn_1.get_ls_const()[0]).get_string() << std::endl;
	//std::cout << eqn_1.get_ls_var()[0] << std::endl;
	return eqn_1.get_ls_var()[0] + " = " + y.get_string() + " " + eqn_1.get_ls_var()[1] + " = " + x.get_string();
}
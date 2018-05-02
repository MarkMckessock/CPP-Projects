#include "System.h"
#include <string>
#include <iostream>
#include "Equation.h"
#include "boost\rational.hpp"
#include "boost\exception\all.hpp"
#include "rational_to_string.h"

System::System(){}

System::System(std::string _eqn_1, std::string _eqn_2){
	try {
		eqn_1 = Equation(_eqn_1);
		eqn_2 = Equation(_eqn_2);
		if (eqn_1.get_ls_const()[0] == eqn_2.get_ls_const()[0] &&
			eqn_1.get_ls_const()[1] == eqn_1.get_ls_const()[1] &&
			eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0] &&
			eqn_1.get_rs() != eqn_2.get_rs())
			throw(std::domain_error("Unsolvable system"));
	}
	catch (std::invalid_argument& e) {
		throw;
	}
	catch (std::domain_error) {
		throw;
	}
}

std::string System::get_string() {
	return eqn_1.get_string() + "\n" + eqn_2.get_string();
}

boost::rational<int> solve_var_2(Equation eqn_1, Equation eqn_2) {
	boost::rational<int> rs, var_2, var_2_coef;
	if (eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
		if(eqn_1.get_ls_const()[0] == 0)
			return eqn_1.get_rs() / (eqn_1.get_op() == '-' ? -eqn_1.get_ls_const()[1] : eqn_1.get_ls_const()[1]);
		if(eqn_2.get_ls_const()[0] == 0)
			return eqn_2.get_rs() / (eqn_2.get_op() == '-' ? -eqn_2.get_ls_const()[1] : eqn_2.get_ls_const()[1]);
		boost::rational<int> mult = eqn_1.get_ls_const()[0] / -eqn_2.get_ls_const()[0];
		var_2_coef = (eqn_1.get_op() == '-' ? -eqn_1.get_ls_const()[1] : eqn_1.get_ls_const()[1]) + (eqn_2.get_op() == '-' ? -mult * eqn_2.get_ls_const()[1] : mult * eqn_2.get_ls_const()[1]);
		rs = eqn_1.get_rs() + mult * eqn_2.get_rs();
		return rs / var_2_coef;
	}
	else {
		if (eqn_1.get_ls_const()[0] == 0)
			return eqn_1.get_rs() / (eqn_1.get_op() == '-' ? -eqn_1.get_ls_const()[1] : eqn_1.get_ls_const()[1]);
		if (eqn_2.get_ls_const()[1] == 0)
			return eqn_2.get_rs() / eqn_2.get_ls_const()[1];
		boost::rational<int> mult = eqn_1.get_ls_const()[0] / -(eqn_2.get_op() == '-' ? -eqn_2.get_ls_const()[1] : eqn_2.get_ls_const()[1]);
		var_2_coef = eqn_2.get_ls_const()[0]*mult + (eqn_1.get_op() == '-' ? -eqn_1.get_ls_const()[1] : eqn_1.get_ls_const()[1]);
		rs = eqn_1.get_rs() + mult * eqn_2.get_rs();
		return rs / var_2_coef;
	}
}

boost::rational<int> solve_var_1(Equation eqn_1, Equation eqn_2) {
	if (eqn_1.get_ls_const()[1] == 0)
		return eqn_1.get_rs() / eqn_1.get_ls_const()[0];
	if (eqn_2.get_ls_const()[1] == 0)
		return eqn_2.get_rs() / eqn_2.get_ls_const()[0];
	boost::rational<int> rs, var_1, var_1_coef, mult;
	if (eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
		if (eqn_1.get_op() == '-') {
			if (eqn_2.get_op() == '-')
				mult = -eqn_1.get_ls_const()[1] / eqn_2.get_ls_const()[1];
			else {
				mult = eqn_1.get_ls_const()[1] / eqn_2.get_ls_const()[1];
			}
		}
		else {
			if(eqn_2.get_op() == '-')
				mult = eqn_1.get_ls_const()[1] / eqn_2.get_ls_const()[1];
			else
				mult = eqn_1.get_ls_const()[1] / -eqn_2.get_ls_const()[1];
		}
		var_1_coef = eqn_1.get_ls_const()[0] + mult * eqn_2.get_ls_const()[0];
		rs = eqn_1.get_rs() + mult * eqn_2.get_rs();
		return rs / var_1_coef;
	}
	else {	
		if (eqn_1.get_ls_const()[1] == 0)
			return eqn_1.get_rs() / eqn_1.get_ls_const()[0];
		if (eqn_2.get_ls_const()[0] == 0)
			return eqn_2.get_rs() / (eqn_2.get_op() == '-' ? -eqn_2.get_ls_const()[1] : eqn_2.get_ls_const()[1]);
		boost::rational<int> mult = (eqn_1.get_op()== '-' ? -eqn_1.get_ls_const()[1] : eqn_1.get_ls_const()[1]) / -eqn_2.get_ls_const()[0];
		var_1_coef = eqn_1.get_ls_const()[0] + (eqn_2.get_op() == '-' ? -mult * eqn_2.get_ls_const()[1] : mult * eqn_2.get_ls_const()[1]);
		rs = eqn_1.get_rs() + mult * eqn_2.get_rs();
		return rs / var_1_coef;
	}
}

std::string System::solve(){
	boost::rational<int> var_1,var_2;
	//solve by elimination
	var_2 = solve_var_2(eqn_1, eqn_2);
	var_1 = solve_var_1(eqn_1, eqn_2);
	std::string result = std::string(1,eqn_1.get_ls_var()[0]) + " = " + rational_to_string(var_1) + " " + eqn_1.get_ls_var()[1] + " = " + rational_to_string(var_2);
	return result;
}
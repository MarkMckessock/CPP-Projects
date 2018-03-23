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

std::string System::solve() {
	boost::rational<int> var_1,var_1_const,var_1_coef,var_2,var_2_coef,var_2_const;
	////coef of var_1 is 0
	//if (eqn_1.get_ls_const()[0].numerator() == 0)
	//	var_2 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
	////coed of var_2 is 0
	//if (eqn_1.get_ls_const()[1].numerator() == 0)
	//	var_1 = eqn_1.get_rs() / eqn_1.get_ls_const()[0];
	//if (eqn_1.get_ls_var[0] == eqn_2.get_ls_var[0]) {
	//	if (eqn_2.get_ls_const()[0].numerator() == 0)

	//}
	if (eqn_1.get_ls_const()[0] == 0 && eqn_1.get_ls_const()[1] != 0)
		var_2 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
	else if (eqn_1.get_ls_const()[0] != 0 && eqn_1.get_ls_const()[1] == 0)
		var_1 = eqn_1.get_rs() / eqn_1.get_ls_const()[0];
	//CHECK IF 1 VAR HAS COEF OF 0 FIRST AND RETURN const/the coef of the other var
	try {
		var_1_const = eqn_1.get_rs() / eqn_1.get_ls_const()[0];
		var_1_coef = eqn_1.get_op() == '-' ? eqn_1.get_ls_const()[1] / eqn_1.get_ls_const()[0] : (eqn_1.get_ls_const()[1] * -1) / eqn_1.get_ls_const()[0];
		if (eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
			var_2_coef = eqn_2.get_op() == '+' ? eqn_2.get_ls_const()[0] * var_1_coef + eqn_2.get_ls_const()[1] : eqn_2.get_ls_const()[0] * var_1_coef - eqn_2.get_ls_const()[1];
			var_2_const = eqn_2.get_ls_const()[0] * var_1_const < 0 ? eqn_2.get_rs() + eqn_2.get_ls_const()[0] * var_1_const : eqn_2.get_rs() - eqn_2.get_ls_const()[0] * var_1_const;
			var_2 = (var_2_const / var_2_coef);
			//plug var 2 in and solve for var_1
			var_1 = var_1_const + var_1_coef * var_2;
		}
	}
	catch (boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::bad_rational>>) {
		std::cout << "Invalid equation found" << std::endl;
	}
	std::string result = std::string(1,eqn_1.get_ls_var()[0]) + " = " + rational_to_string(var_1) + " " + eqn_1.get_ls_var()[1] + " = " + rational_to_string(var_2);
	return result;
}
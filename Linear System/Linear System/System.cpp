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

boost::rational<int> System::solve_y() {
	boost::rational<int> var_1, var_1_coef, var_1_const, var_2_coef, var_2_const;
	//std::cout << eqn_1.get_rs() << "/" << eqn_1.get_ls_const()[0] << std::endl;
	//std::cout << eqn_1.get_rs() / eqn_1.get_ls_const()[0] << std::endl;
	//std::cout << eqn_1.get_ls_const()[1] << " * -1 / " << eqn_1.get_ls_const()[0] << std::endl;
	//std::cout << (eqn_1.get_ls_const()[1] * -1) / eqn_1.get_ls_const()[0] << std::endl;
	var_1_const = eqn_1.get_rs() / eqn_1.get_ls_const()[0];
	var_1_coef = eqn_1.get_op() == '-' ? eqn_1.get_ls_const()[1] / eqn_1.get_ls_const()[0] : (eqn_1.get_ls_const()[1] * -1) / eqn_1.get_ls_const()[0];
	//std::cout << "var /" << var_1_const << "/" << var_1_coef << std::endl;
	if (eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
		var_2_coef = eqn_2.get_op() == '+' ? eqn_2.get_ls_const()[0] * var_1_coef + eqn_2.get_ls_const()[1] : eqn_2.get_ls_const()[0] * var_1_coef - eqn_2.get_ls_const()[1];
		/*std::cout << "operation " << eqn_2.get_ls_const()[0] << " * " << var_1_coef << " + " << eqn_2.get_ls_const()[1] << std::endl;
		std::cout << "var_2_coef" << var_2_coef << std::endl;*/
		var_2_const = eqn_2.get_ls_const()[0] * var_1_const < 0 ? eqn_2.get_rs() + eqn_2.get_ls_const()[0] * var_1_const : eqn_2.get_rs() - eqn_2.get_ls_const()[0] * var_1_const;
		//std::cout << "operation" << eqn_2.get_rs() << " - " << eqn_2.get_ls_const()[0] << " * " << var_1_const << std::endl;
		//std::cout << "var_2_const" << var_2_const << std::endl;
		if (var_2_coef == 0 && var_2_const == 0)
			throw(std::domain_error("Lines are parrallel"));
		return (var_2_const / var_2_coef);
	}
	else {
		var_2_coef =  eqn_2.get_ls_const()[1] * var_1_coef + eqn_2.get_ls_const()[0];
		var_2_const = eqn_2.get_rs() - eqn_2.get_ls_const()[1] * var_1_const;
		if (var_2_coef == 0 && var_2_const == 0)
			throw(std::domain_error("Lines are parrallel"));
		return (var_2_const / var_2_coef);
	}
}

boost::rational<int> System::solve_x(boost::rational<int> var_1_const, boost::rational<int> var_1_coef, boost::rational<int> &var_2) {
	return var_1_const + var_1_coef * var_2;
}

std::string System::solve(){
	boost::rational<int> var_1,var_1_const,var_1_coef,var_2,var_2_coef,var_2_const;
	if (eqn_1.get_ls_const()[0] == 0 && eqn_1.get_ls_const()[1] && eqn_2.get_ls_const()[0] && eqn_2.get_ls_const()[1]) {
		var_2 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
		//(0x+By=C)(Ax+By=C)
		if(eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0])
			var_1 = solve_x(eqn_2.get_rs() / eqn_2.get_ls_const()[0], eqn_2.get_op() == '-' ? eqn_2.get_ls_const()[1] / eqn_2.get_ls_const()[0] : (eqn_2.get_ls_const()[1] * -1) / eqn_2.get_ls_const()[0],var_2);
		//(0x+By=C)(By+Ax=C)
		else
			var_1 = solve_x(eqn_2.get_op() == '-' ? eqn_2.get_rs()*-1 / eqn_2.get_ls_const()[0]: eqn_2.get_rs() / eqn_2.get_ls_const()[0], eqn_2.get_op() == '-' ? eqn_2.get_ls_const()[0] / eqn_2.get_ls_const()[1] : (eqn_2.get_ls_const()[1] * -1) / eqn_2.get_ls_const()[0], var_2);
	}
	//(Ax+0y=C)(Ax+By=C)
	if (eqn_1.get_ls_const()[0] && eqn_1.get_ls_const()[1] == 0 && eqn_2.get_ls_const()[0] && eqn_2.get_ls_const()[1]) {
		var_2 = solve_y();
		var_1 = eqn_1.get_rs() / eqn_1.get_ls_const()[0];
	}
	if (eqn_2.get_ls_const()[0] && eqn_2.get_ls_const()[1] == 0 && eqn_1.get_ls_const()[0] && eqn_1.get_ls_const()[1]) {
		//(Ax+By=C)(Ax+0y=C)
		if (eqn_2.get_ls_var()[0] == eqn_1.get_ls_var()[0]) {
			var_1 = eqn_2.get_rs() / eqn_2.get_ls_const()[0];
			var_2 = solve_y();
		}
		//(Ax+By=C)(Bx+0y=C)
		else {
			var_2 = eqn_2.get_rs() / eqn_2.get_ls_const()[0];
			var_1 = solve_x(eqn_1.get_op() == '-' ? eqn_1.get_rs()*-1 / eqn_1.get_ls_const()[0] : eqn_1.get_rs() / eqn_1.get_ls_const()[0], eqn_1.get_op() == '-' ? eqn_1.get_ls_const()[0] / eqn_1.get_ls_const()[1] : (eqn_1.get_ls_const()[1] * -1) / eqn_1.get_ls_const()[0], var_2);
		}
	}
	if (eqn_2.get_ls_const()[1] && eqn_2.get_ls_const()[0] == 0 && eqn_1.get_ls_const()[0] && eqn_1.get_ls_const()[1]) {
		//(Ax+By=C)(0x+By=C)
		if (eqn_2.get_ls_var()[0] == eqn_1.get_ls_var()[0]) {
			var_1 = solve_y();
			var_2 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
		}
		//(Ax+By=C)(0y+Bx=C)
		else {
			var_1 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
			var_2 = solve_x(eqn_1.get_op() == '-' ? eqn_1.get_rs()*-1 / eqn_1.get_ls_const()[0] : eqn_1.get_rs() / eqn_1.get_ls_const()[0], eqn_1.get_op() == '-' ? eqn_1.get_ls_const()[0] / eqn_1.get_ls_const()[1] : (eqn_1.get_ls_const()[1] * -1) / eqn_1.get_ls_const()[0], var_2);
		}
	}
	//(0x+By=C)(Ax+0y=X)
	if (eqn_1.get_ls_const()[0] == 0 && eqn_1.get_ls_const()[1] && eqn_2.get_ls_const()[0] && eqn_2.get_ls_const()[1] == 0 && eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
		var_2 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
		var_1 = eqn_2.get_rs() / eqn_2.get_ls_const()[0];
	}
	// (0x+By=C)(0y+Ax=C)
	if (eqn_1.get_ls_const()[0] == 0 && eqn_1.get_ls_const()[1] && eqn_2.get_ls_const()[1] && eqn_2.get_ls_const()[0] == 0 && eqn_1.get_ls_var()[0] != eqn_2.get_ls_var()[0]) {
		var_2 = eqn_1.get_rs() / eqn_1.get_ls_const()[1];
		var_1 = eqn_2.get_rs() / eqn_2.get_ls_const()[1];
	}
	//(Ax+0y=C)(0x+By=C)
	if (eqn_1.get_ls_const()[1] == 0 && eqn_1.get_ls_const()[0] && eqn_2.get_ls_const()[1] && eqn_2.get_ls_const()[0] == 0 && eqn_1.get_ls_var()[0] == eqn_2.get_ls_var()[0]) {
		var_2 = eqn_2.get_rs() / eqn_2.get_ls_const()[1];
		var_1 = eqn_1.get_rs() / eqn_1.get_ls_const()[0];
	}
	//(Ax+By=C)(Ax+By=C)
	if (eqn_1.get_ls_const()[0] && eqn_1.get_ls_const()[1] && eqn_2.get_ls_const()[0] && eqn_2.get_ls_const()[1]) {
		try {
			var_2 = solve_y();
			var_1 = solve_x(eqn_1.get_op() == '-' ? eqn_1.get_rs()*-1 / eqn_1.get_ls_const()[0] : eqn_1.get_rs() / eqn_1.get_ls_const()[0], eqn_1.get_op() == '-' ? eqn_1.get_ls_const()[0] / eqn_1.get_ls_const()[1] : (eqn_1.get_ls_const()[1] * -1) / eqn_1.get_ls_const()[0], var_2);
		}
		catch (boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::bad_rational>>& e) {
			std::cout << "Invalid equation found - " << e.what() << std::endl;
		}
		catch (std::domain_error) {
			throw;
		}
	}
	std::string result = std::string(1,eqn_1.get_ls_var()[0]) + " = " + rational_to_string(var_1) + " " + eqn_1.get_ls_var()[1] + " = " + rational_to_string(var_2);
	return result;
}
#ifndef IS_OPERATOR
#define IS_OPERATOR

inline bool is_operator(char _char) {
	if (_char == '*' || _char == '+' || _char == '-' || _char == '/')
		return true;
	else
		return false;
}

#endif
#ifndef TOKEN_CODE_H_
#define TOKEN_CODE_H_
#include <string>

enum TokenCode {
	identifier = 1,
	int_litteral = 2,
	assign_op = 3,
	add_op = 4,
	sub_op = 5,
	mul_op = 6,
	div_op = 7,
	left_parenthesis = 8,
	right_parenthesis = 9,
	semi_colon = 10
};

#endif // ! TOKEN_CODE_H_
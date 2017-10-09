#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>
#include "token_code.h"
#include <iostream>

class Token
{
private:
	std::string m_Lexeme;
	TokenCode m_Code;
public:
	Token(std::string lexeme, TokenCode code) : m_Lexeme(lexeme), m_Code(code) {};

	void Print() { std::cout << "Lexeme is " << m_Lexeme << " with code " << m_Code; };
};

#endif // ! TOKEN_H_
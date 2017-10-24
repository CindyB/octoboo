#include "lexical_analyzer.h"
#include "token_code.h"

Token* LexicalAnalyzer::GetNextToken()
{
	if (!m_Stream->is_open()) return nullptr;

	char c = m_Stream->get();

	if (isalpha(c))//q0 -> q1
	{
		std::string identifier = std::string();
		do
		{
			identifier.append(1, c);
			c = m_Stream->get();
		} while (!isspace(c) && c != ';' && !m_Stream->eof());

		return new Token(identifier, TokenCode::identifier);
	}
	else if(isdigit(c))//q0 -> q2
	{
		do
		{
			c = m_Stream->get();
		} while (!isspace(c));
	}
	else//q0->qsymbol
	{
		if (c == '+') return new Token(std::string(c, 1), TokenCode::add_op);
		if (c == '-') return new Token(std::string(c, 1), TokenCode::sub_op);
		if (c == '*') return new Token(std::string(c, 1), TokenCode::mul_op);
		if (c == '\\') return new Token(std::string(c, 1), TokenCode::div_op);
		if (c == '=') return new Token(std::string(c, 1), TokenCode::assign_op);
		if (c == ';') return new Token(std::string(c, 1), TokenCode::semi_colon);
		if (c == '(') return new Token(std::string(c, 1), TokenCode::left_parenthesis);
		if (c == ')') return new Token(std::string(c, 1), TokenCode::right_parenthesis);
		return nullptr;
	}
}
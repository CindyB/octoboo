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
		std::string value = std::string();
		do
		{
			value.append(1, c);
			c = m_Stream->get();
		} while (!isspace(c) && c != ';' && !m_Stream->eof());
		return new Token(value, TokenCode::int_litteral);
	}
	else//q0->qsymbol
	{
		if (c == '+') return new Token(std::string(1, c), TokenCode::add_op);
		if (c == '-') return new Token(std::string(1, c), TokenCode::sub_op);
		if (c == '*') return new Token(std::string(1, c), TokenCode::mul_op);
		if (c == '\\') return new Token(std::string(1, c), TokenCode::div_op);
		if (c == '=') return new Token(std::string(1, c), TokenCode::assign_op);
		if (c == ';') return new Token(std::string(1, c), TokenCode::semi_colon);
		if (c == '(') return new Token(std::string(1, c), TokenCode::left_parenthesis);
		if (c == ')') return new Token(std::string(1, c), TokenCode::right_parenthesis);
		return nullptr;
	}
}
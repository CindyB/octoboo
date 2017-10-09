#ifndef LEXICAL_ANALYZER_H_
#define LEXICAL_ANALYZER_H_
#include <string>
#include "token.h"

class LexicalAnalyzer
{
private:
	std::string m_filepath;
public:
	LexicalAnalyzer(std::string filepath) : m_filepath(filepath) {};

	Token* GetNextToken();
};

#endif // ! LEXICAL_ANALYZER_H_
#ifndef LEXICAL_ANALYZER_H_
#define LEXICAL_ANALYZER_H_
#include <string>
#include <fstream>
#include <iostream>
#include "token.h"

class LexicalAnalyzer
{
private:
	std::string m_filepath;
	std::ifstream* m_Stream;
public:
	LexicalAnalyzer(std::string filepath){
		m_filepath = filepath;
		m_Stream = new std::ifstream(filepath);
	};

	Token* GetNextToken();
};

#endif // ! LEXICAL_ANALYZER_H_
#ifndef SYNTAX_ANALYZER_H_
#define SYNTAX_ANALYZER_H_
#include <string>
#include "lexical_analyzer.h"

class SyntaxAnalyzer
{
private:
	LexicalAnalyzer* lexicalAnalyzer;
public:
	SyntaxAnalyzer(std::string filepath)
	{
		lexicalAnalyzer = new LexicalAnalyzer(filepath);
	};

	~SyntaxAnalyzer()
	{
		delete lexicalAnalyzer;
	}
};

#endif // ! SYNTAX_ANALYZER_H_
#ifndef SYNTAX_ANALYZER_H_
#define SYNTAX_ANALYZER_H_
#include <string>
#include "lexical_analyzer.h"

class SyntaxAnalyzer
{
private:
	LexicalAnalyzer* m_LexicalAnalyzer;
public:
	SyntaxAnalyzer(std::string filepath)
	{
		m_LexicalAnalyzer = new LexicalAnalyzer(filepath);
	};

	~SyntaxAnalyzer()
	{
		delete m_LexicalAnalyzer;
	}

	void Analyze();
};

#endif // ! SYNTAX_ANALYZER_H_
#ifndef COMPILER_H_
#define COMPILER_H_
#include <string>
#include "syntax_analyzer.h"

class Compiler
{
private:
	SyntaxAnalyzer* syntaxAnalyzer;
public:
	Compiler(std::string filepath)
	{
		syntaxAnalyzer = new SyntaxAnalyzer(filepath);
	}

	~Compiler()
	{
		delete syntaxAnalyzer;
	}

	void Compile();
};

#endif // ! COMPILER_H_
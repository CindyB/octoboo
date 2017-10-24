#include "syntax_analyzer.h"
#include <iostream>

void SyntaxAnalyzer::Analyze()
{
	Token* token = nullptr;
	while ((token = m_LexicalAnalyzer->GetNextToken()) != nullptr)
	{
		std::cout << "Lexeme is" << token->Lexeme() << " with code " << token->Code();
	}
}
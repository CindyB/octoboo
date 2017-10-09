#ifndef LEXICAL_ANALYZER_H_
#define LEXICAL_ANALYZER_H_
#include <string>

class LexicalAnalyzer
{
private:
	std::string m_filepath;
public:
	LexicalAnalyzer(std::string filepath) : m_filepath(filepath) {};
};

#endif // ! LEXICAL_ANALYZER_H_
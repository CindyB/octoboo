#ifndef COMPILER_H_
#define COMPILER_H_
#include <string>

class Compiler
{
private :
	std::string m_Filepath;
public :
	Compiler(std::string filepath) :m_Filepath(filepath) {};
	void Compile();
};

#endif // ! COMPILER_H_
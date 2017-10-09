#include "stdafx.h"
#include "CppUnitTest.h"
#include "Compiler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(CompilerTest)
	{
	public:
		
		TEST_METHOD(FirstPhase)
		{
			Compiler* compiler = new Compiler("t");

			compiler->Compile();
		}

	};
}
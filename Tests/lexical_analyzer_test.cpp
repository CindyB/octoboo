#include "stdafx.h"
#include "CppUnitTest.h"
#include "lexical_analyzer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(LexicalAnalyzerTest)
	{
	public:

		TEST_METHOD(GivenFileWithIdentifier_WhenGetNextToken_ThenTokenOfIdentifierTypeIsReturned)
		{
			Token expected("result", TokenCode::identifier);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/identifier.oc");

			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

	};
}
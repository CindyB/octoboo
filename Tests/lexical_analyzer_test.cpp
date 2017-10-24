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

		TEST_METHOD(GivenNotExistingFile_WhenGetNextToken_ThenNullPtrIsReturnedAsToken)
		{
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/notexisting.oc");

			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(actual == nullptr);
		}

		TEST_METHOD(GivenEmptyFile_WhenGetNextToken_ThenNullPtrIsReturnedAsToken)
		{
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/empty.oc");

			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(actual == nullptr);
		}
	};
}
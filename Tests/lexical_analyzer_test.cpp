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

		TEST_METHOD(GivenFileWithAddOperator_WhenGetNextToken_ThenTokenOfAddOperatorTypeIsReturned)
		{
			Token expected("+", TokenCode::add_op);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithSubOperator_WhenGetNextToken_ThenTokenOfSubOperatorTypeIsReturned)
		{
			Token expected("-", TokenCode::sub_op);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithMulOperator_WhenGetNextToken_ThenTokenOfMulOperatorTypeIsReturned)
		{
			Token expected("*", TokenCode::mul_op);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			for(int i = 0;i<2;i++)
				analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithDicOperator_WhenGetNextToken_ThenTokenOfDivOperatorTypeIsReturned)
		{
			Token expected("\\", TokenCode::div_op);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			for (int i = 0; i<3; i++)
				analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithAssignOperator_WhenGetNextToken_ThenTokenOfAssignOperatorTypeIsReturned)
		{
			Token expected("=", TokenCode::assign_op);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			for (int i = 0; i<4; i++)
				analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithSemicolon_WhenGetNextToken_ThenTokenOfSemicolonTypeIsReturned)
		{
			Token expected(";", TokenCode::semi_colon);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			for (int i = 0; i<5; i++)
				analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithLeftParenthesis_WhenGetNextToken_ThenTokenOfLeftParenthesisTypeIsReturned)
		{
			Token expected("(", TokenCode::left_parenthesis);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			for (int i = 0; i<6; i++)
				analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithRightParenthesis_WhenGetNextToken_ThenTokenOfRightParenthesisTypeIsReturned)
		{
			Token expected(")", TokenCode::right_parenthesis);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/symbols.oc");

			for (int i = 0; i<7; i++)
				analyzer->GetNextToken();
			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}

		TEST_METHOD(GivenFileWithIntLiteral_WhenGetNextToken_ThenTokenOfIntLiteralTypeIsReturned)
		{
			Token expected("1345", TokenCode::int_litteral);
			LexicalAnalyzer* analyzer = new LexicalAnalyzer("./../Tests/TestFiles/int.oc");

			Token* actual = analyzer->GetNextToken();

			Assert::IsTrue(expected.Code() == actual->Code());
			Assert::IsTrue(expected.Lexeme().compare(actual->Lexeme()) == 0);
		}
	};
}
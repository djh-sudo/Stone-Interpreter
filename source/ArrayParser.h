#pragma once
#include "FunctionParser.h"
#include "ArrayLiteral.h"
#include "ClassParser.h"
// �������
class ArrayParser :public ClassParser {
protected:
	// Ԫ��ָ��
	ListRule<ArrayLiteral>* element;

public:
	ArrayParser(Lexer& l);
};
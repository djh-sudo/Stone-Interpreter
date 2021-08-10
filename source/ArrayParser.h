#pragma once
#include "FunctionParser.h"
#include "ArrayLiteral.h"
#include "ClassParser.h"
// 数组分析
class ArrayParser :public ClassParser {
protected:
	// 元素指针
	ListRule<ArrayLiteral>* element;

public:
	ArrayParser(Lexer& l);
};
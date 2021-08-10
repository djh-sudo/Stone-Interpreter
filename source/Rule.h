#pragma once
#include "ASTree.h"
#include "Lexer.h"

/*
	Rule为一个抽象类
	parser 和 match由具体子类实现

*/
/*
	Rule [Base]
	-> ListRule
	-> OrRule
*/

// 规则解析
class Rule {
public:
	Rule() = default;
	virtual ~Rule() = default;
	virtual ASTree::cptr parser(Lexer& l) = 0;
	virtual bool match(Lexer& l) = 0;
};